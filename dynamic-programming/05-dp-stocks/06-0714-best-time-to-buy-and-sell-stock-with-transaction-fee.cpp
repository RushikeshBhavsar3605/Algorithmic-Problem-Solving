#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Memoization):
class Solution {
  private:
    int solve(int idx, int buy, int fee, vi &prices, vvi &memo) {
        if (idx == sz(prices))
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        int res = 0;
        if (buy) {
            updateMax(res, -prices[idx] - fee + solve(idx + 1, 0, fee, prices, memo));
            updateMax(res, solve(idx + 1, 1, fee, prices, memo));
        } else {
            updateMax(res, prices[idx] + solve(idx + 1, 1, fee, prices, memo));
            updateMax(res, solve(idx + 1, 0, fee, prices, memo));
        }

        return memo[idx][buy] = res;
    }

  public:
    int maxProfit(vector<int> &prices, int fee) {
        vvi memo(sz(prices), vi(2, -1));

        return solve(0, 1, fee, prices, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = sz(prices);
        vvi dp(n + 1, vi(2, 0));

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                int res = 0;
                if (buy) {
                    updateMax(res, -prices[idx] - fee + dp[idx + 1][0]);
                    updateMax(res, dp[idx + 1][1]);
                } else {
                    updateMax(res, prices[idx] + dp[idx + 1][1]);
                    updateMax(res, dp[idx + 1][0]);
                }

                dp[idx][buy] = res;
            }
        }

        return dp[0][1];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = sz(prices);
        vi curr(2, 0);
        vi next(2, 0);

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                int res = 0;
                if (buy) {
                    updateMax(res, -prices[idx] - fee + next[0]);
                    updateMax(res, next[1]);
                } else {
                    updateMax(res, prices[idx] + next[1]);
                    updateMax(res, next[0]);
                }

                curr[buy] = res;
            }

            swap(curr, next);
        }

        return next[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, 2, 8, 4, 9};
    auto res = obj.maxProfit(v, 2);
    print(res);
    v = {1, 3, 7, 5, 10, 3};
    res = obj.maxProfit(v, 3);
    print(res);
    return 0;
}

/*
Problem: Best Time to Buy and Sell Stock with Transaction Fee
*/