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
    int MOD = 1e9+7;

    int solve(int idx, int target, vi &arr) {
        if (idx == sz(arr))
            return target == 0 ? 1 : 0;

        int notTaken = solve(idx + 1, target, arr);

        int taken = 0;
        if (arr[idx] <= target)
            taken = solve(idx + 1, target - arr[idx], arr);

        return (notTaken + taken) % MOD;
    }

  public:
    int findWays(vector<int> &arr, int k) {
        return solve(0, k, arr);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int MOD = 1e9 + 7;

    int solve(int idx, int target, vi &arr, vvi &memo) {
        if (idx == sz(arr))
            return target == 0 ? 1 : 0;

        if (memo[idx][target] != -1)
            return memo[idx][target];

        int notTaken = solve(idx + 1, target, arr, memo);

        int taken = 0;
        if (arr[idx] <= target)
            taken = solve(idx + 1, target - arr[idx], arr, memo);

        return memo[idx][target] = (notTaken + taken) % MOD;
    }

  public:
    int findWays(vector<int> &arr, int k) {
        vvi memo(sz(arr), vi(k + 1, -1));
        return solve(0, k, arr, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int findWays(vector<int> &arr, int k) {
        int MOD = 1e9 + 7, n = sz(arr);
        vvi dp(n, vi(k + 1, 0));

        dp[n - 1][0] = 1;
        if (arr[n - 1] <= k)
            dp[n - 1][arr[n - 1]] = 1;

        revloop(idx, n - 2, 0) {
            loop(target, 0, k + 1) {
                int notTaken = dp[idx + 1][target];

                int taken = 0;
                if (arr[idx] <= target)
                    taken = dp[idx + 1][target - arr[idx]];

                dp[idx][target] = (notTaken + taken) % MOD;
            }
        }

        return dp[0][k];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int findWays(vector<int> &arr, int k) {
        int MOD = 1e9 + 7, n = sz(arr);
        vi curr(k + 1, 0);
        vi next(k + 1, 0);

        next[0] = 1;
        if (arr[n - 1] <= k)
            next[arr[n - 1]] = 1;

        revloop(idx, n - 2, 0) {
            loop(target, 0, k + 1) {
                int notTaken = next[target];

                int taken = 0;
                if (arr[idx] <= target)
                    taken = next[target - arr[idx]];

                curr[target] = (notTaken + taken) % MOD;
            }

            next = curr;
        }

        return next[k];
    }
};

int main() {
    Solution obj;
    vi v = {1, 4, 4, 5};
    println(obj.findWays(v, 5));
    v = {1, 1, 1};
    println(obj.findWays(v, 2));
    v = {2, 34, 5};
    println(obj.findWays(v, 40));
    v = {12, 14, 3, 18, 2};
    println(obj.findWays(v, 13));
}

/*
Problem: Count Subsets with Sum K
Link: https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
*/