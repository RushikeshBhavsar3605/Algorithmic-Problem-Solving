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

/* Approach 1 (Tabulation): */
class Solution {
  public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vec<vec<vec<ll>>> dp(zero + 1, vec<vec<ll>>(one + 1, vec<ll>(2)));
        ll mod = 1e9 + 7;
        loop(i, 0, min(zero, limit) + 1) dp[i][0][0] = 1;
        loop(j, 0, min(one, limit) + 1) dp[0][j][1] = 1;

        loop(i, 1, zero + 1) {
            loop(j, 1, one + 1) {
                if (i > limit)
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
                else
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];

                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                if (j > limit)
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
                else
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];

                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};

int main() {
    Solution obj;
    auto res = obj.numberOfStableArrays(1, 1, 2);
    print(res);
    res = obj.numberOfStableArrays(1, 2, 1);
    print(res);
    res = obj.numberOfStableArrays(3, 3, 2);
    print(res);
    return 0;
}

/*
Problem: Find All Possible Stable Binary Arrays II
*/