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
    string longestCommonSubsequence(string text1, string text2) {
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

        string res = "";
        int idx1 = 0, idx2 = 0;
        while (idx1 < sz(text1) && idx2 < sz(text2)) {
            if (text1[idx1] == text2[idx2]) {
                res.pb(text1[idx1]);
                idx1++;
                idx2++;
            } else if (dp[idx1 + 1][idx2] > dp[idx1][idx2 + 1])
                idx1++;
            else
                idx2++;
        }

        return res;
    }
};
/*
Note: The doubt I encounter in Algorithm

Doubt:
- While building dp table if we are doing (i+1, j+1) only when there's a match.
- Then how can we do (i+1, j+1) while building the result string?
- As in the original algorithm we where doing (i+1, j+1) based on the current match status.
- But in the result building algorithm we don't have access to next match status, then on what bases we are doing (i+1, j+1) on current status match?

Clarification:
- If current status is matched then it's obvious that both (i, j) will not match with (i+1, j) and (i, j+1), that's why we skip these paths and switch to diagonal.
*/

int main() {
    Solution obj;
    auto res = obj.longestCommonSubsequence("ababa", "cbbcad");
    print(res);
    res = obj.longestCommonSubsequence("xyz", "abc");
    print(res);
    return 0;
}

/*
Problem: Print Longest Common Subsequence
*/