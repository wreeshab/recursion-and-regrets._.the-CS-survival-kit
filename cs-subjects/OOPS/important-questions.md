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

   - Focuses on _how_ to achieve a task using step-by-step instructions.
   - Programs modify the state through assignment and control flow statements.
   - Includes:
     - **Procedural Programming:** Based on procedure/function calls. Code is structured into reusable routines.  
       _Example:_ C
     - **Parallel Programming:** Tasks are divided and executed concurrently to improve performance.  
       _Example:_ OpenMP, CUDA

2. **Declarative Programming:**

   - Focuses on _what_ to achieve, not how.
   - No explicit control flow; describes logic or structure.
   - Includes:
     - **Functional Programming:** Pure functions, immutability, and no side effects.  
       _Example:_ Haskell, Scala
     - **Logic Programming:** Uses facts and rules to derive conclusions.  
       _Example:_ Prolog
     - **Markup & Query Languages:**  
       _Example:_ SQL, HTML

3. **Event-Driven Programming:**
   - Execution is driven by events like user actions or messages.
   - Common in GUI applications and asynchronous systems.  
     _Example:_ JavaScript, Node.js

**Note:** Many modern languages (like Python, JavaScript, and Scala) support multiple paradigms, allowing developers to choose the best fit for a problem.

### Q: What is the difference between Structured Programming and Object-Oriented Programming?

**Answer:**

Structured Programming and Object-Oriented Programming are two distinct paradigms for designing programs. Structured Programming focuses on the logical flow of control, while OOP organizes code around objects.

| Aspect              | Object-Oriented Programming                         | Structured Programming                           |
| ------------------- | --------------------------------------------------- | ------------------------------------------------ |
| **Core Concept**    | Based on objects that encapsulate data and behavior | Based on dividing program into functions/modules |
| **Approach**        | Bottom-up                                           | Top-down                                         |
| **Data Access**     | Controlled access using access specifiers           | No data access restriction                       |
| **Reusability**     | Achieved via inheritance and polymorphism           | Achieved via functions and loops                 |
| **Execution Style** | Dynamic method calls based on object behavior       | Sequential function calls                        |
| **Maintainability** | Easier to modify and extend                         | More difficult to modify with growth             |
| **Focus**           | Data-centric                                        | Procedure-centric                                |

**Note:** Structured Programming is considered a precursor to OOP and is a subset of the procedural paradigm.

### Q: What are the advantages and disadvantages of OOP?

**Answer:**

| Advantages                                      | Disadvantages                                                        |
| ----------------------------------------------- | -------------------------------------------------------------------- |
| Code reusability through inheritance            | Requires good understanding of objects and relationships             |
| Easier to maintain and update                   | Needs proper planning and design upfront                             |
| Better data security via encapsulation          | Not ideal for simple or linear problems                              |
| Scalable and flexible with polymorphism         | Programs can become longer and more verbose                          |
| Models real-world entities, reducing complexity | Initial development may be slower compared to procedural programming |

### Q: What is a class?

**Answer:**

A **class** is a fundamental construct in Object-Oriented Programming that defines a **template for creating objects**. It combines **data (called attributes or members)** and **functions (called methods)** into a single unit, enabling encapsulation, abstraction, and modular design.

#### Key Properties:

- **Encapsulation:** Groups related data and functions together.
- **Abstraction:** Hides internal details and exposes only relevant behavior.
- **Reusability:** Can be extended using inheritance.
- **Instantiation:** Objects are created from the class, each with its own copy of data members.

### Q: What are access modifiers?

**Answer:**

**Access modifiers** define the visibility and accessibility of class members (data and methods) from outside the class. They enforce encapsulation by controlling how the internal details of a class are exposed.

There are three access modifiers in C++ and Java:

---

#### `public`

- Members are accessible from **anywhere** (outside the class, other functions, or classes).
- Used when you want unrestricted access to members.
- Commonly used for interface methods or constants.

---

#### `private`

- Members are accessible **only within the class** itself.
- Promotes **encapsulation** by hiding implementation details.
- Accessed externally through **getter/setter** functions (if needed).
- In C++, `friend` functions/classes can access private members.

