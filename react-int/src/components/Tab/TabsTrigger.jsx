import { useTabsContext } from "./TabsContext";

function TabsTrigger({ value, children }) {
  const { value: activeValue, setValue } = useTabsContext();

  const isActive = activeValue === value;

  return (
    <button
      role="tab"
      aria-selected={isActive}
      className={`tab-trigger ${isActive ? "active" : ""}`}
      onClick={() => setValue(value)}
    >
      {children}
    </button>
  );
}

export default TabsTrigger;
