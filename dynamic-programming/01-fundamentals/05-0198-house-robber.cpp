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
    int solve(int idx, vi &nums) {
        if (idx < 0)
            return 0;

        int take = nums[idx] + solve(idx - 2, nums);
        int notTake = solve(idx - 1, nums);
        return max(take, notTake);
    }

  public:
    int rob(vector<int> &nums) {
        return solve(sz(nums) - 1, nums);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
    int solve(int idx, vi &nums, vi &memo) {
        if (idx < 0)
            return 0;

        if (memo[idx] != -1)
            return memo[idx];

        int take = nums[idx] + solve(idx - 2, nums, memo);
        int notTake = solve(idx - 1, nums, memo);
        return memo[idx] = max(take, notTake);
    }

  public:
    int rob(vector<int> &nums) {
        vi memo(sz(nums), -1);
        return solve(sz(nums) - 1, nums, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = sz(nums);

        vi dp(n);
        dp[0] = nums[0];

        loop(i, 1, n) {
            updateMax(dp[i], nums[i] + (i > 1 ? dp[i - 2] : 0));
            updateMax(dp[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};
*/

/* Approach 4 (Space Optimization) (Greedy): */
class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = sz(nums);

        int prev1 = nums[0], prev2 = 0;
        loop(i, 1, n) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 1};
    println(obj.rob(v));
    v = {2, 7, 9, 3, 1};
    println(obj.rob(v));
}

/*
Problem: House Robber
*/