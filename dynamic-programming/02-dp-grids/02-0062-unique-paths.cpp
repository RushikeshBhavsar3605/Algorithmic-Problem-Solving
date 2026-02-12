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
    int solve(int row, int col, int m, int n) {
        if (row == m - 1 && col == n - 1)
            return 1;
        else if (row == m || col == n)
            return 0;

        int right = solve(row, col + 1, m, n);
        int bottom = solve(row + 1, col, m, n);

        return right + bottom;
    }

  public:
    int uniquePaths(int m, int n) {
        return solve(0, 0, m, n);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int row, int col, int m, int n, vvi &memo) {
        if (row == m - 1 && col == n - 1)
            return 1;
        else if (row == m || col == n)
            return 0;

        if (memo[row][col] != -1)
            return memo[row][col];

        int right = solve(row, col + 1, m, n, memo);
        int bottom = solve(row + 1, col, m, n, memo);

        return memo[row][col] = right + bottom;
    }

  public:
    int uniquePaths(int m, int n) {
        vvi memo(m, vi(n, -1));
        return solve(0, 0, m, n, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int uniquePaths(int m, int n) {
        vvi dp(m, vi(n, 0));
        dp[m - 1][n - 1] = 1;

        revloop(row, m - 1, 0) {
            revloop(col, n - 1, 0) {
                vvi neighbors = {{row, col + 1}, {row + 1, col}};

                iterate(it, neighbors) {
                    int newRow = it[0];
                    int newCol = it[1];

                    if (newRow == m || newCol == n)
                        continue;

                    dp[row][col] += dp[newRow][newCol];
                }
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 4 (Optimized Tabulation):
class Solution {
  public:
    int uniquePaths(int m, int n) {
        vvi dp(m, vi(n, 0));
        dp[m - 1][n - 1] = 1;

        revloop(row, m - 1, 0) {
            revloop(col, n - 1, 0) {
                if (row < m - 1)
                    dp[row][col] += dp[row + 1][col];
                if (col < n - 1)
                    dp[row][col] += dp[row][col + 1];
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 5 (Space Optimization): */
class Solution {
  public:
    int uniquePaths(int m, int n) {
        vi next(n, 0);
        next[n - 1] = 1;

        revloop(row, m - 1, 0) {
            vi curr(n, 0);

            revloop(col, n - 1, 0) {
                curr[col] += next[col];
                if (col < n - 1)
                    curr[col] += curr[col + 1];
            }

            next = curr;
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    println(obj.uniquePaths(3, 7));
    println(obj.uniquePaths(3, 2));
}

/*
Problem: Unique Paths
*/