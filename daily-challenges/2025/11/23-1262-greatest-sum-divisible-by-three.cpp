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
    int solve(int idx, int rem, vi &nums) {
        if (idx == sz(nums)) {
            return (rem == 0) ? 0 : INT_MIN;
        }

        int include = solve(idx + 1, (rem + nums[idx]) % 3, nums) + nums[idx];
        int exclude = solve(idx + 1, rem, nums);

        return max(include, exclude);
    }

  public:
    int maxSumDivThree(vector<int> &nums) {
        return solve(0, 0, nums);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, int rem, vi &nums, vvi &memo) {
        if (idx == sz(nums)) {
            return (rem == 0) ? 0 : INT_MIN;
        }

        if (memo[idx][rem] != -1)
            return memo[idx][rem];

        int include = solve(idx + 1, (rem + nums[idx]) % 3, nums, memo) + nums[idx];
        int exclude = solve(idx + 1, rem, nums, memo);

        return memo[idx][rem] = max(include, exclude);
    }

  public:
    int maxSumDivThree(vector<int> &nums) {
        int n = sz(nums);
        vvi memo(n, vi(3, -1));
        return solve(0, 0, nums, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int maxSumDivThree(vector<int> &nums) {
        int n = sz(nums);
        vvi dp(n + 1, vi(3, 0));

        revloop(idx, n, 0) {
            loop(rem, 0, 3) {
                if (idx == n) {
                    dp[idx][rem] = (rem == 0) ? 0 : INT_MIN;
                    continue;
                }

                int include = dp[idx + 1][(rem + nums[idx]) % 3] + nums[idx];
                int exclude = dp[idx + 1][rem];

                dp[idx][rem] = max(include, exclude);
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int maxSumDivThree(vector<int> &nums) {
        int n = sz(nums);
        vi next(3, INT_MIN);
        next[0] = 0;

        revloop(idx, n - 1, 0) {
            vi curr(3, 0);

            loop(rem, 0, 3) {
                int include = next[(rem + nums[idx]) % 3] + nums[idx];
                int exclude = next[rem];

                curr[rem] = max(include, exclude);
            }

            next = curr;
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    vi v = {3, 6, 5, 1, 8};
    println(obj.maxSumDivThree(v));
    v = {4};
    println(obj.maxSumDivThree(v));
    v = {1, 2, 3, 4, 4};
    println(obj.maxSumDivThree(v));
}

/*
Problem: Greatest Sum Divisible by Three
*/