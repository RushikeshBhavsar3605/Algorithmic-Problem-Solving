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

/* Approach 1 (Dynamic Programming):
class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = sz(s);
        int m = sz(t);
        vec<vec<double>> dp(n + 1, vec<double>(m + 1, 0));
        loop(i, 0, n + 1)
            dp[i][m] = 1;

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j];
            }
        }

        return (int)dp[0][0];
    }
};
*/

/* Approach 2 (Space Optimization):
class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = sz(s);
        int m = sz(t);
        vec<double> curr(m + 1, 0);
        vec<double> next(m + 1, 0);
        curr[m] = next[m] = 1;

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (s[i] == t[j])
                    curr[j] = next[j + 1] + next[j];
                else
                    curr[j] = next[j];
            }

            swap(curr, next);
        }

        return (int)next[0];
    }
};
*/

/* Approach 3 (Optimal): */
class Solution {
  public:
    int numDistinct(string s, string t) {
        int n = sz(s);
        int m = sz(t);
        vec<double> dp(m + 1, 0);
        dp[m] = 1;

        revloop(i, n - 1, 0) {
            loop(j, 0, m) {
                if (s[i] == t[j])
                    dp[j] += dp[j + 1];
            }
        }

        return dp[0];
    }
};

int main() {
    Solution obj;
    auto res = obj.numDistinct("rabbbit", "rabbit");
    print(res);
    res = obj.numDistinct("babgbag", "bag");
    print(res);
    return 0;
}

/*
Problem: Distinct Subsequences

  r a b b i t 
r 3 3 3 3 1 1 1 
a 0 3 3 3 1 1 1 
b 0 0 3 3 1 1 1 
b 0 0 1 2 1 1 1 
b 0 0 0 1 1 1 1 
i 0 0 0 0 1 1 1 
t 0 0 0 0 0 1 1 
  0 0 0 0 0 0 1 

3

  b a g 
b 5 3 2 1 
a 2 3 2 1 
b 2 1 2 1 
g 1 1 2 1 
b 1 1 1 1 
a 0 1 1 1 
g 0 0 1 1 
  0 0 0 1 

5
*/