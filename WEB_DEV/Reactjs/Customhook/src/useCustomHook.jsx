import { useState } from "react";

const useCustomHook = (initialCount) => {
  const [count, setCount] = useState(initialCount);

  const increment = () => setCount(count + 1);
  const decrement = () => setCount(count - 1);
  const reset = () => setCount(0);

  return [count, { increment, decrement, reset }];
};

export default useCustomHook;
