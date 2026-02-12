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
    int solve(int level, int idx, vvi &triangle) {
        if (level == sz(triangle))
            return 0;

        int down = solve(level + 1, idx, triangle) + triangle[level][idx];
        int diagonal = solve(level + 1, idx + 1, triangle) + triangle[level][idx];

        return min(down, diagonal);
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        return solve(0, 0, triangle);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int level, int idx, vvi &triangle, vvi &memo) {
        if (level == sz(triangle))
            return 0;

        if (memo[level][idx] != INT_MIN)
            return memo[level][idx];

        int down = solve(level + 1, idx, triangle, memo) + triangle[level][idx];
        int diagonal = solve(level + 1, idx + 1, triangle, memo) + triangle[level][idx];

        return memo[level][idx] = min(down, diagonal);
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vvi memo(sz(triangle), vi(sz(triangle), INT_MIN));
        return solve(0, 0, triangle, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = sz(triangle);
        vvi dp(n, vi(n, 0));

        loop(i, 0, n)
            dp[n - 1][i] = triangle[n - 1][i];

        revloop(level, n - 2, 0) {
            revloop(idx, level, 0) {
                int down = dp[level + 1][idx];
                int diagonal = dp[level + 1][idx + 1];

                dp[level][idx] = triangle[level][idx] + min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 4 (Space Optimization):
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = sz(triangle);
        vi next = triangle[n - 1];

        revloop(level, n - 2, 0) {
            vi curr(level + 1, 0);

            revloop(idx, level, 0) {
                int down = next[idx];
                int diagonal = next[idx + 1];

                curr[idx] = triangle[level][idx] + min(down, diagonal);
            }

            next = curr;
        }

        return next[0];
    }
};
*/

/* Approach 5 (Most Optimal): */
class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = sz(triangle);
        vi dp(n + 1, 0);

        revloop(level, n - 1, 0)
            loop(idx, 0, level + 1)
                dp[idx] = triangle[level][idx] + min(dp[idx], dp[idx + 1]);

        return dp[0];
    }
};

int main() {
    Solution obj;
    vvi v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    println(obj.minimumTotal(v));
    v = {{-10}};
    println(obj.minimumTotal(v));
}

/*
Problem: Triangle
*/