import { useEffect, useRef, useState } from "react";
import { OTP_DIGITS } from "../constants";
import "./otp.css";

function OTP() {
  const [inputState, setInputState] = useState(new Array(OTP_DIGITS).fill(""));
  const refArrays = useRef([]);

  useEffect(() => {
    refArrays.current[0].focus();
  }, []);

  const handleKeyUp = (e, index) => {
    if (e.key === "Backspace") {
      refArrays.current[index - 1]?.focus();
    }
  };
  const handleValueChange = (value, index) => {
    if (isNaN(value)) return;
    const newValues = [...inputState];
    newValues[index] = value.slice(-1);
    setInputState(newValues);
    value.trim() && refArrays.current[index + 1]?.focus();
  };
  return (
    <div>
      {inputState.map((_, index) => {
        return (
          <input
            ref={(input) => (refArrays.current[index] = input)}
            onChange={(e) => handleValueChange(e.target.value, index)}
            className="otp-input"
            key={index}
            value={inputState[index]}
            type="text"
            onKeyUp={(e) => handleKeyUp(e, index)}
          />
        );
      })}
    </div>
  );
}

export default OTP;
