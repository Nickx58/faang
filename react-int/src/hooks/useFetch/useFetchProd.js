import { useEffect, useCallback, useRef, useReducer } from "react";

// Global cache and in-flight request tracker
const cache = new Map();
const inFlightRequests = new Map();

const initialState = {
  data: null,
  isLoading: false,
  error: null,
  status: "idle", // idle | loading | success | error
};

function fetchReducer(state, action) {
  switch (action.type) {
    case "LOADING":
      return { ...initialState, isLoading: true, status: "loading" };
    case "SUCCESS":
      return { ...initialState, data: action.payload, status: "success" };
    case "ERROR":
      return { ...initialState, error: action.payload, status: "error" };
    default:
      return state;
  }
}

function useFetch(url, options = {}) {
  const {
    method = "GET",
    body = null,
    retries = 3,
    cacheTime = 300000, // 5 minutes default
    manual = false,
  } = options;

  const [state, dispatch] = useReducer(fetchReducer, initialState);
  const cancelRequest = useRef(false);

  const executeFetch = useCallback(
    async (overrideBody = null) => {
      // 1. Check Cache (GET only)
      if (method === "GET" && cache.has(url)) {
        const cached = cache.get(url);
        if (Date.now() - cached.timestamp < cacheTime) {
          dispatch({ type: "SUCCESS", payload: cached.data });
          return cached.data;
        }
        cache.delete(url); // Expired
      }

      // 2. Request De-duplication (Prevent multiple identical GETs)
      if (method === "GET" && inFlightRequests.has(url)) {
        return inFlightRequests.get(url).then((data) => {
          dispatch({ type: "SUCCESS", payload: data });
          return data;
        });
      }

      dispatch({ type: "LOADING" });
      const controller = new AbortController();

      const fetchPromise = (async () => {
        let currentAttempt = 0;

        const attemptFetch = async () => {
          try {
            const response = await fetch(url, {
              method,
              signal: controller.signal,
              headers: {
                "Content-Type": "application/json",
                ...options.headers,
              },
              body:
                overrideBody ||
                (method !== "GET" ? JSON.stringify(body) : null),
            });

            if (!response.ok) {
              const errorData = await response.json().catch(() => ({}));
              throw new Error(errorData.message || `HTTP ${response.status}`);
            }

            const result = await response.json();

            if (cancelRequest.current) return;

            // 3. Cache Success & Invalidate on Mutations
            if (method === "GET") {
              cache.set(url, { data: result, timestamp: Date.now() });
            } else {
              // If POST/PUT/DELETE, clear cache for this URL as data is likely stale
              cache.delete(url);
            }

            dispatch({ type: "SUCCESS", payload: result });
            return result;
          } catch (err) {
            if (err.name === "AbortError") return;

            if (currentAttempt < retries) {
              currentAttempt++;
              const backoff = Math.pow(2, currentAttempt) * 1000;
              await new Promise((res) => setTimeout(res, backoff));
              return attemptFetch();
            }

            dispatch({ type: "ERROR", payload: err.message });
            throw err;
          } finally {
            if (method === "GET") inFlightRequests.delete(url);
          }
        };

        return attemptFetch();
      })();

      if (method === "GET") inFlightRequests.set(url, fetchPromise);
      return fetchPromise;
    },
    [url, method, body, retries, cacheTime, options.headers],
  );

  useEffect(() => {
    cancelRequest.current = false;
    if (method === "GET" && !manual) {
      executeFetch();
    }
    return () => {
      cancelRequest.current = true;
    };
  }, [executeFetch, method, manual]);

  return { ...state, trigger: executeFetch };
}

export default useFetch;
