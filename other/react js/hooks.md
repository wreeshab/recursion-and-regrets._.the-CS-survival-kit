🔁 useState
Adds state to functional components.

Returns a state variable and a function to update it.

State persists between renders.

Updating the state triggers a re-render.

Used for: counters, input forms, toggles, etc.

🔄 useEffect
Runs side effects after render (like componentDidMount, componentDidUpdate, componentWillUnmount).

Commonly used for:

Fetching data

Subscribing to events

Manual DOM manipulation

Accepts two arguments:

A function to run

An optional dependency array

js
Copy
Edit
useEffect(() => {
  // side effect
  return () => {
    // cleanup
  };
}, [dependencies]);
If dependency array is:

Empty ([]): runs once after initial render

Omitted: runs after every render

[a, b]: runs when a or b changes

🌍 useContext
Provides a way to consume global values like theme, user info, etc.

Avoids prop drilling.

Works with React.createContext() and a Context.Provider.

Used for: Theme, Auth state, Language, Global config.

📦 useRef
Returns a mutable object that:

Can persist values across renders

Can hold DOM element references

Doesn’t cause re-render when the value changes.

Used for:

Focusing an input

Accessing DOM nodes

Storing interval IDs or previous values

🧠 useMemo
Memoizes the result of an expensive computation.

Prevents re-computation unless dependencies change.

Helps avoid unnecessary performance overhead.

js
Copy
Edit
const memoizedValue = useMemo(() => computeExpensiveValue(a, b), [a, b]);
Used for: heavy calculations, derived state.

🔁 useCallback
Returns a memoized version of a function.

Prevents re-creation of the function on each render.

Useful when passing callbacks to optimized child components (e.g., React.memo).

js
Copy
Edit
const memoizedFn = useCallback(() => doSomething(a, b), [a, b]);
Used for: performance optimization in re-renders.