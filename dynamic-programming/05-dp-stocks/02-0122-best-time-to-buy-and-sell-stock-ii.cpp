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
    int solve(int idx, int buy, vi &prices, vvi &memo) {
        if (idx == sz(prices))
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        long profit = 0;
        if (buy)
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, memo),
                        solve(idx + 1, 1, prices, memo));
        else
            profit = max(prices[idx] + solve(idx + 1, 1, prices, memo),
                        solve(idx + 1, 0, prices, memo));

        return memo[idx][buy] = profit;
    }

  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vvi memo(n + 1, vi(2, -1));

        return solve(0, 1, prices, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vvi dp(n + 1, vi(2, 0));

        revloop(idx, n - 1, 0) {
            revloop(buy, 1, 0) {
                int profit = 0;
                if (buy)
                    profit = max(-prices[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                else
                    profit = max(prices[idx] + dp[idx + 1][1], dp[idx + 1][0]);

                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];
    }
};
*/

/* Approach 3 (Space Optimization):
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = sz(prices);
        vi curr(2, 0);
        vi next(2, 0);

        revloop(idx, n - 1, 0) {
            revloop(buy, 1, 0) {
                int profit = 0;
                if (buy)
                    profit = max(-prices[idx] + next[0], next[1]);
                else
                    profit = max(prices[idx] + next[1], next[0]);

                curr[buy] = profit;
            }

            swap(curr, next);
        }

        return next[1];
    }
};
*/

/* Approach 4 (Greedy): */
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        loop(i, 1, sz(prices))
            if (prices[i - 1] < prices[i])
                profit += prices[i] - prices[i - 1];

        return profit;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {7, 1, 5, 3, 6, 4};
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
Problem: Best Time to Buy and Sell Stock II

  1 0
7 14 7
1 8 7
5 8 3
3 6 3
6 6 0
4 4 0
33 0 0

7

  1 0
1 5 4
2 5 3
3 5 2
4 5 1
5 5 0
4 0 0

4

  1 0
7 7 0
6 6 0
4 4 0
3 3 0
1 1 0
4 0 0

0
*/