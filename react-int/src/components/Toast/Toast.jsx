import "./toast.css";
function Toast({ id, message, type, onClose }) {
  return (
    <div className={`toast ${type}`}>
      {message}
      <span className="close-btn" onClick={() => onClose(id)}>
        ✕
      </span>
    </div>
  );
}

export default Toast;
