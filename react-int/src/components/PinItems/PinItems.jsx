import { useState } from "react";
import "./pinItems.css";
import { pint_items } from "../constants";

function PinItems() {
  const [itemsList, setItemsList] = useState(pint_items);

  const handleChange = (e, id) => {
    const updatedItems = itemsList.map((item) =>
      item.id === id ? { ...item, pinned: e.target.checked } : item,
    );

    setItemsList(updatedItems);
  };

  const pinnedItems = itemsList.filter((item) => item.pinned);
  const unPinnedItems = itemsList.filter((item) => !item.pinned);

  return (
    <div>
      <h2>Pin Items to top</h2>

      {[...pinnedItems, ...unPinnedItems].map((item) => (
        <div
          className="pin-items-container"
          style={{
            backgroundColor: item.pinned ? "rgb(10,150,150)" : "#f8f9fa",
          }}
          key={item.id}
        >
          <label>
            <input
              type="checkbox"
              checked={item.pinned}
              onChange={(e) => handleChange(e, item.id)}
            />
            {item.text}
          </label>
        </div>
      ))}
    </div>
  );
}

export default PinItems;