---

#### `protected`

- Similar to `private`, but members are also accessible in **derived (child) classes**.
- Useful in inheritance when base class members need to be visible to subclasses but hidden from the rest of the program.

---

**Java Note:**
Java also includes a **default (package-private)** modifier (no keyword), which makes members accessible only within the same package.

### Q: What are friend classes and friend functions?

**Answer:**

Friend classes and friend functions in C++ allow controlled access to the **private** and **protected** members of a class from outside, without making those members public. This helps in scenarios where internal access is necessary without fully compromising encapsulation.

---

#### Friend Class:

- A **friend class** is a class that is granted access to another class’s private and protected members.
- The friendship is declared **inside the class** being accessed.
- The declaration can be made under `private`, `protected`, or `public`—placement does **not** affect its behavior.
- **Use cases:**
  - **Operator Overloading:** Enables access to internal state during binary operator implementations.
  - **Tightly Coupled Classes:** e.g., a `LinkedList` class needing access to internal members of a `Node` class.
  - **Builder Pattern:** Allows a builder class to construct an object by directly modifying internal members.
  - **Selective Internal Access:** Grants trusted classes internal access without exposing details globally.
  - **Performance-Critical Code:** Avoids overhead of getter/setter functions in critical systems.

---

#### Friend Function:

- A **friend function** is a non-member function that is allowed to access a class’s private and protected members.
- Friendship is **granted by the class**, not requested by the function.
- Can be:
  - A **global function**, explicitly declared as a friend.
  - A **member function** of another class, declared as a friend using the class name and scope resolution.

---

#### Trade-offs:

- **Advantage:** Provides controlled access when necessary, especially for performance or tight coupling.
- **Disadvantage:** May lead to **tight coupling** and reduced encapsulation if overused.

#### Java Note:

- **Java does not support friend classes or friend functions.**
- Instead, Java controls access using **package-level access**, **protected**, and **public/private** modifiers.
- Collaboration between tightly coupled classes is often handled by placing them in the **same package**, or by using **inner classes**.

### Q: What are the 5 types of member functions in C++?

**Answer:**

C++ supports different types of member functions based on purpose, accessibility, and behavior. These are:

---

#### 1. **Simple Member Function**

- A standard function defined within a class.
- Can access both private and public members of the class.
- Requires an object to be invoked.

---

#### 2. **Static Member Function**

- Belongs to the class, not to any specific object.
- Can be called using the class name without creating an object.
- Can access only **static members** of the class.
- Does not have access to `this` pointer.
- Though callable through an object, it’s discouraged as it does not act on instance-specific data.

---

#### 3. **Const Member Function**

- Guarantees that it will not modify any non-static data members of the class.
- Useful for functions that only read object state.
- Can be called on `const` objects.
- Cannot invoke non-const functions.
- Helps enforce read-only operations and improves API clarity and compiler optimization.

---

#### 4. **Inline Member Function**

- Function whose body is defined inside the class.
- Compiler may expand it at the call site to avoid function call overhead.
- Best suited for small, frequently called functions like accessors.
- Excessive inlining can lead to code bloat; compiler may ignore the inline request.

---

#### 5. **Friend Function**

- Not a member of the class but declared as a **friend**.
- Can access private and protected members of the class.
- Useful in operator overloading, utility functions, or tightly coupled classes.
- Helps when external logic needs privileged access without exposing members globally.
- Declared in the class but defined outside.

---

### Java Note:

- Java does **not** support `friend` functions or classes.
- Java does not have `const` functions; immutability is handled through design (e.g., `final`, no setters).
- Java methods defined inside a class are implicitly non-inline; JVM handles inlining internally.
- Static functions behave similarly in Java: they belong to the class and can be called without an object.

### Q: What are access modifiers and non-access modifiers? What is the difference between them?

**Answer:**

Modifiers are keywords used to define the **scope**, **visibility**, or **behavior** of classes, methods, and variables.

---

### **Access Modifiers**

Access modifiers control **visibility**—who can access a class or member.

#### In C++:

