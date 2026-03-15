import { useToast } from "../../hooks/useToast";

function ToastExample() {
  const toast = useToast();

  return (
    <div>
      <button onClick={() => toast("Success!", "success")}>Success</button>
      <button onClick={() => toast("Error occurred", "error")}>Error</button>
    </div>
  );
}

export default ToastExample;
