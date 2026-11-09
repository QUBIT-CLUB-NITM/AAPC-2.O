# Problem 5: Constrained Data Cleanup

## Problem Statement
A high-performance in-memory cache holds an array of $N$ distinct telemetry readings: $A[1], A[2], \dots, A[N]$. During system stabilization, an automated maintenance worker is dispatched to purge all legacy telemetry, preserving **only the maximum element** in the array.

The cleanup engine operates under the following architectural constraints:
1. In a single atomic operation, the worker can select any contiguous subarray of size at most $K$ that **does not contain the maximum element** and delete it from memory.
2. When a subarray is deleted, the remaining segments before and after it close the gap to form a single continuous array.

Your objective is to compute the **minimum number of operations** required to completely eradicate all elements except the maximum element.

---

## Input Format
- The first line contains two space-separated integers $N$ and $K$ ($1 \le K \le N \le 1\,000\,000$) — the total number of telemetry records and the maximum subarray deletion capacity per operation.
- The second line contains $N$ space-separated integers $A[1], A[2], \dots, A[N]$ ($1 \le A[i] \le 10^9$) — the unique telemetry values.

---

## Output Format
- Print a single integer representing the minimum number of cleanup operations needed.

---

## Constraints
- $1 \le K \le N \le 1\,000\,000$
- $1 \le A[i] \le 10^9$ for all $1 \le i \le N$
- All values in $A$ are strictly distinct.

---

## Sample Test Cases

### Sample 1
**Input:**
```text
7 2
1 2 3 100 4 5 6
```
**Output:**
```text
4
```
**Explanation:**
- The elements are $[1, 2, 3, 100, 4, 5, 6]$ and $K = 2$.
- The maximum element is $100$ located at index 3 (0-based).
- Elements to the left of 100: $[1, 2, 3]$ (count $L = 3$).
- Elements to the right of 100: $[4, 5, 6]$ (count $R = 3$).
- Because no operation may contain the maximum element ($100$), an operation cannot bridge across the left and right sides.
- Removing $L = 3$ elements with chunks of size at most $2$ requires $\lceil 3 / 2 \rceil = 2$ operations.
- Removing $R = 3$ elements with chunks of size at most $2$ requires $\lceil 3 / 2 \rceil = 2$ operations.
- Total minimum operations: $2 + 2 = 4$.

### Sample 2
**Input:**
```text
5 3
50 10 20 30 40
```
**Output:**
```text
2
```
**Explanation:**
- The maximum is $50$ at index 0 ($L = 0$).
- To the right: $[10, 20, 30, 40]$ ($R = 4$).
- Deleting $4$ elements with chunk size at most $3$ requires $\lceil 4 / 3 \rceil = 2$ operations.
- Total operations: $0 + 2 = 2$.

---

## Mathematical Formulation
Let $L$ be the number of elements situated strictly before the maximum element, and let $R = N - 1 - L$ be the number of elements situated strictly after it.

Because no deletion operation can cover the maximum element:
- The left segment of $L$ elements must be cleared independently using deletions of size $\le K$. The minimum number of operations is:
  $$\text{ops}_L = \left\lceil \frac{L}{K} \right\rceil = \left\lfloor \frac{L + K - 1}{K} \right\rfloor$$
- Similarly, the right segment of $R$ elements requires:
  $$\text{ops}_R = \left\lceil \frac{R}{K} \right\rceil = \left\lfloor \frac{R + K - 1}{K} \right\rfloor$$
- The overall minimum number of operations is:
  $$\text{Total Operations} = \text{ops}_L + \text{ops}_R$$

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. Finding the position of the maximum element requires a single pass over $N$ items. With $N = 1\,000\,000$, streaming I/O processes the input in $\approx 0.05\text{–}0.15\text{ s}$, easily passing the typical $1.0\text{–}2.0\text{ s}$ limit.
- **Auxiliary Space Complexity:** $\mathcal{O}(1)$. The maximum and its index can be tracked on the fly as numbers are read, requiring zero array storage.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **No Elements to Delete ($N = 1$)** | Single element array | `0` operations |
| **Maximum at First Index ($L = 0$)** | Maximum is at position 0 | $\lceil (N - 1) / K \rceil$ |
| **Maximum at Last Index ($R = 0$)** | Maximum is at position $N - 1$ | $\lceil (N - 1) / K \rceil$ |
| **Unit Chunk Size ($K = 1$)** | Only 1 element can be removed per op | $N - 1$ operations |
| **Huge Capacity ($K \ge N$)** | $K$ exceeds remaining elements | $1$ op for left (if $L > 0$) + $1$ op for right (if $R > 0$) |
| **Maximum Input Scale ($N = 1\,000\,000$)** | Up to $10^6$ elements | Handled via streaming $O(1)$ memory |