- `public`: Accessible from anywhere.
- `private`: Accessible only within the class.
- `protected`: Accessible within the class and its derived classes.

#### In Java:

- `public`: Accessible from anywhere.
- `private`: Accessible only within the class.
- `protected`: Accessible within the package and in subclasses (even outside the package).
- _(default / package-private)_: No keyword; accessible within the same package only.

---

### **Non-Access Modifiers**

Non-access modifiers define **behavioral or semantic properties** of classes, methods, and variables. They do **not** control visibility.

#### In C++:

- `static`: Belongs to the class, not instances.
- `const`: Marks data or functions as immutable.
- `inline`: Suggests inlining the function to reduce call overhead.
- `virtual`: Enables runtime polymorphism.
- `mutable`: Allows modification even in `const` context.
- `friend`: Grants access to private/protected members.

#### In Java:

- `static`: Class-level member.
- `final`: Prevents inheritance, reassignment, or overriding.
- `abstract`: Declares abstract classes or methods with no body.
- `synchronized`: Used for thread-safety in methods/blocks.
- `native`, `transient`, `volatile`: Misc. behavioral modifiers for low-level or advanced use.

---

### **Difference Between Access and Non-Access Modifiers**

| Aspect                | Access Modifiers                          | Non-Access Modifiers                                        |
| --------------------- | ----------------------------------------- | ----------------------------------------------------------- |
| **Purpose**           | Control visibility/scope                  | Define behavior or characteristics                          |
| **Examples (C++)**    | `public`, `private`, `protected`          | `static`, `const`, `inline`, `virtual`, `friend`, `mutable` |
| **Examples (Java)**   | `public`, `private`, `protected`, default | `static`, `final`, `abstract`, `synchronized`, `transient`  |
| **Affect on Access?** | Yes                                       | No                                                          |
| **Usage Scope**       | Classes, methods, variables               | Classes, methods, variables                                 |

### Q: What is the difference between static and dynamic binding?

**Answer:**

**Binding** refers to the process of connecting a function call to the function definition. It determines which version of a function or method gets executed.

---

### **Static Binding (Early Binding)**

- **Resolved at compile time.**
- Used for:
  - Normal function calls
  - Function overloading
  - Operator overloading
  - Static methods
- **Faster**, as the call is determined before runtime.
- **No runtime polymorphism**.

---

### **Dynamic Binding (Late Binding)**

- **Resolved at runtime** using a virtual function table (vtable).
- Used for:
  - Virtual functions in C++
  - Overridden methods in base/derived relationships
- Enables **runtime polymorphism**.
- Slightly **slower**, as function lookup happens during execution.

---

### **Key Differences**

| Aspect              | Static Binding             | Dynamic Binding                      |
| ------------------- | -------------------------- | ------------------------------------ |
| **Resolution Time** | Compile time               | Runtime                              |
| **Polymorphism**    | Not supported              | Enables runtime polymorphism         |
| **Function Type**   | Normal, overloaded, static | Virtual (C++), Overridden (Java)     |
| **Speed**           | Faster execution           | Slightly slower due to vtable/lookup |
| **Flexibility**     | Less flexible              | More flexible and extensible         |

---

### **Java Note:**

- Java uses **dynamic binding** by default for **non-static**, **non-final**, **non-private** methods.
- Static, private, and final methods use **static binding** because they cannot be overridden.

### Q: What is the `static` keyword? Explain its use in C++ and how it's different in Java.

**Answer:**

The `static` keyword in C++ is used to define **class-level members** that are shared across all instances, instead of being tied to individual objects. It applies to **variables**, **methods**, **blocks**, and **nested classes (in Java)**.

---

### 🔹 Static Variables in C++

- Declared inside a class using the `static` keyword.
- **Shared among all instances**—only one copy exists.
- Initialized once at program startup (for globals) or first time control passes (for locals).
- Can be used for counters, shared configuration, etc.

#### Key Properties:

- Exist independently of any object.
- Useful for data that must persist across function calls or objects.
- At class level: shared among all instances.
- At function level: retains value across multiple calls.

---

### 🔹 Static Member Functions in C++

