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
    // Recursive function to check if we can form `target`
    // using elements from index `idx` to end
    bool solve(int idx, int target, vi &nums) {
        // Base case: exact target achieved
        if (target == 0)
            return true;

        // Base case: no elements left but target not achieved
        if (idx == sz(nums))
            return false;

        // Option 1: skip current element
        bool notTaken = solve(idx + 1, target, nums);

        // Option 2: take current element if it does not exceed target
        bool taken = false;
        if (nums[idx] <= target)
            taken = solve(idx + 1, target - nums[idx], nums);

        // Return true if either choice works
        return notTaken || taken;
    }

  public:
    bool canPartition(vector<int> &nums) {
        // Compute total sum of array
        int totalSum = accumulate(all(nums), 0);

        // If total sum is odd, equal partition is impossible
        if (totalSum & 1)
            return false;

        // Target sum for each subset
        int k = (totalSum >> 1);

        // Check if subset with sum = k exists
        return solve(0, k, nums);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    // Recursive function with memoization to check
    // if we can form `target` using elements from index `idx`
    bool solve(int idx, int target, vi &nums, vvi &memo) {
        // Base case: exact target achieved
        if (target == 0)
            return true;

        // Base case: no elements left but target not achieved
        if (idx == sz(nums))
            return false;

        // Return cached result if already computed
        if (memo[idx][target] != -1)
            return memo[idx][target];

        // Option 1: skip current element
        bool notTaken = solve(idx + 1, target, nums, memo);

        // Option 2: take current element if feasible
        bool taken = false;
        if (nums[idx] <= target)
            taken = solve(idx + 1, target - nums[idx], nums, memo);

        // Store and return result for current state
        return memo[idx][target] = notTaken || taken;
    }

  public:
    bool canPartition(vector<int> &nums) {
        // Compute total sum of the array
        int totalSum = accumulate(all(nums), 0);

        // If total sum is odd, equal partition is impossible
        if (totalSum & 1)
            return false;

        // Target sum for each subset
        int k = (totalSum >> 1);
        // Memo table: memo[idx][target]
        vvi memo(sz(nums), vi(k + 1, -1));
        // Check if subset with sum = k exists
        return solve(0, k, nums, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        // Compute total sum of the array
        int totalSum = accumulate(all(nums), 0);

        // If total sum is odd, equal partition is impossible
        if (totalSum & 1)
            return false;

        int n = sz(nums);
        int k = totalSum / 2;

        // dp[idx][target] = whether we can form `target`
        // using elements from idx to n-1
        vvi dp(sz(nums), vi(k + 1, 0));

        // Base case: target 0 is always achievable
        loop(idx, 0, n)
            dp[idx][0] = true;

        // Base case: last element alone can form its value
        if (nums[n - 1] <= k)
            dp[n - 1][nums[n - 1]] = true;

        // Fill DP table bottom-up
        revloop(idx, n - 2, 0) {
            loop(target, 1, k + 1) {
                // Option 1: skip current element
                bool notTaken = dp[idx + 1][target];

                // Option 2: take current element if feasible
                bool taken = false;
                if (nums[idx] <= target)
                    taken = dp[idx + 1][target - nums[idx]];

                // Store result for current state
                dp[idx][target] = notTaken || taken;
            }
        }

        // Answer: can we form target k starting from index 0
        return dp[0][k];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        // Compute total sum of the array
        int totalSum = accumulate(all(nums), 0);

        // If total sum is odd, equal partition is impossible
        if (totalSum & 1)
            return false;

        int n = sz(nums);
        int k = totalSum / 2;

        // Space-optimized DP arrays
        // next[target] -> dp for idx + 1
        // curr[target] -> dp for idx
        vi next(k + 1, 0);
        vi curr(k + 1, 0);

        // Base case: target 0 is always achievable
        next[0] = true;
        // Base case: last element alone can form its value
        if (nums[n - 1] <= k)
            next[nums[n - 1]] = true;

        // Build DP from bottom to top
        revloop(idx, n - 2, 0) {
            // Reset base case for current row
            curr[0] = true;

            loop(target, 1, k + 1) {
                // Option 1: skip current element
                bool notTaken = next[target];

                // Option 2: take current element if feasible
                bool taken = false;
                if (nums[idx] <= target)
                    taken = next[target - nums[idx]];

                // Store result for current state
                curr[target] = notTaken || taken;
            }

            // Move current row to next
            next = curr;
        }

        // Answer: can we form target k
        return next[k];
    }
};

int main() {
    Solution obj;
    vi v = {1, 5, 11, 5};
    println(obj.canPartition(v));
    v = {1, 2, 3, 5};
    println(obj.canPartition(v));
}

/*
Problem: Partition Equal Subset Sum
*/