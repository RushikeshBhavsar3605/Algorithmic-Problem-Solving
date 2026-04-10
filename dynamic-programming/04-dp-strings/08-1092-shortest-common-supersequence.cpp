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

/* Approach 1 (Dynamic Programming): */
class Solution {
  public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = sz(str1);
        int m = sz(str2);
        vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        string res;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                res.pb(str1[i]);
                i++;
                j++;
            } else if (dp[i][j + 1] < dp[i + 1][j]) {
                res.pb(str1[i]);
                i++;
            } else {
                res.pb(str2[j]);
                j++;
            }
        }

        while (i < n)
            res.pb(str1[i++]);

        while (j < m)
            res.pb(str2[j++]);

        return res;
    }
};

int main() {
    Solution obj;
    auto res = obj.shortestCommonSupersequence("abac", "cab");
    print(res);
    res = obj.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa");
    print(res);
    return 0;
}

/*
Problem: Shortest Common Supersequence

  c a b 
a 2 2 1 0 
b 1 1 1 0 
a 1 1 0 0 
c 1 0 0 0 
  0 0 0 0 

cabac

  a a a a a a a a 
a 8 7 6 5 4 3 2 1 0 
a 7 7 6 5 4 3 2 1 0 
a 6 6 6 5 4 3 2 1 0 
a 5 5 5 5 4 3 2 1 0 
a 4 4 4 4 4 3 2 1 0 
a 3 3 3 3 3 3 2 1 0 
a 2 2 2 2 2 2 2 1 0 
a 1 1 1 1 1 1 1 1 0 
  0 0 0 0 0 0 0 0 0 

aaaaaaaa
*/