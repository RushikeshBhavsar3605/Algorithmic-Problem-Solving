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
    int solve(int row, int col, vvi &grid, int k, int sum = 0) {
        int n = sz(grid), m = sz(grid[0]);
        if (row == n - 1 && col == m - 1)
            return (sum + grid[row][col]) % k == 0 ? 1 : 0;
        if (row == n || col == m)
            return 0;

        int right = solve(row, col + 1, grid, k, sum + grid[row][col]);
        int down = solve(row + 1, col, grid, k, sum + grid[row][col]);

        return right + down;
    }

  public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        return solve(0, 0, grid, k);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int MOD = 1e9 + 7;

    int solve(int row, int col, vvi &grid, int k, vector<vector<vector<int>>> &memo, int sum = 0) {
        int n = sz(grid), m = sz(grid[0]);
        if (row == n - 1 && col == m - 1)
            return (sum + grid[row][col]) % k == 0 ? 1 : 0;
        if (row == n || col == m)
            return 0;

        int remainder = sum % k;
        if (memo[row][col][remainder] != -1)
            return memo[row][col][remainder];

        int newSum = sum + grid[row][col];
        int right = solve(row, col + 1, grid, k, memo, newSum);
        int down = solve(row + 1, col, grid, k, memo, newSum);

        return memo[row][col][remainder] = (right + down) % MOD;
    }

  public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int n = sz(grid), m = sz(grid[0]);

        vector<vector<vector<int>>> memo(n, vvi(m, vi(k, -1)));
        return solve(0, 0, grid, k, memo);
    }
};
*/

/*Approach 3 (Tabulation):
class Solution {
  public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int MOD = 1e9 + 7;
        int n = sz(grid), m = sz(grid[0]);

        vector<vector<vector<int>>> dp(n, vvi(m, vi(k, 0)));
        dp[n - 1][m - 1][grid[n - 1][m - 1] % k] = 1;

        revloop(row, n - 1, 0) {
            revloop(col, m - 1, 0) {
                loop(remainder, 0, k) {
                    int currRemainder = (remainder + grid[row][col]) % k;

                    if (col != m - 1)
                        dp[row][col][currRemainder] = (dp[row][col][currRemainder] + dp[row][col + 1][remainder]) % MOD;

                    if (row != n - 1)
                        dp[row][col][currRemainder] = (dp[row][col][currRemainder] + dp[row + 1][col][remainder]) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int MOD = 1e9 + 7;
        int n = sz(grid), m = sz(grid[0]);

        vvi curr(m, vi(k, 0));
        vvi next(m, vi(k, 0));

        revloop(row, n - 1, 0) {
            fill(all(curr), vi(k, 0));

            revloop(col, m - 1, 0) {
                if (row == n - 1 && col == m - 1) {
                    curr[col][grid[row][col] % k] = 1;
                    continue;
                }

                loop(remainder, 0, k) {
                    int currRemainder = (remainder + grid[row][col]) % k;

                    if (col != m - 1)
                        curr[col][currRemainder] = (curr[col][currRemainder] + curr[col + 1][remainder]) % MOD;

                    if (row != n - 1)
                        curr[col][currRemainder] = (curr[col][currRemainder] + next[col][remainder]) % MOD;
                }
            }

            swap(curr, next);
        }

        return next[0][0];
    }
};

int main() {
    Solution obj;
    vvi v = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    println(obj.numberOfPaths(v, 3));
    v = {{0, 0}};
    println(obj.numberOfPaths(v, 5));
}

/*
Problem: Paths in Matrix Whose Sum Is Divisible by K
*/