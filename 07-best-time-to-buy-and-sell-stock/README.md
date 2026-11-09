# Problem 7: Best Time to Buy and Sell Stock

## Problem Statement
You are given an array `prices` of size $N$, where `prices[i]` represents the price of a given stock on the $i$-th day ($0$-indexed).

You want to maximize your profit by choosing **a single day to buy** one stock and choosing **a different day in the future to sell** that stock (i.e., $\text{buy\_day} < \text{sell\_day}$).

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit (for example, if stock prices only decline or remain flat), output `0`.

---

## Input Format
- The first line contains an integer $N$ ($1 \le N \le 100\,000$) — the number of days.
- The second line contains $N$ space-separated integers $\text{prices}[0], \text{prices}[1], \dots, \text{prices}[N - 1]$ ($0 \le \text{prices}[i] \le 10^4$) — the stock prices on each consecutive day.

---

## Output Format
- Print a single integer representing the maximum profit achievable from at most one buy and one sell transaction.

---

## Constraints
- $1 \le N \le 100\,000$
- $0 \le \text{prices}[i] \le 10^4$ for all $0 \le i < N$

---

## Sample Test Cases

### Sample 1
**Input:**
```text
6
7 1 5 3 6 4
```
**Output:**
```text
5
```
**Explanation:**
- Buy on Day 1 (0-indexed: price = 1)
- Sell on Day 4 (0-indexed: price = 6)
- Profit = $6 - 1 = 5$.
- Note that buying on day 1 and selling on day 0 is not permitted because selling must occur strictly after buying.

### Sample 2
**Input:**
```text
5
7 6 4 3 1
```
**Output:**
```text
0
```
**Explanation:**
In this case, no transaction yields a positive profit. The optimal choice is to make no transactions, resulting in a maximum profit of $0$.

---

## Algorithmic Strategy
This is the classic single-pass greedy / dynamic programming problem.
- We maintain the minimum price seen so far: $\text{min\_price}$.
- For each subsequent day $i \in [1, N - 1]$:
  1. The potential profit if selling on day $i$ is $\text{prices}[i] - \text{min\_price}$.
  2. We update the global maximum profit: $\text{max\_profit} = \max(\text{max\_profit}, \text{prices}[i] - \text{min\_price})$.
  3. We update the minimum price: $\text{min\_price} = \min(\text{min\_price}, \text{prices}[i])$.
- If $N \le 1$, no valid pair of days exists, so the answer is $0$.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. A single traversal through the array updates both running variables in $\mathcal{O}(1)$ per element. For $N = 100\,000$, execution takes $< 5\text{ ms}$.
- **Auxiliary Space Complexity:** $\mathcal{O}(1)$. Requires only two scalar variables ($\text{min\_price}$ and $\text{max\_profit}$) with no additional memory allocation.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **Single Day ($N = 1$)** | Cannot buy and sell on distinct days | `0` |
| **Strictly Decreasing** | Prices drop every day (e.g., `[5, 4, 3, 2, 1]`) | `0` |
| **Strictly Increasing** | Prices rise every day (e.g., `[1, 2, 3, 4, 5]`) | `4` ($\text{prices}[N-1] - \text{prices}[0]$) |
| **All Prices Equal** | Zero volatility (e.g., `[3, 3, 3, 3]`) | `0` |
| **Zero Prices** | Stock priced at 0 (e.g., `[0, 10, 0, 5]`) | `10` |
| **Max Scale ($N = 100\,000$)** | Handled with fast I/O | Runs within $\approx 5\text{ ms}$ |
