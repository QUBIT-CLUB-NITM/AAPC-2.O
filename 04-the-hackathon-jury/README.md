# Problem 4: The Hackathon Jury

## Problem Statement
At an international engineering hackathon, $N$ teams (numbered $1$ to $N$) showcase their projects to an evaluation panel of $3$ industry judges. Each judge reviews the projects and assigns an integer score between $0$ and $100$ to each team. If a judge was unable to evaluate a specific team, they submit a score of `-1`.

However, the organizers enforce strict jury integrity guidelines:
1. **Invalid Judge Filter:** A judge who assigns `-1` to **all $N$ teams** is deemed inactive/invalid, and their entire scorecard is discarded from the scoring pipeline.
2. **Team Average Computation:** For each team, their official score is the arithmetic mean of all evaluations submitted for them by **valid** judges. If a valid judge marked `-1` for that team, that rating is excluded from both the sum and the count of evaluations.
3. **Unevaluated Teams:** If a team receives no evaluations from any valid judge, their official average score is $0$.
4. **Winner Selection & Tie-Breaking:** The team with the highest average score is declared the winner. If multiple teams are tied for the highest average score, the team with the smallest 1-indexed ID wins.

Determine the 1-indexed ID of the winning team.

---

## Input Format
- The first line contains an integer $N$ ($1 \le N \le 1000$) — the number of teams.
- The next $3$ lines each contain $N$ space-separated integers representing the evaluation scores given by Judge 1, Judge 2, and Judge 3 respectively. Each score is an integer between $-1$ and $100$.

---

## Output Format
- Print a single integer representing the 1-indexed ID of the winning team.

---

## Constraints
- $1 \le N \le 1000$
- $-1 \le \text{Score} \le 100$

---

## Sample Test Cases

### Sample 1
**Input:**
```text
3
-1 -1 -1
80 90 -1
70 -1 95
```
**Output:**
```text
3
```
**Explanation:**
- Judge 1 assigned `-1 -1 -1`. Since all $N=3$ scores are `-1`, Judge 1 is invalid and discarded.
- Judge 2 and Judge 3 both assigned valid scores and are retained.
- **Team 1:** Evaluated by Judge 2 (80) and Judge 3 (70). Valid ratings = 2. Average = $\frac{80 + 70}{2} = 75.0$.
- **Team 2:** Evaluated by Judge 2 (90). Judge 3 did not evaluate. Valid ratings = 1. Average = $\frac{90}{1} = 90.0$.
- **Team 3:** Evaluated by Judge 3 (95). Judge 2 did not evaluate. Valid ratings = 1. Average = $\frac{95}{1} = 95.0$.
- The maximum average is $95.0$, achieved by Team 3. The output is `3`.

### Sample 2
**Input:**
```text
2
50 50
-1 -1
-1 -1
```
**Output:**
```text
1
```
**Explanation:**
- Judges 2 and 3 are discarded because all their entries are `-1`.
- Judge 1 gave 50 to Team 1 and 50 to Team 2.
- Both teams have an average of 50.0. The tie is broken by selecting the smaller team ID: Team 1.

---

## Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$. Inspecting 3 rows of $N$ scores takes $3 \times N$ operations. Filtering judges takes $\mathcal{O}(N)$ operations, and calculating team averages takes $\mathcal{O}(N)$ operations. For $N = 1000$, this executes in $< 1\text{ ms}$.
- **Auxiliary Space Complexity:** $\mathcal{O}(N)$. A $3 \times N$ score matrix or three arrays of length $N$ can store the input scores.

---

## Edge Case Breakdown
| Edge Case | Description | Expected Output |
| :--- | :--- | :--- |
| **All Judges Inactive** | All 3 judges assign `-1` across all teams | Every team has average 0; output is `1` (smallest ID) |
| **No Judges Evaluated a Team** | Valid judges exist, but a team was skipped by all | Team has average 0; loses to any team with average $> 0$ |
| **Tie with Average = 0** | Multiple teams unevaluated or scored 0 | Smallest team ID among tied candidates wins |
| **Floating-Point Precision** | E.g., $\frac{100}{3} \approx 33.333\dots$ vs $\frac{66}{2} = 33.0$ | Exact cross-multiplication integer arithmetic ($S_i \cdot C_b > S_b \cdot C_i$) prevents precision errors |
| **Minimum Teams ($N = 1$)** | Single team | Output is `1` |
