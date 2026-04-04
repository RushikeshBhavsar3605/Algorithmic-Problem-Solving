# DP on Subsequences & Knapsack Variants: Quick Reference Playbook

Use this table to immediately pattern-match subset/knapsack DP problems. The cardinal rule of subsequence DP in production: **You almost never need the full 2D table.** If the current row only reads from the immediate next/previous row, collapse it to two 1D arrays (`curr` and `next`) and halve your memory. For unbounded problems, collapse further to a single 1D array — but only when you're certain the read direction is safe.

| The Problem (When to use)                                                                                                                                        | The Pattern (How to solve)                                                                                                                                                                                                                                                     | Code Reference                                                             |
| :--------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------- |
| **Existence / Feasibility**<br>Can _any_ subset achieve exactly the target sum? Items are used at most once.                                                     | **Boolean DP:** `dp[target] = notTaken \|\| taken`. Base case: `dp[0] = true`. Space-optimize to two 1D `bool` arrays rolling `next → curr`. Short-circuit early if you find `true`.                                                                                           | `01-subset-sum-equal-to-k.cpp`<br>`02-0416-partition-equal-subset-sum.cpp` |
| **Count Subsets (Exact Sum)**<br>How many distinct subsets sum to exactly K? Items are used at most once.                                                        | **Additive DP:** `dp[target] = notTaken + taken`, add MOD. Base case: `dp[0] = 1`. Critical edge case: if the array contains zeros, the `dp[n-1][0]` initialization can double-count — handle with `+= 1` instead of `= 1` for the last element.                               | `03-count-subsets-with-sum-k.cpp`                                          |
| **Count Subsets via Math Reduction**<br>Count partitions where `S1 − S2 = D`, or assign `+/−` signs to hit a target. Negative sums make direct DP infeasible.    | **Algebraic Collapse:** Derive `S1 = (totalSum + D) / 2` and reduce to "count subsets with sum S1". Guard: if `(totalSum + D)` is odd or `D > totalSum`, return 0 immediately. For signed targets, shift the sum axis by `offset = totalSum` to keep indices non-negative.     | `04-partitions-with-given-difference.cpp`<br>`09-0494-target-sum.cpp`      |
| **0/1 Knapsack (Maximize Value)**<br>Pick items to maximize total value without exceeding a weight budget. Each item is used at most once.                       | **Max-Value DP:** `dp[w] = max(notTake, take + val[idx])`. Base: fill `prev[w] = val[0]` for all `w >= wt[0]`. Space-optimize with `swap(prev, curr)` per row. Read from `prev` to avoid using the same item twice.                                                            | `05-0-1-knapsack-problem.cpp`                                              |
| **Unbounded Knapsack — Minimize**<br>Reach an exact target using the fewest items. Each denomination can be reused any number of times.                          | **Unbounded Min DP:** `take = dp[idx][rem − coin] + 1` (same `idx`, not `idx−1` — this is what makes it unbounded). Sentinel: initialize infeasible states to `INT_MAX`; guard `take != INT_MAX` before adding 1 to avoid overflow.                                            | `06-0322-coin-change.cpp`<br>`08-0322-coin-change.cpp`                     |
| **Unbounded Knapsack — Count Combinations**<br>Count the number of ways to form a target using coins with unlimited supply. Order doesn't matter (combinations). | **Unbounded Count DP:** `take = dp[idx][target − coin]` (same `idx`). Base: `dp[0][i] = 1` if `i % coins[0] == 0`. Iterate forward over `target` within each `idx`. Distinct from permutation counting — do not iterate `idx` in the inner loop.                               | `10-0518-coin-change-ii.cpp`                                               |
| **Greedy Assignment**<br>Optimally match two sorted lists — satisfy as many "needs" as possible with available "resources". No benefit from DP here.             | **Two-Pointer Greedy:** Sort both arrays. Use one pointer per array: advance the _child_ pointer only on a successful match, always advance the _cookie_ pointer. Final child pointer value is the answer. Memoization/tabulation also work but add unnecessary `O(n·m)` cost. | `07-0455-assign-cookies.cpp`                                               |

---

## C++ STL Cheat Sheet

Syntax shortcuts for the patterns used across these problems:

**Rolling Two-Array Space Optimization (0/1 Knapsack)**

```cpp
// Standard curr/next roll — safe for 0/1 (each item once)
vec<int> prev(W + 1, 0), curr(W + 1, 0);
loop(i, wt[0], W + 1) prev[i] = val[0];   // base case

loop(idx, 1, n) {
    loop(maxWt, 0, W + 1) {
        int notTake = prev[maxWt];
        int take = (wt[idx] <= maxWt) ? prev[maxWt - wt[idx]] + val[idx] : 0;
        curr[maxWt] = max(notTake, take);
    }
    swap(prev, curr);
}
// Answer in prev[W]
```

**Unbounded Read (Same-Row Self-Reference)**

```cpp
// For coin change / unbounded knapsack:
// Reading curr[rem - coin] instead of prev[rem - coin]
// allows re-using the same item at the current index.
revloop(idx, n - 1, 0) {
    loop(rem, 0, amount + 1) {
        int take = INT_MAX;
        if (coins[idx] <= rem && curr[rem - coins[idx]] != INT_MAX)
            take = curr[rem - coins[idx]] + 1;   // curr, not next
        curr[rem] = min(take, next[rem]);
    }
    swap(curr, next);
}
```

**Math Reduction Template (Partition / Target Sum)**

```cpp
// Both "partitions with difference D" and "target sum" reduce here:
int totalSum = accumulate(all(arr), 0);
if ((totalSum + target) & 1) return 0;          // odd → impossible
if (abs(target) > totalSum)  return 0;          // out of range
int S1 = (totalSum + target) / 2;               // count subsets summing to S1
```

**Sentinel Pattern for Minimization DP**

```cpp
// Use INT_MAX - 1 (not INT_MAX) to safely add 1 without overflow:
const int INF = INT_MAX - 1;
vec<int> dp(amount + 1, INF);
dp[0] = 0;
// ...
if (take != INF) updateMin(dp[rem], take + 1);
// Return: dp[amount] < INF ? dp[amount] : -1;
```

**Offset Trick for Negative Sum Indices**

```cpp
// When curr sum can be negative (Target Sum problem):
int offset = totalSum;  // shift so index 0 = sum of -totalSum
vec<int> dp(2 * totalSum + 1, 0);
dp[target + offset] = 1;  // base case at shifted index

// Access: dp[curr + offset]  where curr ∈ [-totalSum, totalSum]
```
