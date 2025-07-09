# React Questions.

### Q. What is Virtual DOM?

The **Virtual DOM (VDOM)** is a lightweight, in-memory representation of the real DOM. It is maintained by React as a JavaScript object that mimics the structure of the actual browser DOM.

---

#### Why it exists:

Direct manipulation of the real DOM is slow. The Virtual DOM helps improve performance by minimizing real DOM updates.

---

#### How it works:

1. When state or props change, React creates a **new Virtual DOM**.
2. React then **diffs** (compares) the new Virtual DOM with the previous one.
3. It calculates the **minimal set of changes** needed to update the real DOM.
4. Finally, it applies those changes to the actual DOM efficiently.

---

#### Benefits:

- Improves rendering performance
- Minimizes direct DOM manipulation
- Enables declarative UI updates


### Q. What is the Reconciliation Algorithm in React?

**Reconciliation** is the process React uses to update the DOM when a component’s state or props change.

---

#### Purpose:

To efficiently determine **which parts of the UI need to be updated** and apply the **least number of changes** to the real DOM.

---

#### Core Principles:

1. **Virtual DOM Diffing**  
   React compares the new Virtual DOM with the previous one to identify differences.

2. **Key Assumption: DOM nodes are stable between renders**  
   React assumes elements of the same type at the same position represent the same node.

3. **O(n) Heuristic Diffing**  
   Instead of comparing every node recursively (which is expensive), React:
   - Compares elements **in order**
   - Reuses nodes when types match
   - Deletes and creates new nodes when types differ

---

#### Key Optimization: `key` Prop

When rendering lists, React uses the `key` prop to:
- Track items across renders
- Avoid unnecessary re-renders
- Maintain element identity

---

#### Special Cases:

- **Different element types** → old subtree is removed, new subtree is mounted.
- **Same type elements** → attributes are updated, and children are diffed recursively.

### Q. What is the Fiber Algorithm in React?

**Fiber** is the **reimplementation of React's reconciliation algorithm**, introduced in React 16. It improves performance, flexibility, and supports features like **concurrent rendering**.

---

#### Purpose:

To enable **interruptible rendering**, allowing React to **pause, resume, reuse, or abort** work. This improves responsiveness for complex UIs.

---

#### Why was Fiber introduced?

The old stack-based reconciliation was synchronous and couldn’t handle large updates smoothly. Fiber allows **incremental rendering**.

---

#### Key Features:

1. **Incremental Rendering**  
   Breaks rendering work into small units (called fibers) that can be paused and resumed.

2. **Prioritization**  
   Assigns priority levels to updates (e.g., user input > background data fetch).

3. **Concurrency Support**  
   Enables future features like **Concurrent Mode** and **Suspense**, where React can render while waiting for async data.

4. **Error Handling**  
   Improved error boundaries and better control over what to show when something fails.

---

#### How it works (High-Level):

- React builds a **work-in-progress fiber tree** instead of updating the DOM immediately.
- Once the entire tree is ready, it **commits** the changes in a single step.
- If needed, it can **pause** and handle higher priority tasks first.

---

#### Summary:

Fiber is React’s engine under the hood that:
- Makes rendering **asynchronous and interruptible**
- Adds **fine-grained control** over rendering
- Powers modern features like **Suspense** and **Concurrent Mode**
