# Prefix & Suffix Arrays: Quick Reference Playbook

Use this table to immediately pattern-match the problem to the solution and grab the code.

| The Problem (When to use)                                                                                             | The Pattern (How to solve)                                                                                                                                                                            | Code Reference               |
| :-------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------- |
| **Static Range Queries**<br>Need to repeatedly calculate the sum of elements between indices `[L, R]` in `O(1)` time. | **Prefix Sum Array:** Precompute running totals. `prefixSum[i+1] = prefixSum[i] + nums[i]`. <br>Result: `sum(L, R) = prefixSum[R+1] - prefixSum[L]`.                                                  | `02-0303-range-sum...`       |
| **Equilibrium / Pivot Finding**<br>Find an index where the sum of the left side equals the right side.                | **Optimized Running Sum:** Compute `totalSum` upfront. As you iterate, subtract `nums[i]` from `rightSum`. Compare `leftSum == rightSum`. Add `nums[i]` to `leftSum`. `O(N)` time, `O(1)` space.      | `03-0724-find-pivot...`      |
| **Subarrays with Divisibility**<br>Find the longest subarray whose sum is divisible by `K`.                           | **Prefix Sum + Hash Map:** Track the running prefix sum modulo `K`. Store the first seen index of each remainder. If you see the same remainder again, the subarray between them is divisible by `K`. | `10-longest-subarray...`     |
| **Vertical String Matching**<br>Find the longest common prefix among an array of strings.                             | **Column-by-Column Scan:** Take the first string as a baseline. Iterate through its characters (columns) and compare against the same index in all other strings (rows). Stop on mismatch.            | `01-0014-longest-common...`  |
| **Substring Identification**<br>Find all strings that are a substring of another string in an array.                  | **Nested Iteration:** Check if string A fits into string B by iterating through B's starting indices. _(Note: Can be optimized via KMP/Rabin-Karp for massive datasets)._                             | `04-1408-string-matching...` |

## C++ STL Cheat Sheet

Syntax shortcuts for production-level prefix and string operations:

**Fast Total Sum (accumulate)**

```cpp
#include <numeric>
int totalSum = accumulate(nums.begin(), nums.end(), 0);
// Note: use 0LL if sums can exceed INT_MAX
```

**Handling Negative Modulo (Crucial for Divisibility Patterns)**
C++ handles modulo on negative numbers awkwardly (returns a negative). Always normalize it:

```cpp
int remainder = (prefixSum % k + k) % k;
```

**String Substring Search (Built-in alternative to manual loops)**

```cpp
if (mainStr.find(subStr) != string::npos) {
    // subStr exists within mainStr
}
```
