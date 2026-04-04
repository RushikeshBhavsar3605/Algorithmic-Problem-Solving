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
    int solve(int idx, vec<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (idx < 0)
            return INT_MAX - 1;

        int notTake = solve(idx - 1, coins, amount);
        int take = INT_MAX - 1;
        if (coins[idx] <= amount)
            take = solve(idx, coins, amount - coins[idx]) + 1;

        return min(notTake, take);
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        int res = solve(sz(coins) - 1, coins, amount);
        return res < INT_MAX - 1 ? res : -1;
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, vec<int> &coins, int amount, vec<vec<int>> &memo) {
        if (amount == 0)
            return 0;
        if (idx < 0)
            return INT_MAX - 1;

        if (memo[idx][amount] != -1)
            return memo[idx][amount];

        int notTake = solve(idx - 1, coins, amount, memo);
        int take = INT_MAX - 1;
        if (coins[idx] <= amount)
            take = solve(idx, coins, amount - coins[idx], memo) + 1;

        return memo[idx][amount] = min(notTake, take);
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        vec<vec<int>> memo(sz(coins), vec<int>(amount + 1, -1));
        int res = solve(sz(coins) - 1, coins, amount, memo);

        return res < INT_MAX - 1 ? res : -1;
    }
};
*/

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = sz(coins);
        vec<vec<int>> dp(n, vec<int>(amount + 1, INT_MAX - 1));
        loop(i, 0, n) dp[i][0] = 0;

        loop(idx, 1, n) {
            loop(price, 0, amount + 1) {
                int notTake = dp[idx - 1][price];
                int take = INT_MAX - 1;
                if (coins[idx] <= price)
                    take = dp[idx - 1][price - coins[idx]] + 1;

                dp[idx][price] = min(notTake, take);
            }
        }

        return dp[n - 1][amount] < INT_MAX - 1 ? dp[n - 1][amount] : -1;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 2, 5};
    cout << obj.coinChange(v, 11) << endl;
    v = {2};
    cout << obj.coinChange(v, 3) << endl;
    v = {1};
    cout << obj.coinChange(v, 0) << endl;
    return 0;
}

/*
Problem: Coin Change
*/