import { useState } from "react";
import "./accordion.css";

const items = [
  {
    title: "JavaScript Basics",
    content: "Learn variables, functions, and loops in JavaScript.",
  },
  {
    title: "React.js Overview",
    content: "Understand components, state, and props in React.",
  },
  {
    title: "Node.js",
    content: "Basics of server-side development with Node.js.",
  },
  {
    title: "Full-Stack Development",
    content: "Build full-stack apps with React and Node.js.",
  },
];

function Accordion() {
  const [openIndex, setOpenIndex] = useState(null);

  function hanldeOpenIndex(index) {
    setOpenIndex(openIndex === index ? null : index);
  }
  if (!items || items.length === 0) {
    return <div>No items available.</div>;
  }
  return (
    <div className="accordion">
      {items.map((item, index) => {
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