- Belong to the class, not to any object.
- Can be invoked using the class name.
- **Cannot access non-static members directly** (no `this` pointer).
- Ideal for utility functions or logic unrelated to object state.

---

### 🔹 Access & Inheritance

- Static members are **not inherited** in the traditional sense, but can be accessed via derived classes.
- Static functions **can be overloaded** but **cannot be overridden**.
- Use of the class name for access is preferred, even though access via object is syntactically allowed.

---

### 🔹 When to Use Static

- To store values shared across all objects (e.g., configuration, counters).
- To provide utility/helper functions (e.g., logging, conversions).
- To reduce memory usage in large-scale programs (shared constants or objects).

---

### 🔹 Static Initialization Blocks (C++ Context)

- C++ does **not have explicit static blocks** like Java.
- Initialization of static members is done in global scope or via static constructors/patterns.

---

### 🔹 C++ Note on Static Classes

- **C++ does not support static classes directly.**
- However, a class with only static members can simulate similar behavior.
- Unlike Java, **C++ allows static variables in free functions**, not just within classes.

---

### 🔹 Java Perspective

- In **Java**, `static` is used similarly:
  - **Static Variables**: Shared among all instances.
  - **Static Methods**: Can be accessed without an object; can't access instance members.
  - **Static Blocks**: Used to initialize static data; runs once when the class is loaded.
  - **Static Nested Classes**: Java allows **static classes only as nested classes**.
    - These **do not need outer class instances** and can access only static members of the outer class.
- Java restricts static context more strictly than C++, e.g., top-level classes cannot be static.
- Common use cases: utility methods (`Math`, `Collections`), constants (`static final`), and factory methods.

---

### Q: What is the `final` keyword in Java?

**Answer:**

The `final` keyword in Java is a **non-access modifier** used to restrict modifications. It can be applied to **variables**, **methods**, and **classes**, each with different implications.

---

### 🔹 Final Variables

A `final` variable's value **cannot be reassigned** once initialized.

#### Types of Final Variables:

| Type                 | Scope      | Initialization                 | Reassignable? |
| -------------------- | ---------- | ------------------------------ | ------------- |
| `final`              | Per object | At declaration                 | ❌            |
| `blank final`        | Per object | In constructor/block           | ❌            |
| `static final`       | Per class  | At declaration or static block | ❌            |
| `static blank final` | Per class  | In static block                | ❌            |

#### Important:

- If a `final` variable is a **reference**, you **cannot rebind** it to another object, but you **can modify the object's internal state**.
  - ✅ `arr[0] = 5;` ❌ `arr = new int[10];`

---

### 🔹 Final Methods

- A **final method cannot be overridden** in subclasses.
- Used to **lock method behavior** and prevent modification.
- Helpful in securing critical logic in base classes.

---

### 🔹 Final Classes

- A **final class cannot be extended**.
- Prevents inheritance completely.
- Used for:
  - **Security** (e.g., `String`, `Integer` classes)
  - **Immutable object design**
  - **API stability**

---

### 🔸 Other Notes

- **Local Final Variables**: Declared inside methods/blocks; must be initialized exactly once.
- **Used in loops and lambdas** where variables must be _effectively final_.
- **Not transitive**: Final reference ≠ final object.

---

### 🔁 Summary Table

| Context   | Effect of `final`                  |
| --------- | ---------------------------------- |
| Variable  | Value cannot be reassigned         |
| Method    | Cannot be overridden in a subclass |
| Class     | Cannot be subclassed or extended   |
| Reference | Cannot point to another object     |

### Q: What is the `virtual` keyword in C++?

**Answer:**

The `virtual` keyword in C++ enables **runtime polymorphism**. It allows a member function in a base class to be **overridden** in a derived class, and ensures that the function call is **resolved at runtime** based on the actual type of the object, not the pointer/reference type.

---

### 🔹 Key Characteristics

- Used for **dynamic (late) binding**.
- Applied to member functions of a class to allow overriding in derived classes.
- When a base class declares a function as `virtual`, derived classes can provide their own implementation of the function.
- The function remains `virtual` throughout the inheritance chain.

---

### 🔹 Use Cases

