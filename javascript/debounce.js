export default function debounce(func, wait) {
  let timer = null;

  return function (...args) {
    const context = this;

    clearTimeout(timer);
    timer = setTimeout(() => {
      timer = null;
      func.apply(context, args);
    }, wait);
  };
}

/*

1. function (...args)
args = ["John", 25];
debounced("John", 25);
We use ...args because we don't know how many arguments func will need.

2. Why const context = this?

This is about preserving the value of this
When we eventually execute the function inside setTimeout, we want this to still refer to user

3. Why func.apply(context, args)?

apply() allows us to call a function while explicitly specifying:
what this should be
what arguments should be passed
Call func with this = context and pass all the arguments stored in args

PRESS → WAIT
PRESS → RESET WAIT
PRESS → RESET WAIT
PRESS → RESET WAIT

        STOP PRESSING
             ↓
           WAIT
             ↓
            RUN

Debounce = "Wait until I'm done doing this repeatedly."

*/
