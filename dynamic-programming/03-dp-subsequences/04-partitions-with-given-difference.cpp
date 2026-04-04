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
    int MOD = 1e9 + 7;

    int solve(int idx, int target, vi nums) {
        if (target == 0)
            return 1;
        if (idx == sz(nums))
            return 0;

        int notTaken = solve(idx + 1, target, nums);
        int taken = 0;
        if (nums[idx] <= target)
            taken = solve(idx + 1, target - nums[idx], nums);

        return (notTaken + taken) % MOD;
    }

  public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = accumulate(all(arr), 0);
        int targetSum = (totalSum + d) >> 1;
        if ((totalSum + d) & 1)
            return 0;

        return solve(0, targetSum, arr);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int MOD = 1e9 + 7;

    int solve(int idx, int target, vi nums, vvi &memo) {
        if (idx == sz(nums))
            return target == 0 ? 1 : 0;

        if (memo[idx][target] != -1)
            return memo[idx][target];

        int notTaken = solve(idx + 1, target, nums, memo);
        int taken = 0;
        if (nums[idx] <= target)
            taken = solve(idx + 1, target - nums[idx], nums, memo);

        return memo[idx][target] = (notTaken + taken) % MOD;
    }

  public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = accumulate(all(arr), 0);
        int targetSum = (totalSum + d) >> 1;
        if ((totalSum + d) & 1)
            return 0;

        vvi memo(n, vi(targetSum + 1, -1));
        return solve(0, targetSum, arr, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  private:
    int MOD = 1e9 + 7;

  public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = accumulate(all(arr), 0);
        int targetSum = (totalSum + d) >> 1;
        if ((totalSum + d) & 1)
            return 0;

        vvi dp(n, vi(targetSum + 1, 0));
        dp[n - 1][0] = 1;
        if (arr[n - 1] <= targetSum)
            dp[n - 1][arr[n - 1]] += 1;

        revloop(idx, n - 2, 0) {
            loop(target, 0, targetSum + 1) {
                int notTaken = dp[idx + 1][target];
                int taken = 0;
                if (arr[idx] <= target)
                    taken = dp[idx + 1][target - arr[idx]];

                dp[idx][target] = (notTaken + taken) % MOD;
            }
        }

        return dp[0][targetSum];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  private:
    int MOD = 1e9 + 7;

  public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = accumulate(all(arr), 0);
        int targetSum = (totalSum + d) >> 1;
        if ((totalSum + d) & 1)
            return 0;

        vi curr(targetSum + 1, 0);
        vi next(targetSum + 1, 0);
        next[0] = 1;
        if (arr[n - 1] <= targetSum)
            next[arr[n - 1]] += 1;

        revloop(idx, n - 2, 0) {
            loop(target, 0, targetSum + 1) {
                int notTaken = next[target];
                int taken = 0;
                if (arr[idx] <= target)
                    taken = next[target - arr[idx]];

                curr[target] = (notTaken + taken) % MOD;
            }

            next = curr;
        }

        return next[targetSum];
    }
};

int main() {
    Solution obj;
    vi v = {5, 2, 6, 4};
    println(obj.countPartitions(4, 3, v));
    v = {1, 1, 1, 1};
    println(obj.countPartitions(4, 0, v));
    v = {4, 6, 3};
    println(obj.countPartitions(3, 1, v));
    v = {3, 1, 1, 2, 1};
    println(obj.countPartitions(5, 0, v));
    v = {3, 2, 2, 5, 1};
    println(obj.countPartitions(5, 1, v));
}

/*
Problem: Partitions With Given Difference
Link: https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
*/