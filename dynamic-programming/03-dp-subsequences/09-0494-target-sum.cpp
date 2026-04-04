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

// =====================
// Universal Printers
// =====================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vec<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vec<vec<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Memoization):
class Solution {
  private:
    int solve(int idx, int curr, vec<int> &nums, int target, vec<vec<int>> &memo, int offset) {
        if (idx == sz(nums))
            return curr == target;

        int shifted = curr + offset;
        if (memo[idx][shifted] != -1)
            return memo[idx][shifted];

        int plus = solve(idx + 1, curr + nums[idx], nums, target, memo, offset);
        int minus = solve(idx + 1, curr - nums[idx], nums, target, memo, offset);

        return memo[idx][shifted] = plus + minus;
    }

  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int totalSum = accumulate(all(nums), 0);
        if (abs(target) > totalSum)
            return 0;

        vec<vec<int>> memo(sz(nums), vec<int>(2 * totalSum + 1, -1));
        return solve(0, 0, nums, target, memo, totalSum);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = sz(nums);
        int totalSum = accumulate(all(nums), 0);
        if (abs(target) > totalSum)
            return 0;

        int offset = totalSum;
        vec<vec<int>> dp(n + 1, vec<int>(2 * totalSum + 1, 0));
        dp[n][target + offset] = 1;

        revloop(idx, n - 1, 0) {
            revloop(curr, totalSum, -totalSum) {
                int shifted = curr + offset;
                int plus = 0, minus = 0;

                if (curr + nums[idx] <= totalSum)
                    plus = dp[idx + 1][curr + nums[idx] + offset];
                if (curr - nums[idx] >= -totalSum)
                    minus = dp[idx + 1][curr - nums[idx] + offset];

                dp[idx][shifted] = plus + minus;
            }
        }

        return dp[0][offset];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = sz(nums);
        int totalSum = accumulate(all(nums), 0);
        if (abs(target) > totalSum)
            return 0;

        int offset = totalSum;
        vec<int> curr(2 * totalSum + 1, 0);
        vec<int> next(2 * totalSum + 1, 0);
        next[target + offset] = 1;

        revloop(idx, n - 1, 0) {
            revloop(c, totalSum, -totalSum) {
                int shifted = c + offset;
                int plus = 0, minus = 0;

                if (c + nums[idx] <= totalSum)
                    plus = next[c + nums[idx] + offset];
                if (c - nums[idx] >= -totalSum)
                    minus = next[c - nums[idx] + offset];

                curr[shifted] = plus + minus;
            }

            swap(curr, next);
        }

        return next[offset]; // curr = 0;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 1, 1, 1, 1};
    auto res = obj.findTargetSumWays(v, 3);
    print(res);
    v = {1};
    res = obj.findTargetSumWays(v, 1);
    print(res);
    return 0;
}

/*
Problem: Target Sum
*/