- Enables **function overriding** for polymorphic behavior.
- Essential when using **base class pointers or references** to refer to derived class objects.
- Ensures **correct destructor behavior** in inheritance hierarchies.

---

### 🔹 Additional Notes

- Virtual functions must be **non-static**.
- **Constructors cannot be virtual**.
- **Destructors should be virtual** in base classes when using inheritance to ensure proper cleanup.
- Declaring a function as `= 0` makes it a **pure virtual function**, making the class **abstract**.

---

### 🔸 Java Perspective

- In Java, all **non-static, non-final** methods are **virtual by default**.
- Dynamic method dispatch is automatically handled by the JVM.
- Java does not require any special keyword like `virtual` to achieve runtime polymorphism.
- Java does not support virtual destructors because it uses garbage collection.

### Q: What does the `abstract` keyword do in Java?

**Answer:**

The `abstract` keyword in Java is a **non-access modifier** used to define **incomplete entities**—classes and methods that are meant to be **extended or implemented later**.

---

### 🔹 Abstract Classes

An **abstract class** cannot be instantiated directly. It is designed to serve as a **base class** and can contain both:

- **Abstract methods**: Declared without a body, must be implemented by subclasses.
- **Concrete methods**: Have a complete definition and can be inherited.

#### Key Points:

- Can contain **constructors**, **instance variables**, and **concrete methods**.
- Subclasses must **implement all abstract methods** unless they are also declared abstract.
- Useful for sharing common code and enforcing design contracts.

---

### 🔹 Abstract Methods

An **abstract method** is a method with:

- **No body** (only signature),
- Declared with the `abstract` keyword,
- Meant to be **overridden** by concrete subclasses.

---

### 🔹 Advantages

1. **Enforces structure**: Guarantees that certain methods are implemented.
2. **Promotes code reuse**: Concrete logic can be shared in the abstract class.
3. **Supports polymorphism**: Subclasses can be treated via the base type.
4. **Improves flexibility**: Allows design of extensible frameworks.

---

### 🔹 Restrictions & Invalid Combinations

| Illegal Combination     | Reason                                                                |
| ----------------------- | --------------------------------------------------------------------- |
| `abstract final`        | Final prevents overriding; abstract requires it                       |
| `abstract static`       | Static methods can't be overridden; abstract requires overriding      |
| `abstract private`      | Private methods can't be accessed or overridden by subclasses         |
| `abstract synchronized` | Synchronized needs method body; abstract has none                     |
| `abstract native`       | Native methods are implemented in external code; abstract has no body |
| `abstract strictfp`     | strictfp applies to floating-point behavior in the method body        |

---

### 🔸 Comparison with C++ (Pure Virtual)

| Feature                      | C++ (Pure Virtual)      | Java (Abstract)            |
| ---------------------------- | ----------------------- | -------------------------- |
| Syntax                       | `virtual void f() = 0;` | `abstract void f();`       |
| Abstract class instantiation | ❌                      | ❌                         |
| Force override in subclass?  | ✅                      | ✅                         |
| Multiple inheritance         | Supported               | Not supported with classes |

### Q: What is the `explicit` keyword in C++?

**Answer:**

The `explicit` keyword in C++ is used to prevent **implicit conversions** through constructors or conversion operators that take a single argument. It ensures that such conversions are only performed when **explicitly invoked**, which helps avoid subtle bugs and improves code clarity.

---

### 🔹 Why Use `explicit`?

By default, C++ allows implicit calls to constructors with a single parameter, which can lead to **unexpected behavior** if the compiler automatically converts one type to another.

**Without `explicit`:**

```cpp
class Meter {
public:
    Meter(int m) { /*...*/ }
};

void printLength(Meter m);
printLength(5);  // ✅ Implicitly converts 5 to Meter
With explicit:

class Meter {
public:
    explicit Meter(int m) { /*...*/ }
};

printLength(5);            // ❌ Error: implicit conversion not allowed
printLength(Meter(5));     // ✅ OK: explicit conversion
```

🔹 Key Points
Prevents unintended conversions

Applies to constructors and conversion operators

Promotes safe and readable code

