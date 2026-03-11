import { useTabsContext } from "./TabsContext";

function TabsContent({ value, children }) {
  const { value: activeValue } = useTabsContext();

  if (value !== activeValue) return null;

  return (
    <div role="tabpanel" className="tab-content">
      {children}
    </div>
  );
}

export default TabsContent;
