import { useEffect, useState, useRef } from "react";
import "./searchInput.css";

function SearchInput() {
  const [value, setValue] = useState("");
  const [results, setResults] = useState([]);
  const [showResults, setShowResults] = useState(false);
  const [cache, setCache] = useState({});
  const [loading, setLoading] = useState(false);

  const controllerRef = useRef(null);

  useEffect(() => {
    if (!value.trim()) {
      setResults([]);
      return;
    }

    if (cache[value]) {
      setResults(cache[value]);
      return;
    }

    const fetchData = async () => {
      try {
        setLoading(true);

        controllerRef.current?.abort(); // cancel previous request
        const controller = new AbortController();
        controllerRef.current = controller;

        const response = await fetch(
          `https://dummyjson.com/recipes/search?q=${value}`,
          { signal: controller.signal },
        );

        const json = await response.json();

        setResults(json?.recipes || []);
        setCache((prev) => ({ ...prev, [value]: json?.recipes || [] }));
      } catch (err) {
        if (err.name !== "AbortError") {
          console.error(err);
        }
      } finally {
        setLoading(false);
      }
    };

    const timer = setTimeout(fetchData, 400); // better debounce

    return () => clearTimeout(timer);
  }, [value]);

  return (
    <div className="search-input">
      <h1>Auto Complete Search</h1>

      <div className="input-wrapper">
        <input
          type="text"
          className="search"
          value={value}
          placeholder="Search recipes..."
          onFocus={() => setShowResults(true)}
          onBlur={() => {
            // delay to allow click
            setTimeout(() => setShowResults(false), 200);
          }}
          onChange={(e) => setValue(e.target.value)}
        />

        {showResults && (
          <div className="search-results">
            {loading && <div className="result">Loading...</div>}

            {!loading && results.length === 0 && (
              <div className="result">No results found</div>
            )}

            {results.map((r) => (
              <div
                key={r.id}
                className="result"
                onClick={() => {
                  setValue(r.name);
                  setShowResults(false);
                }}
              >
                {r.name}
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
}

export default SearchInput;
