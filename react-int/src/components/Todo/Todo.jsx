import { useMemo, useState } from "react";
import { defaultTask } from "../constants";

const Todo = () => {
  const [tasks, setTasks] = useState(defaultTask);
  const [value, setValue] = useState("");

  const handleKeyDown = (e) => {
    if (e.key === "Enter" && value.length) {
      const newTasks = {
        id: Date.now(),
        isCompleted: false,
        text: value,
      };
      const updatedTask = [...tasks, newTasks];
      setTasks(updatedTask);
      setValue("");
    }
  };
  const handleAddTask = (e) => {
    setValue(e.target.value);
  };

  const handleDelete = (id) => {
    const updatedTask = tasks.filter((task) => task.id !== id);
    setTasks(updatedTask);
  };

  const handleComplete = (id) => {
    setTasks((prev) =>
      prev.map((task) =>
        task.id == id ? { ...task, isCompleted: true } : task,
      ),
    );
  };

  const getCompletedTasks = useMemo(() => {
    const completedTasks = tasks.filter(
      (task) => task.isCompleted === true,
    ).length;
    return completedTasks;
  }, [tasks]);

  return (
    <div>
      <h1>Todo</h1>
      <h2>Number of tasks: {tasks.length}</h2>
      <h2>Number of Completed Tasks: {getCompletedTasks}</h2>
      <label htmlFor="Add Task">
        Add Task:{" "}
        <input
          value={value}
          onKeyDown={handleKeyDown}
          type="text"
          name="Add Task"
          onChange={handleAddTask}
        />
      </label>
      <ul>
        {tasks.map((task) => {
          return (
            <div
              style={{
                textDecoration: task.isCompleted ? "line-through" : "none",
              }}
            >
              <li key={task.id}>{task.text}</li>
              <button onClick={() => handleDelete(task.id)}>Delete</button>
              <button onClick={() => handleComplete(task.id)}>Complete</button>
            </div>
          );
        })}
      </ul>
    </div>
  );
};

export default Todo;
