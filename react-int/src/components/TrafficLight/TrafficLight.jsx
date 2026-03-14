import { useEffect, useState } from "react";
import { lights } from "../constants";
import "./trafficLight.css";

function TrafficLight() {
  const [activeIndex, setActiveIndex] = useState(0);
  useEffect(() => {
    const id = setInterval(() => {
      setActiveIndex((prev) => (prev + 1) % lights.length);
    }, 1000);

    return () => {
      clearInterval(id);
    };
  });
  return (
    <div>
      <h2>Traffic Light</h2>
      {lights.map((light, index) => {
        return (
          <div
            className="traffic-light"
            style={{ backgroundColor: activeIndex === index && light }}
          />
        );
      })}
    </div>
  );
}

export default TrafficLight;
