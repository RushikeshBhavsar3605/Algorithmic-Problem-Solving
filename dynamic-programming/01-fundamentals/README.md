# 1D Dynamic Programming & Fundamentals: Quick Reference Playbook

Use this table to immediately pattern-match the problem to the state transition and grab the code. In production, always default to the `O(1)` space optimization when the state depends only on a fixed window of previous states (like a rolling cache).

| The Problem (When to use)                                                                                                                  | The Pattern (How to solve)                                                                                                                             | Code Reference                                          |
| :----------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------ |
| **Fixed-Window Transitions**<br>Next state depends strictly on the last 1 or 2 states (e.g., Fibonacci, Climbing Stairs).                  | **Space-Optimized DP:** Drop the `O(N)` array. Use two variables (`prev1`, `prev2`) to roll the state forward. `O(N)` time, `O(1)` space.              | `01-0509-fibonacci...`<br>`02-0070-climbing-stairs.cpp` |
| **Take vs. Not Take (Non-Adjacent)**<br>Maximize/minimize sums without picking adjacent elements.                                          | **1D DP Recurrence:** `curr = max(prev1, prev2 + nums[i])`. Again, optimize to `O(1)` space using a sliding two-variable window.                       | `05-0198-house-robber.cpp`                              |
| **Circular Array Constraints**<br>Same as above, but the first and last elements are adjacent.                                             | **Break the Loop:** Run the linear DP algorithm twice. Once from index `0` to `n-2`, and once from `1` to `n-1`. Return the `max()` of both.           | `06-0213-house-robber-ii.cpp`                           |
| **Sparse Jump States**<br>Transitions depend on dynamic values (like jump size) rather than fixed indices, creating a massive state space. | **Hash Map + 2D DP:** Use an `unordered_map` to map sparse values to indices. State becomes `dp[index][jump_size]`.                                    | `03-0403-frog-jump.cpp`                                 |
| **Greedy Over DP**<br>Problem looks like DP but asks for bottleneck minimization over uniform paths.                                       | **Greedy Array Scan:** Sometimes a DP recurrence simplifies mathematically. Jump skipping exactly one element: `max(result, stones[i] - stones[i-2])`. | `04-2498-frog-jump-ii.cpp`                              |

## C++ STL Cheat Sheet

Syntax shortcuts for spinning up DP tables quickly and cleanly:

**Initialize a 1D Memoization Table**

```cpp
// Fill with -1 (Standard for "uncomputed")
vector<int> memo(n + 1, -1);
```

**Initialize a 2D DP/Memo Table**

```cpp
// size n x m initialized to -1
vector<vector<int>> memo(n, vector<int>(m, -1));
```

**Clean Max/Min Updates (Macro style)**
If you are doing heavy state transitions, custom macros keep the code scannable:

```cpp
#define updateMax(a, b) (a = max(a, b))
// Usage inside loops:
updateMax(dp[i], nums[i] + dp[i - 2]);
```
