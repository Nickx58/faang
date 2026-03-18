import { useState } from "react";
import Interest from "./Interest";
import Profile from "./Profile";
import "./tabform.css";

const config = [
  {
    name: "Profile",
    component: Profile,
  },
  {
    name: "Interest",
    component: Interest,
  },
];
function TabForm() {
  const [activeTab, setActiveTab] = useState(0);
  const [data, setData] = useState({
    name: "Nick",
    age: 28,
    email: "nn@gmail.com",
  });
  const ActiveTabComponent = config[activeTab].component;
  console.log(data, "data");
  return (
    <div>
      <div className="tab-form-container">
        {config.map((tab, index) => {
          return (
            <div className="tab-form" onClick={() => setActiveTab(index)}>
              {tab.name}
            </div>
          );
        })}
      </div>
      <div className="tab-form-component">
        <ActiveTabComponent data={data} setData={setData} />
      </div>
    </div>
  );
}

export default TabForm;
