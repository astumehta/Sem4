import { useState } from "react";
import reactLogo from "./assets/react.svg";
import viteLogo from "/vite.svg";
import "./App.css";

function App() {
  const [count, setCount] = useState(0);

  return (
    <>
      <div className="card">
        <div className="count" id="count-value">
          <h1>Count is: {count}</h1>
        </div>

        <button
          className="buttons"
          onClick={() => setCount((count) => count + 1)}
        >
          Increment
        </button>
        <button
          className="buttons"
          onClick={() => setCount((count) => (count = 0))}
        >
          Reset
        </button>
        <button
          className="buttons"
          onClick={() => setCount((count) => count - 1)}
        >
          Decrement
        </button>
      </div>
    </>
  );
}

export default App;
