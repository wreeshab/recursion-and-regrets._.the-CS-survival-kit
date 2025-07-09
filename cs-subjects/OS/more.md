### Q. How and Where Are the Different Parts of a Process Stored in Memory?

When a process is loaded into memory, the OS organizes it into **distinct memory segments**. Each segment has a specific role in storing code, data, and variables.

---

### Memory Layout of a Process:

| Segment       | Contents                                      | Location in Memory (Typical Order)        |
|---------------|-----------------------------------------------|--------------------------------------------|
| **Text**      | Executable program code (instructions)         | Lowest address (read-only segment)         |
| **Data**      | Global and static variables (initialized)      | After text segment                         |
| **BSS**       | Uninitialized global/static variables          | After data segment                         |
| **Heap**      | Dynamically allocated memory (`malloc`, `new`) | Grows **upward** towards the stack         |
| **Stack**     | Local variables, function calls, return info   | Grows **downward** from top of address space |

---

### Description of Each:

1. **Text Segment (Code):**
   - Contains the actual **compiled instructions** of the program.
   - Usually marked **read-only** to prevent modification.

2. **Data Segment:**
   - Stores **global and static variables** that are **explicitly initialized**.

3. **BSS Segment:**
   - Holds **uninitialized** global and static variables.
   - The OS initializes this memory to **zero** before use.

4. **Heap:**
   - Used for **dynamic memory allocation** during runtime.
   - Managed manually via `malloc/free` (C) or `new/delete` (C++).

5. **Stack:**
   - Stores **function call frames**, **local variables**, and **return addresses**.
   - Managed automatically using **LIFO** principle.

---

### Summary:

| Part         | Stored In        | Notes                            |
|--------------|------------------|----------------------------------|
| Code         | Text segment     | Read-only, executable            |
| Global/static| Data/BSS segment | Allocated at program start       |
| Heap memory  | Heap             | Grows upward, needs manual mgmt  |
| Local vars   | Stack            | Grows downward, auto-managed     |

The OS and CPU work together to manage and protect these regions, ensuring isolation and safety.
