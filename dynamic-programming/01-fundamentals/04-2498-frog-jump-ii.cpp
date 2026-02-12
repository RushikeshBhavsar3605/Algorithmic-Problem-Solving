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

/* Approach 1 (Recursion): O(n) single-branch recurrence [dp[i] = max(dp[i-1], stones[i]-stones[i-2])]
class Solution {
  private:
    int solve(int idx, vi &stones) {
        // Base: no cost at start, first step is direct delta
        if (idx == 0)
            return 0;
        if (idx == 1)
            return stones[1] - stones[0];

        // dp[idx] = max(dp[idx-1], stones[idx]-stones[idx-2])
        int take = solve(idx - 1, stones);           // dp[idx-1]
        int notTake = stones[idx] - stones[idx - 2]; // gap skipping one stone

        return max(take, notTake);                   // bottleneck minimized
    }

  public:
    int maxJump(vector<int> &stones) {
        int n = sz(stones);
        return solve(sz(stones) - 1, stones); // answer = dp[n-1]
    }
};
*/

/* Approach 2 (Memoization): O(n) time, O(n) memo; avoids recursion recompute (not needed here)
class Solution {
  private:
    int solve(int idx, vi &stones, vi &memo) {
        if (idx == 0)
            return 0;                     // base
        if (idx == 1)
            return stones[1] - stones[0]; // base

        if (memo[idx] != -1)
            return memo[idx]; // cache hit

        int take = solve(idx - 1, stones, memo);     // dp[idx-1]
        int notTake = stones[idx] - stones[idx - 2]; // gap i - (i-2)

        return memo[idx] = max(take, notTake);       // store result
    }

  public:
    int maxJump(vector<int> &stones) {
        int n = sz(stones);
        vi memo(n, -1);                    // O(n) cache
        return solve(n - 1, stones, memo); // top-down
    }
};
*/

/* Approach 3 (Tabulation): O(n) time, O(n) space bottom-up
class Solution {
  public:
    int maxJump(vector<int> &stones) {
        int n = sz(stones);
        if (n == 2)
            return stones[1] - stones[0]; // trivial

        vi dp(n);
        dp[0] = 0;                     // base
        dp[1] = stones[1] - stones[0]; // base

        loop(i, 2, n)
            dp[i] = max(dp[i - 1], stones[i] - stones[i - 2]); // recurrence

        return dp[n - 1]; // answer
    }
};
*/

/* Approach 4 (Space Optimization): reduce to O(1) space; effectively the greedy scan
class Solution {
  public:
    int maxJump(vector<int> &stones) {
        int n = sz(stones);
        if (n == 2)
            return stones[1] - stones[0]; // trivial

        int prev2 = 0;                     // base
        int prev1 = stones[1] - stones[0]; // base

        loop(i, 2, n) {
            prev1 = max(prev2, stones[i] - stones[i - 2]); // recurrence
            prev2 = prev1;
        }

        return prev1; // answer
    }
};
*/

/* Approach 5 (Simplified) (Greedy): reduce to O(1) space; effectively the greedy scan */
class Solution {
  public:
    int maxJump(vector<int> &stones) {
        int n = sz(stones);
        if (n == 2)
            return stones[1] - stones[0]; // trivial

        int result = stones[1] - stones[0];               // seed
        loop(i, 2, n)
            updateMax(result, stones[i] - stones[i - 2]); // take max gap

        return result; // answer
    }
};

int main() {
    Solution obj;
    vi v = {0, 2, 5, 6, 7};
    println(obj.maxJump(v));
    v = {0, 3, 9};
    println(obj.maxJump(v));
}

/*
Problem: Frog Jump II
*/