Especially useful in APIs and library design

🔸 Java Perspective
Java **does not support** implicit constructor-based conversions, so it doesn’t need an explicit keyword. **All type conversions in Java must be explicitly written by the programmer.**

### Q: What is the `this` keyword in C++?

**Answer:**

The `this` keyword in C++ is a **special pointer** available inside non-static member functions. It points to the **current object** that invoked the method.

---

### 🔹 Key Characteristics

- `this` is a **pointer to the invoking object** (i.e., of type `ClassName*`).
- Automatically passed to all **non-static** member functions.
- Used for:
  - **Disambiguating** member variables from parameters.
  - **Returning** the current object (`return *this`) for method chaining.
  - **Passing** the object itself to other functions or classes.
- **Not available** in static member functions.

---

### 🔹 Common Use Cases

| Use Case | Description |
|----------|-------------|
| 1        | Refers to instance variables (`this->name`, `this->age`) |
| 2        | Returns the current object (`return *this`)              |
| 3        | Passed as method parameter (`printDetails(this)`)       |
| 4        | Invokes another method in the same class (`this->print()`) |
| 5        | Passed to another class constructor                     |

> Note: C++ doesn't support constructor chaining using `this()` like Java does. Constructor delegation is done differently in C++ (since C++11 using constructor delegation syntax).

---

### 🔸 Java Perspective

In Java, `this` is used similarly but is an **implicit reference** (not a pointer).  
It supports an additional feature: **constructor chaining** using `this()`.

| Use Case | Description |
|----------|-------------|
| 1        | Refers to instance variables (`this.name`, `this.age`) |
| 2        | Calls another constructor in the same class (`this(...)`) |
| 3        | Returns the current object (`return this`)             |
| 4        | Passed as method parameter (`Helper.display(this)`)   |
| 5        | Invokes another method in the same class (`this.sayHello()`) |
| 6        | Passed to another class constructor (`new College(this)`) |

### Q: What are Constructor Chaining, Implicit Reference, and Explicit Reference?

---

### 🔹 Constructor Chaining

Constructor chaining is the process of **calling one constructor from another** within the same class or between a subclass and its superclass. It helps in **reusing constructor logic**, **avoiding code duplication**, and maintaining consistency in object initialization.

There are two main types:

1. **Within the Same Class**  
   - One constructor calls another constructor in the same class to reuse common initialization logic.
   - In C++, this is done using **delegating constructors** (since C++11).
   - In Java, this is done using the `this()` keyword.

2. **Between Superclass and Subclass**  
   - A subclass constructor calls its superclass constructor to initialize inherited properties.
   - In C++, this is done via the initializer list.
   - In Java, this is done using the `super()` keyword.
---

### 🔹 Implicit Reference

**Definition:** When the object’s own members (variables or methods) are accessed **without explicitly using `this`**, it is called an implicit reference.

- The compiler understands that the method or variable belongs to the current object.
- Common when there is no naming conflict between parameters and member variables.

---

### 🔹 Explicit Reference

**Definition:** When we **explicitly use `this`** to refer to the current object inside a class.

- Used for disambiguation when method parameters shadow member variables.
- Common in method chaining or when passing the current object as an argument.

---

### 🔸 Summary Table

| Concept               | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| Constructor Chaining   | One constructor internally calls another to reuse initialization logic      |
| Implicit Reference     | Referring to object members without writing `this`                          |
| Explicit Reference     | Manually using `this` to refer to the current object                        |

### Q: What is the `new` keyword?

**Answer:**

The `new` keyword is used to **dynamically allocate memory** for an object or data in the **heap** at runtime.

---

### 🔹 In C++:

- Allocates memory manually.
- Returns a **pointer** to the allocated memory.
- Must be paired with `delete` to free memory and avoid leaks.

> Example: `MyClass* obj = new MyClass();`

---

### 🔹 In Java:

- Used to **instantiate objects** of a class.
- Memory management is handled by the **Garbage Collector**.
- No need for explicit deallocation.

> Example: `MyClass obj = new MyClass();`

---

### Q: What is an Interface?

**Answer:**

