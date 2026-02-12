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
    int solve(int row, int col, vvi &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        if (row >= n || col >= m || grid[row][col] == 1)
            return 0;
        if (row == n - 1 && col == m - 1)
            return 1;

        return solve(row + 1, col, grid) + solve(row, col + 1, grid);
    }

  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        return solve(0, 0, obstacleGrid);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
    int solve(int row, int col, vvi &grid, vvi &memo) {
        int n = sz(grid);
        int m = sz(grid[0]);

        if (row >= n || col >= m || grid[row][col] == 1)
            return 0;

        if (row == n - 1 && col == m - 1)
            return 1;

        if (memo[row][col] != -1)
            return memo[row][col];

        return memo[row][col] = solve(row + 1, col, grid, memo) + solve(row, col + 1, grid, memo);
    }

  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = sz(obstacleGrid);
        int m = sz(obstacleGrid[0]);

        vvi memo(n, vi(m, -1));
        return solve(0, 0, obstacleGrid, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int MOD = INT_MAX;
        int n = sz(obstacleGrid);
        int m = sz(obstacleGrid[0]);

        vvi dp(n, vi(m, 0));
        dp[n - 1][m - 1] = 1;

        revloop(row, n - 1, 0) {
            revloop(col, m - 1, 0) {
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }

                if (row < n - 1)
                    dp[row][col] = ((ll)dp[row][col] + dp[row + 1][col]) % MOD;
                if (col < m - 1)
                    dp[row][col] = ((ll)dp[row][col] + dp[row][col + 1]) % MOD;
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int MOD = INT_MAX;
        int n = sz(obstacleGrid);
        int m = sz(obstacleGrid[0]);

        vi next(m, 0);
        next[m - 1] = 1;

        revloop(row, n - 1, 0) {
            vi curr(m, 0);

            revloop(col, m - 1, 0) {
                if (obstacleGrid[row][col] == 1) {
                    next[col] = 0;
                    continue;
                }

                curr[col] = ((ll)curr[col] + next[col]) % MOD;
                if (col < m - 1)
                    curr[col] = ((ll)curr[col] + curr[col + 1]) % MOD;
            }

            next = curr;
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    println(obj.uniquePathsWithObstacles(v));
    v = {{0, 1}, {0, 0}};
    println(obj.uniquePathsWithObstacles(v));
}

/*
Problem: Unique Paths II
*/