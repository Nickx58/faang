import { useState, useRef } from "react";
import { ToastContext } from "./ToastContext";
import Toast from "./Toast";
import "./toast.css";

export function ToastProvider({ children }) {
  const [toasts, setToasts] = useState([]);
  const timersRef = useRef({});

  const removeToast = (id) => {
    clearTimeout(timersRef.current[id]);
    delete timersRef.current[id];

    setToasts((prev) => prev.filter((toast) => toast.id !== id));
  };

  const addToast = (message, type = "info") => {
    const id = Date.now();

    setToasts((prev) => [...prev, { id, message, type }]);

    timersRef.current[id] = setTimeout(() => {
      removeToast(id);
    }, 3000);
  };

  return (
    <ToastContext.Provider value={addToast}>
      {children}

      <div className="toast-container">
        {toasts.map((toast) => (
          <Toast key={toast.id} {...toast} onClose={removeToast} />
        ))}
      </div>
    </ToastContext.Provider>
  );
}
