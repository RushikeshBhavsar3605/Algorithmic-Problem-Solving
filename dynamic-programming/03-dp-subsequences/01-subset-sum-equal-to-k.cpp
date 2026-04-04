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
    bool solve(int idx, int n, int target, vi &arr) {
        if (target == 0)
            return true;
        if (idx == n)
            return false;

        bool notTaken = solve(idx + 1, n, target, arr);

        bool taken = false;
        if (arr[idx] <= target)
            taken = solve(idx + 1, n, target - arr[idx], arr);

        return notTaken || taken;
    }

  public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        return solve(0, n, k, arr);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    bool solve(int idx, int n, int target, vi &arr, vvi &memo) {
        if (target == 0)
            return true;
        if (idx == n)
            return false;

        if (memo[idx][target] != -1)
            return memo[idx][target];

        bool notTaken = solve(idx + 1, n, target, arr, memo);

        bool taken = false;
        if (arr[idx] <= target)
            taken = solve(idx + 1, n, target - arr[idx], arr, memo);

        return memo[idx][target] = notTaken || taken;
    }

  public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vvi memo(n, vi(k + 1, -1));
        return solve(0, n, k, arr, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vvi dp(n, vi(k + 1, 0));

        loop(idx, 0, n)
            dp[idx][0] = true;

        if (arr[n - 1] <= k)
            dp[n - 1][arr[n - 1]] = true;

        revloop(idx, n - 2, 0) {
            loop(target, 1, k + 1) {
                bool notTaken = dp[idx + 1][target];

                bool taken = false;
                if (arr[idx] <= target)
                    taken = dp[idx + 1][target - arr[idx]];

                dp[idx][target] = notTaken || taken;
            }
        }

        return dp[0][k];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vi curr(k + 1, 0);
        vi next(k + 1, 0);

        next[0] = true;
        if (arr[n - 1] <= k)
            next[arr[n - 1]] = true;

        revloop(idx, n - 2, 0) {
            curr[0] = true;

            loop(target, 1, k + 1) {
                bool notTaken = next[target];

                bool taken = false;
                if (arr[idx] <= target)
                    taken = next[target - arr[idx]];

                curr[target] = notTaken || taken;
            }

            next = curr;
        }

        return next[k];
    }
};

int main() {
    Solution obj;
    vi v = {4, 3, 2, 1};
    println(obj.subsetSumToK(4, 5, v));
    v = {2, 5, 1, 6, 7};
    println(obj.subsetSumToK(5, 4, v));
}

/*
Problem: Subset Sum Equal To K
Link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
*/