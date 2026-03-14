import { useState } from "react";
import "./quiz.css";
import { qBank } from "../constants";

function Quiz() {
  const [activeQuestion, setActiveQuestion] = useState(0);
  const [finalScore, setFinalScore] = useState(0);
  const [ans, setAns] = useState("");

  const currentQuestion = qBank[activeQuestion];

  const handleNextQuestion = () => {
    const isCorrect = ans === currentQuestion.answer;

    if (isCorrect) {
      setFinalScore((prev) => prev + 1);
    }

    setActiveQuestion((prev) => prev + 1);
    setAns("");
  };

  const handleGameReset = () => {
    setActiveQuestion(0);
    setFinalScore(0);
    setAns("");
  };

  const isQuizFinished = activeQuestion >= qBank.length;

  return (
    <div>
      <h2 style={{ textAlign: "center" }}>Quiz App</h2>

      <div className="quiz-container">
        {!isQuizFinished ? (
          <>
            <h3>
              Question {activeQuestion + 1} / {qBank.length}
            </h3>

            <h4>{currentQuestion.question}</h4>

            {currentQuestion.options.map((option) => (
              <label key={option}>
                <input
                  type="radio"
                  name="option"
                  value={option}
                  checked={ans === option}
                  onChange={(e) => setAns(e.target.value)}
                />
                {option}
              </label>
            ))}

            <button disabled={!ans} onClick={handleNextQuestion}>
              Submit
            </button>
          </>
        ) : (
          <div>
            <h3>
              Final Score: {finalScore} / {qBank.length}
            </h3>

            <button onClick={handleGameReset}>Play Again</button>
          </div>
        )}
      </div>
    </div>
  );
}

export default Quiz;
