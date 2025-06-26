# objekt oriented programming eh?

### Q: What is Object-Oriented Programming?

**Answer:**

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of **"objects"**, which are instances of **classes**. It organizes software design around **data** (attributes) and **behavior** (methods), promoting modularity, reusability, and abstraction.

OOP revolves around four key principles:
1. **Encapsulation** – Bundling data and methods together and restricting direct access to internal states.
2. **Inheritance** – Mechanism to create a new class from an existing class, promoting code reuse.
3. **Polymorphism** – Ability to treat objects of different classes through a common interface (function overloading and overriding).
4. **Abstraction** – Hiding internal details and showing only essential features to the user.

**In C++:** OOP is supported using classes, access specifiers (`private`, `protected`, `public`), constructors/destructors, and features like virtual functions for runtime polymorphism.

**In Java:** OOP is enforced more strictly (everything is within classes), and it provides features like interfaces and garbage collection which differ from C++'s manual memory management.

### Q: Why Object-Oriented Programming?

**Answer:**

Object-Oriented Programming (OOP) helps manage software complexity by modeling real-world entities as **objects**, enabling better organization, modularity, and scalability in code.

**Key Reasons to Use OOP:**

1. **Modularity:** Code is organized into classes; changes in one class minimally affect others.
2. **Reusability:** Inheritance allows extending existing code without rewriting.
3. **Maintainability:** Encapsulation hides internal details, making code easier to debug and update.
4. **Scalability:** OOP designs are better suited for large systems with evolving requirements.
5. **Polymorphism:** Enables flexible and dynamic behavior through interfaces or base classes.

**Example (C++):**  
Using virtual functions, we can design systems that behave differently based on the object type at runtime.

**Compared to Procedural Programming:**  
- Procedural focuses on functions and logic flow; OOP focuses on data and entities.
- OOP is better for large, complex, real-world systems where maintainability and extensibility matter.

### Q: What other paradigms of programming exist besides OOP?

**Answer:**

A programming paradigm is a style or approach to writing programs. Besides Object-Oriented Programming, key paradigms include:

1. **Imperative Programming:**
   - Focuses on *how* to achieve a task using step-by-step instructions.
   - Programs modify the state through assignment and control flow statements.
   - Includes:
     - **Procedural Programming:** Based on procedure/function calls. Code is structured into reusable routines.  
       *Example:* C
     - **Parallel Programming:** Tasks are divided and executed concurrently to improve performance.  
       *Example:* OpenMP, CUDA

2. **Declarative Programming:**
   - Focuses on *what* to achieve, not how.
   - No explicit control flow; describes logic or structure.
   - Includes:
     - **Functional Programming:** Pure functions, immutability, and no side effects.  
       *Example:* Haskell, Scala
     - **Logic Programming:** Uses facts and rules to derive conclusions.  
       *Example:* Prolog
     - **Markup & Query Languages:**  
       *Example:* SQL, HTML

3. **Event-Driven Programming:**
   - Execution is driven by events like user actions or messages.
   - Common in GUI applications and asynchronous systems.  
   *Example:* JavaScript, Node.js

**Note:** Many modern languages (like Python, JavaScript, and Scala) support multiple paradigms, allowing developers to choose the best fit for a problem.

### Q: What is the difference between Structured Programming and Object-Oriented Programming?

**Answer:**

Structured Programming and Object-Oriented Programming are two distinct paradigms for designing programs. Structured Programming focuses on the logical flow of control, while OOP organizes code around objects.

| Aspect                         | Object-Oriented Programming                          | Structured Programming                           |
|-------------------------------|-------------------------------------------------------|--------------------------------------------------|
| **Core Concept**              | Based on objects that encapsulate data and behavior  | Based on dividing program into functions/modules |
| **Approach**                  | Bottom-up                                             | Top-down                                         |
| **Data Access**               | Controlled access using access specifiers             | No data access restriction                       |
| **Reusability**               | Achieved via inheritance and polymorphism            | Achieved via functions and loops                 |
| **Execution Style**          | Dynamic method calls based on object behavior        | Sequential function calls                        |
| **Maintainability**          | Easier to modify and extend                          | More difficult to modify with growth             |
| **Focus**                     | Data-centric                                         | Procedure-centric                                |

**Note:** Structured Programming is considered a precursor to OOP and is a subset of the procedural paradigm.

### Q: What are the advantages and disadvantages of OOP?

**Answer:**

| Advantages                                      | Disadvantages                                                                 |
|------------------------------------------------|-------------------------------------------------------------------------------|
| Code reusability through inheritance           | Requires good understanding of objects and relationships                     |
| Easier to maintain and update                  | Needs proper planning and design upfront                                     |
| Better data security via encapsulation         | Not ideal for simple or linear problems                                       |
| Scalable and flexible with polymorphism        | Programs can become longer and more verbose                                  |
| Models real-world entities, reducing complexity| Initial development may be slower compared to procedural programming         |

### Q: What is a class?

**Answer:**

A **class** is a fundamental construct in Object-Oriented Programming that defines a **template for creating objects**. It combines **data (called attributes or members)** and **functions (called methods)** into a single unit, enabling encapsulation, abstraction, and modular design.

#### Key Properties:
- **Encapsulation:** Groups related data and functions together.
- **Abstraction:** Hides internal details and exposes only relevant behavior.
- **Reusability:** Can be extended using inheritance.
- **Instantiation:** Objects are created from the class, each with its own copy of data members.
