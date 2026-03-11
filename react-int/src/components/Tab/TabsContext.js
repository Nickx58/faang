import { createContext, useContext } from "react";

const TabsContext = createContext(null);

export function useTabsContext() {
  const context = useContext(TabsContext);

  if (!context) {
    throw new Error("Tabs components must be used inside <Tabs>");
  }
  return context;
}

export default TabsContext;
