import { useState } from "react";
import "./chips.css";

function Chips() {
  const [value, setValue] = useState("");
  const [chips, setChips] = useState([]);

  const handleInputChange = (e) => {
    setValue(e.target.value);
  };

  const onChipsAdd = () => {
    if (value.trim() != "") {
      setChips((prev) => [...prev, value]);
      setValue("");
    }
  };

  const removeChip = (idx) => {
    const newChips = chips.filter((_, index) => index !== idx);
    setChips(newChips);
  };
  return (
    <div>
      <input type="text" value={value} onChange={handleInputChange} />
      <button className="chips-add-btn" onClick={onChipsAdd}>
        Add
      </button>
      <div>
        {chips.map((chip, index) => {
          return (
            <div className="chips-container" key={index}>
              {chip}
              <button
                onClick={() => removeChip(index)}
                className="chips-remove-btn"
              >
                X
              </button>
            </div>
          );
        })}
      </div>
    </div>
  );
}

export default Chips;
