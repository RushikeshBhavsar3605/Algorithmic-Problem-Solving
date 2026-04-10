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
    int solve(int i, int j, string &s, string &p, vec<vec<int>> &memo) {
        if (i == sz(s) && j == sz(p))
            return true;

        if (j == sz(p))
            return false;
        if (i == sz(s)) {
            loop(k, j, sz(p))
                if (p[k] != '*')
                    return false;

            return true;
        }

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return memo[i][j] = solve(i + 1, j + 1, s, p, memo);

        if (p[j] == '*')
            return memo[i][j] = solve(i + 1, j, s, p, memo) || solve(i, j + 1, s, p, memo);

        return memo[i][j] = false;
    }

  public:
    bool isMatch(string s, string p) {
        int n = sz(s);
        int m = sz(p);
        vec<vec<int>> memo(n, vec<int>(m, -1));

        return solve(0, 0, s, p, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = sz(s);
        int m = sz(p);
        vec<vec<bool>> dp(n + 1, vec<bool>(m + 1, 0));
        dp[n][m] = true;
        revloop(j, m - 1, 0) {
            dp[n][j] = dp[n][j + 1];
            if (p[j] != '*')
                dp[n][j] = false;
        }

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (s[i] == p[j] || p[j] == '?')
                    dp[i][j] = dp[i + 1][j + 1];

                else if (p[j] == '*')
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];

                else
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = sz(s);
        int m = sz(p);

        vec<bool> curr(m + 1, false);
        vec<bool> next(m + 1, false);
        next[m] = true;
        revloop(j, m - 1, 0) {
            next[j] = next[j + 1];
            if (p[j] != '*')
                next[j] = false;
        }

        revloop(i, n - 1, 0) {
            curr[m] = false;

            revloop(j, m - 1, 0) {
                if (s[i] == p[j] || p[j] == '?')
                    curr[j] = next[j + 1];

                else if (p[j] == '*')
                    curr[j] = next[j] || curr[j + 1];

                else
                    curr[j] = false;
            }

            swap(curr, next);
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    auto res = obj.isMatch("aa", "a");
    print(res);
    res = obj.isMatch("aa", "*");
    print(res);
    res = obj.isMatch("cb", "?a");
    print(res);
    res = obj.isMatch("acdcb", "a*c?b");
    print(res);
    res = obj.isMatch("adceb", "*a*b");
    print(res);
    return 0;
}

/*
Problem: Wildcard Matching

  a 
a 0 0 
a 1 0 
  0 1 

0

  * 
a 1 0 
a 1 0 
  1 1 

1

  ? a 
c 0 0 0 
b 0 0 0 
  0 0 1 

0

  a * c ? b 
a 0 0 0 0 0 0 
c 0 0 0 0 0 0 
d 0 0 0 0 0 0 
c 0 0 0 1 0 0 
b 0 0 0 0 1 0 
  0 0 0 0 0 1 

0

  * a * b 
a 1 1 1 0 0 
d 0 0 1 0 0 
c 0 0 1 0 0 
e 0 0 1 0 0 
b 0 0 1 1 0 
  0 0 0 0 1 

1
*/