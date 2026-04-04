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

/* Approach 1 (Recursion)(TLE):
class Solution {
  private:
    int solve(int idx, int target, vec<int> &coins) {
        if (idx == sz(coins))
            return target == 0 ? 1 : 0;

        int take = 0;
        if (coins[idx] <= target)
            take = solve(idx, target - coins[idx], coins);

        int notTake = solve(idx + 1, target, coins);

        return take + notTake;
    }

  public:
    int change(int amount, vector<int> &coins) { return solve(0, amount, coins); }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, int target, vec<int> &coins, vec<vec<int>> &memo) {
        if (idx == sz(coins))
            return target == 0 ? 1 : 0;

        if (memo[idx][target] != -1)
            return memo[idx][target];

        int take = 0;
        if (coins[idx] <= target)
            take = solve(idx, target - coins[idx], coins, memo);

        int notTake = solve(idx + 1, target, coins, memo);

        return memo[idx][target] = take + notTake;
    }

  public:
    int change(int amount, vector<int> &coins) {
        vec<vec<int>> memo(sz(coins), vec<int>(amount + 1, -1));
        return solve(0, amount, coins, memo);
    }
};
*/

/* Approach 3 (Tabulation):*/
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        int n = sz(coins);
        vec<vec<int>> dp(n + 1, vec<int>(amount + 1, 0));

        loop(i, 0, amount + 1)
            if (i % coins[0] == 0)
                dp[0][i] = 1;

        revloop(idx, n - 1, 0) {
            loop(target, 0, amount + 1) {
                int take = 0;
                if (coins[idx] <= target)
                    take = dp[idx][target - coins[idx]];

                int notTake = dp[idx + 1][target];

                dp[idx][target] = take + notTake;
            }
        }

        return dp[0][amount];
    }
};

int main() {
    Solution obj;
    vec<int> coins = {1, 2, 5};
    auto res = obj.change(5, coins);
    print(res);
    coins = {2};
    res = obj.change(3, coins);
    print(res);
    coins = {10};
    res = obj.change(10, coins);
    print(res);
    return 0;
}

/*
Problem: Coin Change II
*/