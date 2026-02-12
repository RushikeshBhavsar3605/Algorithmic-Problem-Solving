#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Recursion):
class Solution {
  private:
    int n, m;

    // Recursive DP to compute max cherries starting from:
    // - current row
    // - robot1 at col1
    // - robot2 at col2
    int solve(int row, int col1, int col2, vvi &grid) {
        // Boundary check: if any robot goes out of grid
        if (col1 < 0 || col1 == m || col2 < 0 || col2 == m)
            return INT_MIN;

        // Base case: last row
        // Collect cherries from both robots (avoid double count if same cell)
        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        // Store the maximum cherries possible from this state
        int maxi = 0;

        // Cherries collected at current row
        int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        // Try all 3 possible moves for both robots: left, down, right
        loop(dcol1, -1, 2) {
            loop(dcol2, -1, 2) {
                // Recurse to next row with updated columns
                int res = solve(row + 1, col1 + dcol1, col2 + dcol2, grid) + curr;

                // Update maximum result
                updateMax(maxi, res);
            }
        }

        return maxi;
    }

  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // Grid dimensions
        n = sz(grid), m = sz(grid[0]);

        // Start from row 0 with robots at columns 0 and m-1
        return solve(0, 0, m - 1, grid);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int n, m;

    // Memoized DP to compute max cherries starting from:
    // - current row
    // - robot1 at col1
    // - robot2 at col2
    int solve(int row, int col1, int col2, vvi &grid, vector<vvi> &memo) {
        // Boundary check: if any robot goes out of grid
        if (col1 < 0 || col1 == m || col2 < 0 || col2 == m)
            return INT_MIN;

        // Base case: last row
        // Collect cherries from both robots (avoid double count if same cell)
        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        // Return cached result if already computed
        if (memo[row][col1][col2] != -1)
            return memo[row][col1][col2];

        // Store the maximum cherries possible from this state
        int maxi = 0;

        // Cherries collected at current row
        int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        // Try all 3 possible moves for both robots: left, down, right
        loop(dcol1, -1, 2) {
            loop(dcol2, -1, 2) {
                int res = solve(row + 1, col1 + dcol1, col2 + dcol2, grid, memo) + curr;

                updateMax(maxi, res);
            }
        }

        return memo[row][col1][col2] = maxi;
    }

  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // Grid dimensions
        n = sz(grid), m = sz(grid[0]);

        // 3D memo table: row x col1 x col2
        vector<vvi> memo(n, vvi(m, vi(m, -1)));

        // Start from row 0 with robots at columns 0 and m-1
        return solve(0, 0, m - 1, grid, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // Grid dimensions
        int n = sz(grid), m = sz(grid[0]);

        // dp[row][col1][col2] = max cherries from (row, col1, col2)
        vector<vvi> dp(n, vvi(m, vi(m, -1)));

        // Base case: last row
        // Precompute cherries collected for all (col1, col2) pairs
        loop(col1, 0, m)
            loop(col2, 0, m) {
                if (col1 == col2)
                    dp[n - 1][col1][col2] = grid[n - 1][col1];
                else
                    dp[n - 1][col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
            }

        // Fill DP table bottom-up from second last row to top
        revloop(row, n - 2, 0)
            revloop(col1, m - 1, 0)
                revloop(col2, m - 1, 0) {
                    // Cherries collected at current row
                    int maxi = 0;
                    int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

                    // Try all 9 possible moves for both robots
                    loop(dcol1, -1, 2) {
                        loop(dcol2, -1, 2) {
                            int newCol1 = col1 + dcol1;
                            int newCol2 = col2 + dcol2;

                            // Skip invalid column positions
                            if (newCol1 < 0 || newCol1 == m || newCol2 < 0 || newCol2 == m)
                                continue;

                            // Transition to next row
                            int res = dp[row + 1][newCol1][newCol2] + curr;

                            // Update maximum
                            updateMax(maxi, res);
                        }
                    }

                    // Store result for current state
                    dp[row][col1][col2] = maxi;
                }

        // Starting position: row 0, robots at columns 0 and m-1
        return dp[0][0][m - 1];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        // Grid dimensions
        int n = sz(grid), m = sz(grid[0]);

        // Rolling DP arrays:
        // next -> DP values for row+1
        // curr -> DP values for current row
        vvi curr(m, vi(m, 0));
        vvi next(m, vi(m, 0));

        // Base case: last row
        // Initialize DP for all (col1, col2) pairs
        loop(col1, 0, m)
            loop(col2, 0, m) {
                if (col1 == col2)
                    next[col1][col2] = grid[n - 1][col1];
                else
                    next[col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
            }

        // Process rows from bottom to top
        revloop(row, n - 2, 0) {

            // Compute DP for current row
            revloop(col1, m - 1, 0)
                revloop(col2, m - 1, 0) {

                    // Cherries collected at current row
                    int maxi = 0;
                    int val = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

                    // Try all 9 possible moves for both robots
                    loop(dcol1, -1, 2) {
                        loop(dcol2, -1, 2) {
                            int newCol1 = col1 + dcol1;
                            int newCol2 = col2 + dcol2;

                            // Skip invalid column positions
                            if (newCol1 < 0 || newCol1 == m || newCol2 < 0 || newCol2 == m)
                                continue;

                            // Transition using next row DP
                            int res = next[newCol1][newCol2] + val;

                            // Update maximum
                            updateMax(maxi, res);
                        }
                    }

                    // Store result for current state
                    curr[col1][col2] = maxi;
                }

            // Move current row results to next for the next iteration
            next = curr;
        }

        // Starting position: row 0, robots at columns 0 and m-1
        return next[0][m - 1];
    }
};

int main() {
    Solution obj;
    vvi v = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    println(obj.cherryPickup(v));
    v = {{1, 0, 0, 0, 0, 0, 1},
         {2, 0, 0, 0, 0, 3, 0},
         {2, 0, 9, 0, 0, 0, 0},
         {0, 3, 0, 5, 4, 0, 0},
         {1, 0, 2, 3, 0, 0, 6}};
    println(obj.cherryPickup(v));
}

/*
Problem: Cherry Pickup II
*/