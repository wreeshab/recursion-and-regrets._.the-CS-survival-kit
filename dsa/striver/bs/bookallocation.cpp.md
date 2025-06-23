### What if `studentCount < students`?

- If you finish allocating all books and have used **fewer** than the given number of students, that's totally fine!
- It means the current `mid` value (max pages per student) is **large enough** that some students may not even need any books.
- The condition to fail feasibility is **only** when `studentCount > students`.
- So having fewer students than available means the allocation is **feasible**.

---

### In short:

- If `studentCount <= students` after allocation, then the allocation **is feasible**.
- If `studentCount > students`, allocation is **not feasible**.
