#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

/* Approach 1 (Recursion):
class Solution {
  private:
    int solve(int idx, int maxWt, vec<int> &val, vec<int> &wt) {
        if (idx < 0)
            return 0;

        int notTake = solve(idx - 1, maxWt, val, wt);
        int take = 0;
        if (wt[idx] <= maxWt)
            take = solve(idx - 1, maxWt - wt[idx], val, wt) + val[idx];

        return max(take, notTake);
    }

  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        return solve(sz(val), W, val, wt);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, int maxWt, vec<int> &val, vec<int> &wt, vec<vec<int>> &memo) {
        if (idx < 0)
            return 0;

        if (memo[idx][maxWt] != -1)
            return memo[idx][maxWt];

        int notTake = solve(idx - 1, maxWt, val, wt, memo);
        int take = 0;
        if (wt[idx] <= maxWt)
            take = solve(idx - 1, maxWt - wt[idx], val, wt, memo) + val[idx];

        return memo[idx][maxWt] = max(take, notTake);
    }

  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vec<vec<int>> memo(sz(val), vec<int>(W + 1, -1));
        return solve(sz(val) - 1, W, val, wt, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = sz(val);
        vec<vec<int>> dp(sz(val), vec<int>(W + 1, 0));

        loop(i, wt[0], W + 1) dp[0][i] = val[0];

        loop(idx, 1, n) {
            loop(maxWt, 0, W + 1) {
                int notTake = dp[idx - 1][maxWt];
                int take = 0;
                if (wt[idx] <= maxWt)
                    take = dp[idx - 1][maxWt - wt[idx]] + val[idx];

                dp[idx][maxWt] = max(notTake, take);
            }
        }

        return dp[n - 1][W];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = sz(val);
        vec<int> prev(W + 1, 0);
        vec<int> curr(W + 1, 0);

        loop(i, wt[0], W + 1)
            prev[i] = val[0];

        loop(idx, 1, n) {
            loop(maxWt, 0, W + 1) {
                int notTake = prev[maxWt];
                int take = 0;
                if (wt[idx] <= maxWt)
                    take = prev[maxWt - wt[idx]] + val[idx];

                curr[maxWt] = max(notTake, take);
            }

            swap(prev, curr);
        }

        return prev[W];
    }
};

int main() {
    Solution obj;
    vec<int> val = {1, 2, 3};
    vec<int> wt = {4, 5, 1};
    cout << obj.knapsack(4, val, wt) << endl;
    val = {1, 2, 3};
    wt = {4, 5, 6};
    cout << obj.knapsack(3, val, wt) << endl;
    val = {10, 40, 30, 50};
    wt = {5, 4, 2, 3};
    cout << obj.knapsack(5, val, wt) << endl;
    return 0;
}

/*
Problem: 0 - 1 Knapsack Problem
Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/