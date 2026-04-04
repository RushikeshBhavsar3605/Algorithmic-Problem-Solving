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
    int solve(int childIdx, int cookieIdx, vec<int> &childs, vec<int> &cookies, vec<vec<int>> &memo) {
        if (childIdx == sz(childs) || cookieIdx == sz(cookies))
            return 0;

        if (memo[childIdx][cookieIdx] != -1)
            return memo[childIdx][cookieIdx];

        int result = 0;

        if (childs[childIdx] <= cookies[cookieIdx])
            updateMax(result, solve(childIdx + 1, cookieIdx + 1, childs, cookies, memo) + 1);

        updateMax(result, solve(childIdx, cookieIdx + 1, childs, cookies, memo));

        return memo[childIdx][cookieIdx] = result;
    }

  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(all(g));
        sort(all(s));

        vec<vec<int>> memo(sz(g), vec<int>(sz(s), -1));
        return solve(0, 0, g, s, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int n = sz(g), m = sz(s);
        sort(all(g));
        sort(all(s));

        vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                int res = 0;

                if (g[i] <= s[j])
                    updateMax(res, dp[i + 1][j + 1] + 1);
                updateMax(res, dp[i][j + 1]);

                dp[i][j] = res;
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 3 (Greedy): */
class Solution {
  public:
    int findContentChildren(vector<int> &child, vector<int> &cookies) {
        int n = sz(child), m = sz(cookies);
        sort(all(child));
        sort(all(cookies));

        int childIdx = 0;
        int cookieIdx = 0;

        while (childIdx != sz(child) && cookieIdx != sz(cookies)) {
            if (child[childIdx] <= cookies[cookieIdx])
                childIdx++;

            cookieIdx++;
        }

        return childIdx;
    }
};

int main() {
    Solution obj;
    vec<int> g = {1, 2, 3};
    vec<int> s = {1, 1};
    auto res = obj.findContentChildren(g, s);
    print(res);
    g = {1, 2};
    s = {1, 2, 3};
    res = obj.findContentChildren(g, s);
    print(res);
    return 0;
}

/*
Problem: Assign Cookies
*/