An **interface** is a contract that defines a set of methods that a class must implement, without specifying how those methods should work. It enables **abstraction**, promotes **loose coupling**, and supports **polymorphism** by allowing different classes to implement the same set of behaviors.

---

### 🔹 Key Characteristics

- Defines **what** a class should do, not **how**.
- Contains only **method declarations** (no implementation).
- Cannot be instantiated on its own.
- Classes use it to **guarantee** certain behaviors.

---

### 🔹 Java

- Uses the `interface` keyword.
- All methods are `public` and `abstract` by default.
- Can also contain `default` and `static` methods (Java 8+).
- Variables are implicitly `public static final`.
- Supports **multiple interface inheritance** using `implements`.

> Interfaces are commonly used in Java to define capabilities (e.g., `Runnable`, `Serializable`).

---

### 🔹 C++

- C++ does not have a separate `interface` keyword.
- Interface behavior is achieved using **abstract classes** with **pure virtual functions**.
- A class becomes an interface by declaring all functions as `virtual ... = 0`.
- C++ supports **multiple inheritance**, allowing a class to inherit from many such interfaces.

---

### 🔸 Summary

| Feature           | Java Interface                    | C++ Interface (Abstract Class)       |
|-------------------|------------------------------------|---------------------------------------|
| Keyword           | `interface`                        | `class` with pure virtual functions   |
| Implementation    | Via `implements`                   | Via `public` inheritance              |
| Multiple Inheritance | Supported                        | Supported                             |
| Instantiation     | Not allowed                        | Not allowed if class has pure virtual |
| Method Bodies     | `default` methods allowed (Java 8+) | Not allowed                           |

---

**Conclusion:**  
Interfaces are essential for designing scalable and modular systems. They separate **interface from implementation**, enabling flexibility, testability, and maintainability in object-oriented design.

### Additional Key Points about Interfaces (Not Previously Covered)

- **Interfaces = contract**, **Abstract class = partial implementation + contract**
- Interface variables are always `public static final` (constants).
- All interface methods are `public abstract` by default (pre-Java 8).
- Interfaces support **default** and **static** methods (Java 8+).
- Interfaces support **private methods** (Java 9+).
- A class can implement **multiple interfaces** (true multiple inheritance).
- Can use `InterfaceName.super.method()` to resolve method conflict.
- Interface default methods are also called **defender methods**.
- JVM uses **itable** (interface method table) for method resolution in interfaces.
- Interface method dispatch is slightly **slower** than class method dispatch (uses vtable).
- **to conclude: Interfaces define **capabilities**, not behavior.**

### Q: What is Polymorphism?

**Answer:**

Polymorphism is a core concept in object-oriented programming that allows the same function or operation to behave differently depending on the object it is acting upon. It enables one function name or method to work with different types of data or objects, depending on the context.

---

### 🔹 Core Idea:

“**One name, multiple behaviors**” — the same operation can be performed in different ways depending on the object’s actual type.

---

### 🔹 Importance of Polymorphism:

- Promotes **code reusability** and **extensibility**.
- Enables writing **generic and adaptable code**.
- Simplifies **code maintenance** by reducing duplication.
- Encourages focusing on **behavior**, not specific implementations.

---

### 🔸 Java-Specific Notes:

- In Java, all methods are **dynamically bound** by default.
- Polymorphism is commonly achieved using **method overriding** in class hierarchies.

---

**Conclusion:**  
Polymorphism allows the same operation to act differently on different objects, making object-oriented systems more modular, flexible, and easier to evolve.

### Q: What is Compile-Time Polymorphism?

**Answer:**

Compile-time polymorphism is a feature of object-oriented programming where a function or operator behaves differently based on the number or type of arguments, and this decision is made **during compilation**. It allows a single name to represent multiple behaviors that are resolved **before the program runs**, leading to faster execution and clearer code organization.

******(or)******

Compile-time polymorphism, also known as **static polymorphism**, refers to the ability of a program to resolve method or operator calls **at compile time**, based on the method signature or operand types. This form of polymorphism is achieved through **method overloading** and **operator overloading** (in C++), allowing multiple forms of a function or operator to coexist.

