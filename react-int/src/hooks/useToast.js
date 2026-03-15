import { useContext } from "react";
import { ToastContext } from "../components/Toast/ToastContext";

export function useToast() {
  return useContext(ToastContext);
}
