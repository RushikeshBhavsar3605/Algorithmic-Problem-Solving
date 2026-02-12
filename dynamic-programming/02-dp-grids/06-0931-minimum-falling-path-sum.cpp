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
    int solve(int row, int col, vvi &matrix) {
        int n = sz(matrix);
        if (row == n)
            return 0;

        int left = INT_MAX, middle = INT_MAX, right = INT_MAX;

        middle = solve(row + 1, col, matrix) + matrix[row][col];
        if (col > 0)
            left = solve(row + 1, col - 1, matrix) + matrix[row][col];
        if (col < n - 1)
            right = solve(row + 1, col + 1, matrix) + matrix[row][col];

        return min({left, middle, right});
    }

  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = sz(matrix);
        int mini = INT_MAX;

        loop(i, 0, n)
            updateMin(mini, solve(0, i, matrix));

        return mini;
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int row, int col, vvi &matrix, vvi &memo) {
        int n = sz(matrix);
        if (row == n)
            return 0;
        if (memo[row][col] != INT_MIN)
            return memo[row][col];

        int left = INT_MAX, middle = INT_MAX, right = INT_MAX;

        middle = solve(row + 1, col, matrix, memo) + matrix[row][col];
        if (col > 0)
            left = solve(row + 1, col - 1, matrix, memo) + matrix[row][col];
        if (col < n - 1)
            right = solve(row + 1, col + 1, matrix, memo) + matrix[row][col];

        return memo[row][col] = min({left, middle, right});
    }

  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = sz(matrix);
        int mini = INT_MAX;
        vvi memo(n, vi(n, INT_MIN));

        loop(i, 0, n)
            updateMin(mini, solve(0, i, matrix, memo));

        return mini;
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = sz(matrix);

        vvi dp(n, vi(n, 0));
        dp[n - 1] = matrix[n - 1];

        revloop(row, n - 2, 0) {
            loop(col, 0, n) {
                int left = INT_MAX, middle = INT_MAX, right = INT_MAX;
                middle = dp[row + 1][col] + matrix[row][col];
                if (col > 0)
                    left = dp[row + 1][col - 1] + matrix[row][col];
                if (col < n - 1)
                    right = dp[row + 1][col + 1] + matrix[row][col];

                dp[row][col] = min({left, middle, right});
            }
        }

        int mini = INT_MAX;
        loop(i, 0, n)
            updateMin(mini, dp[0][i]);

        return mini;
    }
};
*/

/* Approach 4 (Space Optimation): */
class Solution {
  public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = sz(matrix);

        vi next = matrix[n - 1];

        revloop(row, n - 2, 0) {
            vi curr(n, 0);

            loop(col, 0, n) {
                int left = INT_MAX, middle = INT_MAX, right = INT_MAX;

                middle = next[col] + matrix[row][col];
                if (col > 0)
                    left = next[col - 1] + matrix[row][col];
                if (col < n - 1)
                    right = next[col + 1] + matrix[row][col];

                curr[col] = min({left, middle, right});
            }

            next = curr;
        }

        int mini = INT_MAX;
        iterate(it, next)
            updateMin(mini, it);

        return mini;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    println(obj.minFallingPathSum(v));
    v = {{-19, 57}, {-40, -5}};
    println(obj.minFallingPathSum(v));
}

/*
Problem: Minimum Falling Path Sum
*/