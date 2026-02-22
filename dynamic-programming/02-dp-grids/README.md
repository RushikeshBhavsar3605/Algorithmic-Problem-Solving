# 2D Grids & Multi-Dimensional DP: Quick Reference Playbook

Use this table to immediately pattern-match grid-based DP problems. The cardinal rule of grid DP in production: **You almost never need a full 2D/3D/4D matrix.** If the current state only depends on the immediate previous row or column, aggressively optimize your space complexity down by one dimension (e.g., `O(M*N)` to `O(N)`).

| The Problem (When to use)                                                                                                                      | The Pattern (How to solve)                                                                                                                                                                      | Code Reference                                              |
| :--------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------- |
| **Choice Restrictions (State Machines)**<br>Pick an action at each step, but you can't repeat the exact same action from the last step.        | **Last-State Tracking:** Keep a state variable for the "previous choice". `dp[idx][last_activity]`. Optimize to a 1D array of size `K` (where `K` = number of possible actions).                | `01-geeks-training.cpp`                                     |
| **Grid Path Counting**<br>Find total ways to reach the bottom-right of an `M x N` grid, with or without obstacles.                             | **Combinatorial DP:** `curr[col] += curr[col+1] + next[col]`. If obstacle, `curr[col] = 0`. Optimize space to a single 1D array `next` representing the row below/ahead.                        | `02-0062-unique-paths.cpp`<br>`03-0063-unique-paths-ii.cpp` |
| **Min/Max Path Sums**<br>Find the cheapest path through a grid or triangle moving right/down.                                                  | **Directional Minimization:** `dp[r][c] = grid[r][c] + min(right, down)`. For triangles, iterate bottom-up so you don't have to check bounds at the bottom edges.                               | `04-0064-minimum-path-sum...`<br>`05-0120-triangle.cpp`     |
| **Variable Start/End Points**<br>Fall from _any_ top cell to _any_ bottom cell (e.g., Min Falling Path).                                       | **Bottom-Up Row Roll:** Start at the second-to-last row. `dp[c] = grid[r][c] + min(down_left, down, down_right)`. Roll the row up until you hit row 0. Return the `min` of row 0.               | `06-0931-minimum-falling...`                                |
| **Multi-Agent / Simultaneous Movement**<br>Two entities traverse the grid at the same time, sharing state (e.g., collecting shared resources). | **Sync the Timestep:** Instead of sequential movement, move both together. For Cherry Pickup II (falling together), use `dp[row][col1][col2]`. Optimize space to `dp[col1][col2]`.              | `08-1463-cherry-pickup-ii.cpp`                              |
| **Round Trip Paths**<br>Go to the bottom-right, then come back to the top-left, picking up items.                                              | **Two-Forward Simulation:** A round trip is mathematically identical to two agents moving forward simultaneously. State: `dp[r1][c1][r2][c2]`. Avoid double counting if `r1 == r2 && c1 == c2`. | `07-0741-cherry-pickup.cpp`                                 |

## C++ STL Cheat Sheet

Syntax shortcuts for spinning up multi-dimensional spaces and grid moves:

**Initialize a 3D Memoization Table**

```cpp
// dimensions: n x m x m, initialized to -1
vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));
```

**Initialize a 4D Memoization Table (If absolutely necessary)**

```cpp
vector<vector<vector<vector<int>>>> memo(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
```

**Directional Arrays (For 4-way/8-way movement)**
When you need to explore neighbors without writing massive `if/else` chains:

```cpp
// right, down, left, up
int dRow[] = {0, 1, 0, -1};
int dCol[] = {1, 0, -1, 0};

for(int i = 0; i < 4; i++) {
    int newRow = row + dRow[i];
    int newCol = col + dCol[i];
    // check bounds, then transition
}
```
