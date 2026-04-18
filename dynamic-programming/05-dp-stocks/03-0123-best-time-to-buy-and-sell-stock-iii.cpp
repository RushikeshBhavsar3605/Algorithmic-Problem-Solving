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
    int solve(int idx, int buy, int cap, vi &prices, nvec_t<int, 3> &memo) {
        if (idx == sz(prices) || !cap)
            return 0;

        if (memo[idx][buy][cap] != -1)
            return memo[idx][buy][cap];

        int res = 0;
        if (buy) {
            updateMax(res, -prices[idx] + solve(idx + 1, 0, cap, prices, memo));
            updateMax(res, solve(idx + 1, 1, cap, prices, memo));
        } else {
            updateMax(res, prices[idx] + solve(idx + 1, 1, cap - 1, prices, memo));
            updateMax(res, solve(idx + 1, 0, cap, prices, memo));
        }

        return memo[idx][buy][cap] = res;
    }

  public:
    int maxProfit(vector<int> &prices) {
        nvec_t<int, 3> memo(sz(prices) + 1, vvi(2, vi(3, -1)));

        return solve(0, 1, 2, prices, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        nvec_t<int, 3> dp(n + 1, vvi(2, vi(3, 0)));

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                loop(cap, 1, 3) {
                    int res = 0;
                    if (buy) {
                        updateMax(res, -prices[idx] + dp[idx + 1][0][cap]);
                        updateMax(res, dp[idx + 1][1][cap]);
                    } else {
                        updateMax(res, prices[idx] + dp[idx + 1][1][cap - 1]);
                        updateMax(res, dp[idx + 1][0][cap]);
                    }

                    dp[idx][buy][cap] = res;
                }
            }
        }

        return dp[0][1][2];
    }
};
*/

/* Approach 3 (Space Optimization):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vvi curr(2, vi(3, 0));
        vvi next(2, vi(3, 0));

        revloop(idx, n - 1, 0) {
            loop(buy, 0, 2) {
                loop(cap, 1, 3) {
                    int res = 0;
                    if (buy) {
                        updateMax(res, -prices[idx] + next[0][cap]);
                        updateMax(res, next[1][cap]);
                    } else {
                        updateMax(res, prices[idx] + next[1][cap - 1]);
                        updateMax(res, next[0][cap]);
                    }

                    curr[buy][cap] = res;
                }
            }

            swap(curr, next);
        }

        return next[1][2];
    }
};
*/

/* Approach 4 (Transaction + Memoization):
class Solution {
  private:
    int solve(int idx, int tid, vi &prices, vvi &memo) {
        if (idx == sz(prices) || tid == 4)
            return 0;

        if (memo[idx][tid] != -1)
            return memo[idx][tid];

        int res = 0;
        if (tid % 2 == 0) {
            updateMax(res, -prices[idx] + solve(idx + 1, tid + 1, prices, memo));
            updateMax(res, solve(idx + 1, tid, prices, memo));
        } else {
            updateMax(res, prices[idx] + solve(idx + 1, tid + 1, prices, memo));
            updateMax(res, solve(idx + 1, tid, prices, memo));
        }

        return memo[idx][tid] = res;
    }

  public:
    int maxProfit(vector<int> &prices) {
        vvi memo(sz(prices) + 1, vi(4, -1));

        return solve(0, 0, prices, memo);
    }
};
*/

/* Approach 5 (Transaction + Tabulation):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vvi dp(n + 1, vi(5, 0));

        revloop(idx, n - 1, 0) {
            revloop(tid, 3, 0) {
                int res = 0;

                if (tid % 2 == 0) {
                    updateMax(res, -prices[idx] + dp[idx + 1][tid + 1]);
                    updateMax(res, dp[idx + 1][tid]);
                } else {
                    updateMax(res, prices[idx] + dp[idx + 1][tid + 1]);
                    updateMax(res, dp[idx + 1][tid]);
                }

                dp[idx][tid] = res;
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 6 (Transaction + Space Optimization): */
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vi curr(5, 0);
        vi next(5, 0);

        revloop(idx, n - 1, 0) {
            revloop(tid, 3, 0) {
                int res = 0;

                if (tid % 2 == 0) {
                    updateMax(res, -prices[idx] + next[tid + 1]);
                    updateMax(res, next[tid]);
                } else {
                    updateMax(res, prices[idx] + next[tid + 1]);
                    updateMax(res, next[tid]);
                }

                curr[tid] = res;
            }

            swap(curr, next);
        }

        return next[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 3, 5, 0, 0, 3, 1, 4};
    auto res = obj.maxProfit(v);
    print(res);
    v = {1, 2, 3, 4, 5};
    res = obj.maxProfit(v);
    print(res);
    v = {7, 6, 4, 3, 1};
    res = obj.maxProfit(v);
    print(res);
    return 0;
}

/*
Problem: Best Time to Buy and Sell Stock III
*/