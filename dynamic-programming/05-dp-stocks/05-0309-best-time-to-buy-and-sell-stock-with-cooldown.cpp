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
    int solve(int idx, int buy, int cooldown, vi &prices, nvec_t<int, 3> &memo) {
        if (idx == sz(prices))
            return 0;

        if (memo[idx][buy][cooldown] != -1)
            return memo[idx][buy][cooldown];

        if (cooldown)
            return solve(idx + 1, buy, 0, prices, memo);

        int res = 0;
        if (buy) {
            updateMax(res, -prices[idx] + solve(idx + 1, 0, 0, prices, memo));
            updateMax(res, solve(idx + 1, 1, 0, prices, memo));
        } else {
            updateMax(res, prices[idx] + solve(idx + 1, 1, 1, prices, memo));
            updateMax(res, solve(idx + 1, 0, 0, prices, memo));
        }

        return memo[idx][buy][cooldown] = res;
    }

  public:
    int maxProfit(vector<int> &prices) {
        nvec_t<int, 3> memo(sz(prices), vvi(2, vi(2, -1)));

        return solve(0, 1, 0, prices, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        nvec_t<int, 3> dp(n + 1, vvi(2, vi(2, 0)));

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                revloop(cooldown, 1, 0) {
                    if (cooldown) {
                        dp[idx][buy][cooldown] = dp[idx + 1][buy][0];
                        continue;
                    }

                    int res = 0;
                    if (buy) {
                        updateMax(res, -prices[idx] + dp[idx + 1][0][0]);
                        updateMax(res, dp[idx + 1][1][0]);
                    } else {
                        updateMax(res, prices[idx] + dp[idx + 1][1][1]);
                        updateMax(res, dp[idx + 1][0][0]);
                    }

                    dp[idx][buy][cooldown] = res;
                }
            }
        }

        return dp[0][1][0];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vvi curr(2, vi(2, 0));
        vvi next(2, vi(2, 0));

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                revloop(cooldown, 1, 0) {
                    if (cooldown) {
                        curr[buy][cooldown] = next[buy][0];
                        continue;
                    }

                    int res = 0;
                    if (buy) {
                        updateMax(res, -prices[idx] + next[0][0]);
                        updateMax(res, next[1][0]);
                    } else {
                        updateMax(res, prices[idx] + next[1][1]);
                        updateMax(res, next[0][0]);
                    }

                    curr[buy][cooldown] = res;
                }
            }

            swap(curr, next);
        }

        return next[1][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 0, 2};
    auto res = obj.maxProfit(v);
    print(res);
    v = {1};
    res = obj.maxProfit(v);
    print(res);
    return 0;
}

/*
Problem: Best Time to Buy and Sell Stock with Cooldown
*/