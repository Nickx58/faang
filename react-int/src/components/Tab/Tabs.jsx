import { useState } from "react";
import TabsContext from "./TabsContext";
import "./tabs.css";

function Tabs({ value, defaultValue, onValueChange, children }) {
  const [internalValue, setInternalValue] = useState(defaultValue);
  const currentValue = value !== undefined ? value : internalValue;

  function setValue(v) {
    if (value === undefined) {
      setInternalValue(v);
    }

    if (onValueChange) {
      onValueChange(v);
    }
  }

  return (
    <TabsContext.Provider value={{ value: currentValue, setValue }}>
      {children}
    </TabsContext.Provider>
  );
}

export default Tabs;
