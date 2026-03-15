import { useState, useEffect, useCallback } from "react";

// 1. Simple cache outside the hook (persists during session)
const cache = new Map();

function useFetch(url, options = {}) {
  const [data, setData] = useState(null);
  const [isLoading, setIsLoading] = useState(false);
  const [error, setError] = useState(null);

  // Defaults for retries and method
  const { method = "GET", retries = 3 } = options;

  const fetchData = useCallback(
    async (manualBody = null) => {
      // 2. Check Cache (Only for GET)
      if (method === "GET" && cache.has(url)) {
        setData(cache.get(url));
        return;
      }

      const controller = new AbortController();
      setIsLoading(true);
      setError(null);

      // 3. Recursive Retry Logic
      const attemptFetch = async (attempt) => {
        try {
          const response = await fetch(url, {
            ...options,
            signal: controller.signal,
            body: manualBody ? JSON.stringify(manualBody) : options.body,
          });

          if (!response.ok) throw new Error(`HTTP ${response.status}`);

          const result = await response.json();

          // 4. Update Cache on Success
          if (method === "GET") cache.set(url, result);

          setData(result);
        } catch (err) {
          if (err.name === "AbortError") return;

          if (attempt < retries) {
            // Exponential backoff: wait 1s, 2s, 4s...
            await new Promise((resolve) =>
              setTimeout(resolve, Math.pow(2, attempt) * 1000),
            );
            return attemptFetch(attempt + 1);
          }
          setError(err.message);
        } finally {
          setIsLoading(false);
        }
      };

      attemptFetch(0);
      return () => controller.abort();
    },
    [method, url, options, retries],
  );

  useEffect(() => {
    if (method === "GET") {
      const cleanup = fetchData();
      return () => cleanup && cleanup();
    }
  }, [fetchData, method]);

  return { data, isLoading, error, trigger: fetchData };
}

export default useFetch;