---

### 🔹 Method Overloading

Method overloading allows multiple methods to have the **same name** but differ in:
- Number of parameters
- Types of parameters
- Order of parameters

> Note: **Return type alone cannot be used** to distinguish overloaded methods.

#### Key Points:
- Enhances readability by grouping logically similar operations.
- The correct method is determined at **compile time** based on the arguments.

---

### 🔹 Operator Overloading (C++)

In C++, operators can be overloaded to extend their meaning when used with user-defined types (like classes). This allows for more intuitive and expressive code using custom logic with standard operators (e.g., `+`, `-`, `==`, etc.).

#### Rules and Limitations:
- Overloading does **not change the operator's syntax** or core meaning—only extends it.
- Cannot overload certain operators like:
  - `sizeof`, `typeid`, `::`, `.`, `.*`, `?:`  
  These are either resolved at compile time or involve non-overloadable behavior.

> Java does **not support operator overloading** (except for `+` used in string concatenation).

---

### 🔹 Mimicking Operator Overloading in Java

While Java lacks true operator overloading, similar behavior can be simulated using **method overloading**, particularly with methods like `add(int, int)` and `add(String, String)` to handle arithmetic and string operations respectively.

---

### ✅ Advantages of Compile-Time Polymorphism:

- **Improves code clarity** by using one name for multiple operations.
- **Faster execution**, as method resolution is done at compile time.
- **Better organization** of logically related operations.

---

### ❌ Disadvantages of Compile-Time Polymorphism:

- **Limited flexibility**: Cannot change behavior dynamically at runtime.
- **Hard to maintain**: Large numbers of overloaded methods can lead to complexity and potential confusion.
- **Restricted to method signature differences** only—cannot adapt to runtime object types.

---

### Summary:

Compile-time polymorphism allows multiple methods or operations with the same name to exist in a class, determined by differences in their **signatures** or **operand types**. It provides performance benefits but lacks the runtime adaptability of dynamic polymorphism.

### Q: What is Runtime Polymorphism?

**Answer:**

Runtime polymorphism (or dynamic method dispatch) is the ability of the program to decide **at runtime** which overridden method to invoke, based on the **actual type of the object**, not the reference type.

It is implemented using **method overriding**, where a subclass redefines a method from its superclass with the same signature. When a superclass reference points to a subclass object (via **upcasting**), the method call is dynamically resolved at runtime.

---

**Key Concepts:**

- **Achieved via overriding**: Method in subclass must match name, parameters, and return type.
- **Reference vs Object Type**: The method executed depends on the object type (`new`) — not the reference type.
- **Upcasting**: A superclass reference can refer to subclass objects, enabling runtime dispatch.
- **Virtual Method Table (JVM)**: Java uses internal tables (vtable/itable) to resolve method calls dynamically.
- **No runtime polymorphism for data members**: Only methods can be overridden, not variables.
- **Constructors are never overridden**.

---

**Rules and Constraints:**

- `private`, `static`, and `final` methods cannot be overridden → they use **static binding**.
- Method visibility can be increased (`protected` → `public`) but not reduced.
- Overridden method in subclass can:
  - Throw unchecked exceptions freely.
  - Throw checked exceptions only if compatible with the superclass method.
- **Covariant return types** are allowed — subclass method can return a subtype of the superclass method's return.

---

**Benefits:**

- Enables **true polymorphic behavior** at runtime.
- Supports **modularity** and **extensibility** via common superclass behavior.
- Makes code **flexible**, by allowing generalized method calls to adapt to object-specific implementations.

---

**Comparison:**

| Feature                     | Compile-time Polymorphism        | Runtime Polymorphism              |
|----------------------------|----------------------------------|-----------------------------------|
| Mechanism                  | Method Overloading               | Method Overriding                 |
| Resolution Time            | Compile-time                     | Runtime                           |
| Requires Inheritance       | No                               | Yes                               |
| Method Signature           | Must differ                      | Must match                        |
| Applicable to              | Static methods allowed           | Only instance (non-final, non-static) methods |
| Return Type Flexibility    | Can vary                         | Covariant (subclass allowed only) |

