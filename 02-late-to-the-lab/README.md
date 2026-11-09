# Problem 2: Late to the Lab

## Problem Statement
The computer science laboratory conducts an automated morning attendance check for its 8:00 AM practical session. The security mechanism locks the laboratory door at precisely $T$ minutes past 8:00 AM. 

There are $N$ students scheduled for the session. The $i$-th student arrives at $A[i]$ minutes past 8:00 AM. 
A student is granted entry if they arrive at or before the door locks ($A[i] \le T$). Any student arriving **strictly after** the locking threshold ($A[i] > T$) is barred from entry and classified as late.

Determine the total number of students who are late to the lab.

---

## Input Format
- The first line contains two space-separated integers $N$ and $T$ ($1 \le N \le 100\,000$, $0 \le T \le 120$) — the number of students and the threshold minute.
- The second line contains $N$ space-separated integers $A[1], A[2], \dots, A[N]$ ($0 \le A[i] \le 120$) — the arrival minute of each student past 8:00 AM.

---

## Output Format
- Print a single integer representing the number of students arriving strictly after minute $T$.

---

## Constraints
- $1 \le N \le 100\,000$
- $0 \le T \le 120$
- $0 \le A[i] \le 120$ for all $1 \le i \le N$

---

## Sample Test Cases

### Sample 1
**Input:**
```text
6 15
5 10 15 16 20 12
```
**Output:**
```text
2
```
**Explanation:**
The threshold minute is $T = 15$.
The arrival times are:
- $5 \le 15$ (On time)
- $10 \le 15$ (On time)
- $15 \le 15$ (On time — arrived precisely as door locked)
- $16 > 15$ (Late)
- $20 > 15$ (Late)
- $12 \le 15$ (On time)

A total of $2$ students arrived strictly after minute $15$.

### Sample 2
**Input:**
```text
4 0
0 5 10 15
```
**Output:**
```text
3
```
**Explanation:**
The door locks at minute $T = 0$. Only the student arriving at minute $0$ is on time. The remaining $3$ students are late.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. We perform a single iteration across the $N$ student arrival times. Since $N \le 100\,000$, this takes $\approx 5\text{–}15\text{ ms}$, well within the typical $1.0\text{ s}$ limit.
- **Auxiliary Space Complexity:** $\mathcal{O}(1)$. The arrivals can be counted streaming directly from standard input without requiring dynamic array allocations.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **Exact Arrival on Threshold ($A[i] = T$)** | Student arrives at minute $T$ | Counted as on time (not late) |
| **Immediate Lock ($T = 0$)** | Door locks immediately at 8:00 AM | Any $A[i] > 0$ counted as late |
| **Generous Threshold ($T = 120$)** | Door locks at end of period | No one is late since $A[i] \le 120$ |
| **All Students Late** | Every $A[i] > T$ | Output is $N$ |
| **No Students Late** | Every $A[i] \le T$ | Output is $0$ |
| **Large Scale ($N = 100\,000$)** | Maximum allowed input size | Requires fast I/O routines |
