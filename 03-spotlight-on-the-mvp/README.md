# Problem 3: Spotlight on the MVP

## Problem Statement
At the grand finals of the Array Arena Esports Championship, $N$ professional players stand in a single straight row on stage, indexed sequentially from left to right. Every player has a strictly unique performance rating $A[i]$ achieved during the season.

The player possessing the strictly highest rating is awarded the MVP (Most Valuable Player) award. The stage choreography requires positioning a dedicated spotlight directly on the MVP. To configure the lighting rigs and automated cameras, the stage coordinator needs to know:
1. The number of players standing strictly to the left of the MVP.
2. The number of players standing strictly to the right of the MVP.

Identify the MVP and output the count of players to their left and right.

---

## Input Format
- The first line contains an integer $N$ ($1 \le N \le 100\,000$) — the number of players.
- The second line contains $N$ space-separated integers $A[1], A[2], \dots, A[N]$ ($1 \le A[i] \le 10^9$) — the unique performance ratings of the players.

---

## Output Format
- Print two space-separated integers:
  `left_count right_count`
  representing the number of players to the left and to the right of the MVP, respectively.

---

## Constraints
- $1 \le N \le 100\,000$
- $1 \le A[i] \le 10^9$ for all $1 \le i \le N$
- All ratings $A[i]$ are guaranteed to be distinct.

---

## Sample Test Cases

### Sample 1
**Input:**
```text
4
10 40 20 30
```
**Output:**
```text
1 2
```
**Explanation:**
- The ratings are $[10, 40, 20, 30]$.
- The highest rating is $40$, situated at $0$-based index $1$.
- Players to the left: $[10]$ (count = $1$).
- Players to the right: $[20, 30]$ (count = $2$).
- The output is `1 2`.

### Sample 2
**Input:**
```text
5
50 40 30 20 10
```
**Output:**
```text
0 4
```
**Explanation:**
The MVP with rating $50$ stands at index $0$ (the far left). Thus, there are $0$ players to the left and $4$ players to the right.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. A single linear traversal through the array tracks the maximum rating and its $0$-based index `max_idx`. Once identified:
  $$\text{left} = \text{max\_idx}, \quad \text{right} = N - 1 - \text{max\_idx}$$
  This takes $\mathcal{O}(N)$ time and runs in under $10\text{ ms}$ for $N = 100\,000$.
- **Auxiliary Space Complexity:** $\mathcal{O}(1)$. Memory is minimal as elements can be processed in a streaming fashion by merely keeping track of the current maximum value and its index.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **Single Player ($N = 1$)** | Array has only 1 player | `0 0` |
| **MVP at Start ($i = 0$)** | MVP is at the far left | `0 (N - 1)` |
| **MVP at End ($i = N - 1$)** | MVP is at the far right | `(N - 1) 0` |
| **Large Ratings ($A[i] = 10^9$)** | Handled seamlessly with 64-bit integer types | Correct counts |
| **Maximum $N = 100\,000$** | High throughput streaming | Runs well within time limit |
