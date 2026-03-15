import { useState } from "react";
import "./pinItems.css";

const items = [
  { id: 1, text: "Buy groceries", pinned: false },
  { id: 2, text: "Call Alice", pinned: false },
  { id: 3, text: "Meeting with Bob", pinned: false },
  { id: 4, text: "Pay electricity bill", pinned: false },
  { id: 5, text: "Read a book", pinned: false },
  { id: 6, text: "Go for a walk", pinned: false },
  { id: 7, text: "Fix bug #234", pinned: false },
  { id: 8, text: "Review pull requests", pinned: false },
];

function PinItems() {
  const [itemsList, setItemsList] = useState(items);

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
