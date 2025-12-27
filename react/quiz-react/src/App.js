import "./app.css";
import { useState } from "react";

const questions = [
  {
    title: "Who is Prime Minister of India?",
    options: ["Modi", "Rahul Gandhi", "Nikhil", "Naruto"],
    correct_answer: "Modi",
  },
  {
    title: "Who won the T20 World Cup in 2024?",
    options: ["India", "RSA", "AUS", "ENG"],
    correct_answer: "India",
  },
];

function App() {
  const [score, setScore] = useState(0);
  const [activeQuestion, setActiveQuestion] = useState(0);
  const [selected, setSelected] = useState("");

  const handleNext = () => {
    if (selected === questions[activeQuestion].correct_answer) {
      setScore((prev) => prev + 1);
    }

    setSelected(""); // reset selection
    setActiveQuestion((prev) => prev + 1);
  };

  const handleRestart = () => {
    setScore(0);
    setActiveQuestion(0);
    setSelected("");
  };

  if (activeQuestion >= questions.length) {
    return (
      <div className="container">
        <h1>Your final score is {score}</h1>
        <button onClick={handleRestart}>Start again</button>
      </div>
    );
  }

  return (
    <div className="container">
      <header className="header">QUIZ App</header>

      <h2>{questions[activeQuestion].title}</h2>

      <ol>
        {questions[activeQuestion].options.map((option) => (
          <li key={option}>
            <label>
              <input
                type="radio"
                name="quiz-option"
                value={option}
                checked={selected === option}
                onChange={(e) => setSelected(e.target.value)}
              />
              {option}
            </label>
          </li>
        ))}
      </ol>

      <button onClick={handleNext} disabled={!selected}>
        Next
      </button>

      <p>
        Question {activeQuestion + 1} of {questions.length}
      </p>
    </div>
  );
}

export default App;
