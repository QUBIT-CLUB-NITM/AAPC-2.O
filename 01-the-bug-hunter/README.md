# Problem 1: The Bug Hunter

## Problem Statement
A microservice monitoring daemon logs an array of $N$ HTTP response status codes. The engineering team has observed intermittent connection dropouts caused by a routing failure that emits an HTTP `404` (Not Found) status code.

Your mission as the bug hunter is to analyze the sequence of HTTP status codes and determine if the anomaly `404` was logged at any point.

Output `1` if `404` appears anywhere in the array; otherwise, output `0`.

---

## Input Format
- The first line contains an integer $N$ ($1 \le N \le 100$) representing the number of status codes logged.
- The second line contains $N$ space-separated integers $A[1], A[2], \dots, A[N]$ ($100 \le A[i] \le 599$) representing the logged HTTP status codes.

---

## Output Format
- Print a single integer: `1` if the array contains `404`, or `0` otherwise.

---

## Constraints
- $1 \le N \le 100$
- $100 \le A[i] \le 599$ for all $1 \le i \le N$

---

## Sample Test Cases

### Sample 1
**Input:**
```text
5
200 201 500 404 200
```
**Output:**
```text
1
```
**Explanation:**
The element `404` appears at the 4th position. Hence, the output is `1`.

### Sample 2
**Input:**
```text
3
200 200 200
```
**Output:**
```text
0
```
**Explanation:**
All status codes are `200`. The code `404` is absent, so the output is `0`.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. A single sequential scan through the array of size $N$ is sufficient. With $N \le 100$, the loop executes in under a microsecond ($\ll 1.0\text{ s}$).
- **Auxiliary Space Complexity:** $\mathcal{O}(1)$. Requires only a boolean flag and loop variables; elements can be processed on the fly without retaining extra memory.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **Minimum size ($N = 1$), Target present** | Array is `[404]` | `1` |
| **Minimum size ($N = 1$), Target absent** | Array is `[200]` | `0` |
| **First element is target** | Array starts with `404 ...` | `1` |
| **Last element is target** | Array ends with `... 404` | `1` |
| **Multiple targets** | Array contains multiple `404` occurrences | `1` |
| **All targets** | Array consists only of `404` | `1` |
