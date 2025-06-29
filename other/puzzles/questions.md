## Puzzle: Paying an Employee with 7 Units of Gold

### Problem Statement:
You have an employee who works for you for **7 days**. You must pay them **1 unit of gold at the end of each day**.

You have a single **gold bar of 7 units**, and you are allowed to make **only 2 cuts** in the bar.  
Design a strategy to pay the worker **exactly 1 unit per day**, using **at most 2 cuts**.

---

### Answer:

Make 2 cuts to divide the gold bar into segments of sizes: **1, 2, and 4** units.  
(These sizes allow all values from 1 to 7 to be formed using binary combinations.)

#### Daily Payment Plan:

| Day | Action                          | Gold With Worker |
|-----|----------------------------------|------------------|
| 1   | Give 1                           | 1                |
| 2   | Take back 1, give 2              | 2                |
| 3   | Give 1                           | 3                |
| 4   | Take back 1 & 2, give 4          | 4                |
| 5   | Give 1                           | 5                |
| 6   | Take back 1, give 2              | 6                |
| 7   | Give 1                           | 7                |

This uses only **2 cuts**, and ensures the worker receives **exactly 1 unit of gold per day**.

## Puzzle: Fastest 3 Horses

### Problem Statement:
You have **25 horses** and **no stopwatch**. You can race **only 5 horses at a time**, and only learn their **relative rankings** (1st to 5th) in each race.

Find the **minimum number of races** needed to determine the **top 3 fastest horses overall**.

---

### Answer:

**Minimum races required: `7`**

#### Strategy:

1. **Race all 25 horses in 5 groups** of 5 each → **5 races**  
   Label the horses by group and position (e.g., A1, A2, ..., E5) where A1 is 1st in group A.

2. **Race all the winners** of each group (A1, B1, ..., E1) → **1 race**  
   - Suppose the result is: A1 > B1 > C1 > D1 > E1  
   - So A1 is the fastest overall. Now consider only candidates that could be in the top 3.

3. **Final (7th) race**:  
   Race these 5 horses:
   - **A2, A3 (2nd & 3rd from group A)**
   - **B1, B2 (2nd from group B)**
   - **C1 (3rd from group C)**
   (Only these can possibly be in top 3, based on prior eliminations.)

   Top 2 in this race, along with A1, are the overall **top 3 horses**.

---
**Total Races: 5 (initial) + 1 (winners) + 1 (final) = 7**


## Puzzle: Anesthesia Injection with 5 Rats in 48 Hours

### Problem:
You have **240 injections**, one contains **anesthesia**.  
You have only **5 rats** and **48 hours**.  
A rat will faint **within 24h** of receiving the poisoned injection.  
Find the poisoned injection using the rats efficiently.

---

### Solution: **Ternary Encoding**

- Represent each injection as a **5-digit base-3 number** (since 3⁵ = 243 ≥ 240).
- Each **rat represents one digit** (from left to right).
- Digit meaning:
  - `0` → Do not inject
  - `1` → Inject on **Day 1**
  - `2` → Inject on **Day 2**
- After 48 hours, each rat can be in one of 3 states:
  - **Alive** → 0
  - **Fainted on Day 1** → 1
  - **Fainted on Day 2** → 2

---

### Example:

**Injection #11201** (in base-3) is poisoned.

Digits (rat-wise): `1 1 2 0 1`  
→ Actions:

| Rat # | Digit | Action        |
|-------|--------|----------------|
| 1     | 1      | Inject Day 1   |
| 2     | 1      | Inject Day 1   |
| 3     | 2      | Inject Day 2   |
| 4     | 0      | No injection   |
| 5     | 1      | Inject Day 1   |

After 48h:
- Rats 1, 2, 5 fainted after Day 1 → digits = 1
- Rat 3 fainted after Day 2 → digit = 2
- Rat 4 alive → digit = 0

So fainting pattern = `1 1 2 0 1` → Injection #11201 is poisoned.

---

### Max Supported:  
**3⁵ = 243 injections** can be tested this way.


## Puzzle: 3 Bulbs and 3 Switches

Turn on switch 1, wait a while, turn it off; turn on switch 2 and enter the room—**the bulb that's on is switch 2, the warm off bulb is switch 1, the cold off bulb is switch 3**.


## Puzzle: 3000 Bananas and a Camel

