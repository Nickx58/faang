/*

Implement a function clamp(number, lower, upper) to restrict a number within the inclusive lower and upper bounds.

*/

// My Solution

export default function clamp(value, lower, upper) {
  if (value >= lower && value <= upper) {
    return value;
  } else if (value < lower) {
    return lower;
  } else {
    return upper;
  }
}

// there solution

export default function clamp(value, lower, upper) {
  if (value < lower) {
    return lower;
  }

  if (value > upper) {
    return upper;
  }

  return value;
}