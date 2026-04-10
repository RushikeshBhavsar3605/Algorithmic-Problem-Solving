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
    int solve(int idx1, int idx2, string &str1, string &str2, vec<vec<int>> &memo) {
        if (idx1 >= sz(str1) || idx2 >= sz(str2))
            return 0;

        if (memo[idx1][idx2] != -1)
            return memo[idx1][idx2];

        if (str1[idx1] == str2[idx2])
            return memo[idx1][idx2] = solve(idx1 + 1, idx2 + 1, str1, str2, memo) + 1;

        return memo[idx1][idx2] = max(solve(idx1 + 1, idx2, str1, str2, memo), solve(idx1, idx2 + 1, str1, str2, memo));
    }

  public:
    int longestCommonSubsequence(string text1, string text2) {
        vec<vec<int>> memo(sz(text1), vec<int>(sz(text2), -1));
        return solve(0, 0, text1, text2, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = sz(text1);
        int m = sz(text2);
        vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));

        revloop(idx1, n - 1, 0) {
            revloop(idx2, m - 1, 0) {
                if (text1[idx1] == text2[idx2])
                    dp[idx1][idx2] = dp[idx1 + 1][idx2 + 1] + 1;
                else
                    dp[idx1][idx2] = max(dp[idx1 + 1][idx2], dp[idx1][idx2 + 1]);
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = sz(text1);
        int m = sz(text2);
        vec<int> curr(m + 1, 0);
        vec<int> next(m + 1, 0);

        revloop(idx1, n - 1, 0) {
            revloop(idx2, m - 1, 0) {
                if (text1[idx1] == text2[idx2])
                    curr[idx2] = next[idx2 + 1] + 1;
                else
                    curr[idx2] = max(next[idx2], curr[idx2 + 1]);
            }

            swap(curr, next);
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    auto res = obj.longestCommonSubsequence("abcde", "ace");
    print(res);
    res = obj.longestCommonSubsequence("abc", "abc");
    print(res);
    res = obj.longestCommonSubsequence("abc", "def");
    print(res);
    return 0;
}

/*
Problem: Longest Common Subsequence

  a c e 
a 3 2 1 0 
b 2 2 1 0 
c 2 2 1 0 
d 1 1 1 0 
e 1 1 1 0 
  0 0 0 0 

3

  a b c 
a 3 2 1 0 
b 2 2 1 0 
c 1 1 1 0 
  0 0 0 0 

3

  d e f 
a 0 0 0 0 
b 0 0 0 0 
c 0 0 0 0 
  0 0 0 0 

0
*/