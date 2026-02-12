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
    int solve(int row, int col, vvi &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        if (row == n - 1 && col == m - 1)
            return grid[row][col];

        int down = INT_MAX, right = INT_MAX;
        if (row < n - 1)
            down = solve(row + 1, col, grid) + grid[row][col];
        if (col < m - 1)
            right = solve(row, col + 1, grid) + grid[row][col];

        return min(down, right);
    }

  public:
    int minPathSum(vector<vector<int>> &grid) {
        return solve(0, 0, grid);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int row, int col, vvi &grid, vvi &memo) {
        int n = sz(grid);
        int m = sz(grid[0]);

        if (row == n - 1 && col == m - 1)
            return grid[row][col];

        if (memo[row][col] != -1)
            return memo[row][col];

        int down = INT_MAX, right = INT_MAX;
        if (row < n - 1)
            down = solve(row + 1, col, grid, memo) + grid[row][col];
        if (col < m - 1)
            right = solve(row, col + 1, grid, memo) + grid[row][col];

        return memo[row][col] = min(down, right);
    }

  public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        vvi memo(n, vi(m, -1));
        return solve(0, 0, grid, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        vvi dp(n, vi(m, 0));
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        revloop(row, n - 1, 0) {
            revloop(col, m - 1, 0) {
                if (row == n - 1 && col == m - 1)
                    continue;

                int down = grid[row][col], right = grid[row][col];
                down = row < n - 1 ? down + dp[row + 1][col] : INT_MAX;
                right = col < m - 1 ? right + dp[row][col + 1] : INT_MAX;

                dp[row][col] = min(down, right);
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        vi next(m, 0);

        revloop(row, n - 1, 0) {
            vi curr(m, 0);

            revloop(col, m - 1, 0) {
                if (row == n - 1 && col == m - 1) {
                    curr[col] = grid[row][col];
                    continue;
                }

                int down = grid[row][col], right = grid[row][col];
                down = row < n - 1 ? down + next[col] : INT_MAX;
                right = col < m - 1 ? right + curr[col + 1] : INT_MAX;

                curr[col] = min(down, right);
            }

            next = curr;
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    println(obj.minPathSum(v));
    v = {{1, 2, 3}, {4, 5, 6}};
    println(obj.minPathSum(v));
}

/*
Problem: Minimum Path Sum
*/