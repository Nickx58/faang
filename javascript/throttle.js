function throttle(func, wait) {
  let timer = null;

  return function (...args) {
    if (timer) {
      return; // Still in the waiting period
    }

    // 1. Call immediately
    func.apply(this, args);

    // 2. Start the waiting period
    timer = setTimeout(() => {
      timer = null;
    }, wait);
  };
}

/*
PRESS → RUN IMMEDIATELY
        ↓
     BLOCK
        ↓
     X ms
        ↓
    ALLOW

Throttle = "Don't let me do this too often."

If you're going to use this immediately, you don't need to save it. If you need it later inside a timer/callback, save it (or otherwise preserve it).

*/
