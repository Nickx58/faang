import { useState } from "react";
import "./accordion.css";
import { accordion_items } from "../constants";

function Accordion() {
  const [openIndex, setOpenIndex] = useState(null);

  function hanldeOpenIndex(index) {
    setOpenIndex(openIndex === index ? null : index);
  }
  if (!accordion_items || accordion_items.length === 0) {
    return <div>No items available.</div>;
  }
  return (
    <div className="accordion">
      {accordion_items.map((item, index) => {
        return (
          <div className="accordion-item" key={index}>
            <button
              onClick={() => hanldeOpenIndex(index)}
              className="accordion-title"
            >
              {item.title}
            </button>
            {openIndex === index && (
              <div className="accordion-content">{item.content}</div>
            )}
          </div>
        );
      })}
    </div>
  );
}

export default Accordion;
