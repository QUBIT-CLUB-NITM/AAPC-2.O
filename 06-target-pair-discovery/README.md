# Problem 6: Target Pair Discovery

## Problem Statement
In a distributed telemetry indexing cluster, you are provided with an array $A$ of $N$ integers and a specific target value $T$.

Your objective is to identify two distinct elements at 1-based indices $i$ and $j$ ($1 \le i < j \le N$) such that their sum equals the target:
$$A[i] + A[j] = T$$

### Tie-Breaking Rules
If there are multiple pairs of indices $(i, j)$ satisfying the condition, select the pair that:
1. **Minimizes the first index $i$**.
2. If multiple valid pairs share the same minimal $i$, **minimizes the second index $j$**.

If no such pair exists, print `-1 -1`.

---

## Input Format
- The first line contains two space-separated integers $N$ and $T$ ($2 \le N \le 200\,000$, $-10^9 \le T \le 10^9$) — the number of elements and the target sum.
- The second line contains $N$ space-separated integers $A[1], A[2], \dots, A[N]$ ($-10^9 \le A[i] \le 10^9$).

---

## Output Format
- Print two space-separated integers representing the 1-based indices $i$ and $j$ ($1 \le i < j \le N$).
- If no pair of indices sums to $T$, print `-1 -1`.

---

## Constraints
- $2 \le N \le 200\,000$
- $-10^9 \le T \le 10^9$
- $-10^9 \le A[i] \le 10^9$ for all $1 \le i \le N$

---

## Sample Test Cases

### Sample 1
**Input:**
```text
5 9
2 7 11 15 3
```
**Output:**
```text
1 2
```
**Explanation:**
- For $i = 1$, $A[1] = 2$. The required complement is $T - A[1] = 9 - 2 = 7$.
- At index $j = 2$, $A[2] = 7$.
- The sum is $A[1] + A[2] = 2 + 7 = 9$ with $1 < 2$.
- Because $i = 1$ is the smallest possible index, this pair satisfies the tie-breaking condition. Output `1 2`.

### Sample 2
**Input:**
```text
4 10
1 2 3 4
```
**Output:**
```text
-1 -1
```
**Explanation:**
No pair of elements sums up to 10. Output `-1 -1`.

---

## Algorithmic Strategy
To satisfy the condition of minimizing $i$ first and then $j$:
1. We iterate index $i$ sequentially from $1$ to $N - 1$.
2. For each fixed $i$, the required complement is $\text{comp} = T - A[i]$.
3. We query whether the complement exists at any index $j > i$, and if multiple such indices exist, select the minimum $j > i$.
4. The very first index $i$ that finds a match is guaranteed to have the minimum $i$, and taking the minimum $j > i$ guarantees the minimal $j$. We print `i j` and immediately terminate.
5. If the search completes across all $i$ without finding a valid complement, we print `-1 -1`.

By preprocessing the array with a sorted list of `(value, index)` pairs or a value-to-indices hash table, each query takes $\mathcal{O}(\log N)$ or $\mathcal{O}(1)$ time.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N \log N)$ or $\mathcal{O}(N)$ expected.
  - Sorting `(value, index)` takes $\mathcal{O}(N \log N)$.
  - For each $i \in [1, N]$, binary searching for the complement range and finding the smallest index $> i$ takes $\mathcal{O}(\log N)$.
  - With $N = 200\,000$, execution completes in $\approx 50\text{–}100\text{ ms}$, comfortably within standard time limits.
- **Auxiliary Space Complexity:** $\mathcal{O}(N)$ to store original values and their 1-based positions.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **No Solution Exists** | No pair sums to target | `-1 -1` |
| **Duplicate Values Form Target** | E.g., $A = [3, 3], T = 6$ | `1 2` (both occurrences used) |
| **Negative Values & Target** | $A = [-5, 2, 7], T = 2 \implies -5 + 7 = 2$ | `1 3` |
| **Multiple Valid Pairs** | $A = [1, 5, 2, 4], T = 6 \implies (1, 5)$ and $(2, 4)$ | `1 2` (smaller $i$) |
| **Multiple Targets for Same $i$** | $A = [2, 7, 7], T = 9 \implies (1, 2)$ and $(1, 3)$ | `1 2` (smaller $j$) |
| **64-bit Integer Overflow** | $T - A[i]$ where $T, A[i] \approx \pm 10^9$ | Fits in 64-bit `long long` / `long` |