### Problem:
- You have **3000 bananas** to transport across **1000 km**.
- A camel can carry **1000 bananas max**, and **eats 1 banana/km walked**, whether loaded or not.
- Goal: **Maximize bananas delivered** at the destination.

---

### ✅ Answer (Normal Case): **533 bananas**

#### Strategy:
Use **2 intermediate drop points** to minimize loss during back-and-forth trips.

Let:
- `x` = distance from **Source to IP1**
- `y` = distance from **IP1 to IP2**
- `z` = distance from **IP2 to Destination**

**Step 1:**  
From Source to IP1 (3 loads, 5 trips/km):  
`3000 - 5x = 2000` → `x = 200`

**Step 2:**  
From IP1 to IP2 (2 loads, 3 trips/km):  
`2000 - 3y = 1000`  
Ideal solution gives `y = 333.33`, but distance must be integer  
→ Use `y = 333`  
Then: `2000 - 3×333 = 1001` bananas at IP2  
(One banana discarded as camel can carry only 1000)

**Step 3:**  
Remaining distance to destination:  
`z = 1000 - x - y = 1000 - 200 - 333 = 467`  
Camel eats 467 bananas

Final bananas at destination:  
`1000 - 467 = 533`

---

### ✅ Alternate Case (Camel eats only when carrying): **833 bananas**

- From Source to 333 km: 3 trips → drop **667 bananas/trip**, total at IP1 = **2001 bananas**
- From IP1 to 833 km (500 km): 2 trips → drop **500 bananas/trip**, total at IP2 = **1000**
- From IP2 to destination (167 km): 1 trip, eats 167

Final bananas at destination:  
`1000 - 167 = 833`

---

### Summary:

| Case                              | Max Bananas Delivered |
|-----------------------------------|------------------------|
| Camel eats on **every trip**      | **533**                |
| Camel eats **only when carrying** | **833**                |

## Puzzle: Find the Jar with Contaminated Pills

### Problem:
You have **10 jars**, each containing **identical-looking pills**.  
- Each pill weighs exactly **10g**, except one jar, which contains **contaminated pills** weighing **9g** each.
- You can use a **weighing scale only once**.
- Identify the jar with contaminated pills.

---

### ✅ Solution:

1. Number the jars **1 to 10**.
2. Take pills as follows:
   - Take **1 pill from Jar 1**
   - Take **2 pills from Jar 2**
   - ...
   - Take **10 pills from Jar 10**

Total pills = `1 + 2 + ... + 10 = 55 pills`

3. Weigh all 55 pills together.

- If all were 10g pills, total weight = `55 × 10 = 550g`
- Let’s say the actual weight is `W`
- Then:  
  `550 - W = x` → The **difference** tells which jar is contaminated  
  (because each contaminated pill is **1g lighter**)

✅ **Answer:** The contaminated jar is **Jar x**

---

### Example:
- Suppose scale shows `547g`
- Difference = `550 - 547 = 3`
- → Contaminated pills are from **Jar 3**

## Puzzle: 100 Prisoners with Red/Black Hats

### Goal:
Maximize the number of prisoners saved (each sees hats in front, not own or behind).

---

### ✅ Strategy (Parity of Red Hats):

- **100th prisoner** (last in line) counts red hats in front.
  - Says **"Red"** if count is even, **"Black"** if odd.
  - Has a 50% chance to survive, but sets a **parity baseline**.

- **Each next prisoner (99 to 1)**:
  - Counts red hats ahead.
  - Compares with previous parity to deduce their own hat color.

### ✅ Result:
- **At most 99 prisoners are guaranteed to be saved**.
- Only the 100th prisoner has a 50/50 chance.


## Puzzle: 10 Coins and a Blindfold

### Problem:
You have **10 coins**, with **5 heads** and **5 tails**, randomly arranged.  
You're **blindfolded** and can **flip coins**, but **can’t see** or feel their state.  
**Goal:** Split the coins into **2 groups** with **equal number of heads**.

---

### ✅ Solution:

1. **Randomly pick any 5 coins**.
2. **Flip all 5**.

Now, both groups (the flipped 5 and the remaining 5) have **equal number of heads**.

---

### 🔍 Why It Works:
- Suppose selected group had **x heads**, **5−x tails**.
- After flipping: **x tails**, **5−x heads**.
- Remaining group still has **(5−x) heads**.

✅ So both groups now have exactly **(5−x) heads**.
