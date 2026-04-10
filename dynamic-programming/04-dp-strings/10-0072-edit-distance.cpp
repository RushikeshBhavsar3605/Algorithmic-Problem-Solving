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

/* Approach 1 (Tabulation):
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n = sz(word1);
        int m = sz(word2);

        vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));
        loop(i, 0, n + 1)
            dp[i][m] = n - i;
        loop(j, 0, m + 1)
            dp[n][j] = m - j;

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (word1[i] != word2[j]) {
                    int insert = dp[i][j + 1];
                    int remove = dp[i + 1][j];
                    int replace = dp[i + 1][j + 1];

                    dp[i][j] = min({insert, remove, replace}) + 1;
                } else
                    dp[i][j] = dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 2 (Space Optimization): */
class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n = sz(word1);
        int m = sz(word2);

        vec<int> curr(m + 1, 0);
        vec<int> next(m + 1, 0);
        loop(j, 0, m + 1)
            next[j] = m - j;

        revloop(i, n - 1, 0) {
            curr[m] = n - i;

            revloop(j, m - 1, 0) {
                if (word1[i] != word2[j]) {
                    int insert = curr[j + 1];
                    int remove = next[j];
                    int replace = next[j + 1];

                    curr[j] = min({insert, remove, replace}) + 1;
                } else
                    curr[j] = next[j + 1];
            }

            swap(curr, next);
        }

        return next[0];
    }
};

int main() {
    Solution obj;
    auto res = obj.minDistance("horse", "ros");
    print(res);
    res = obj.minDistance("intention", "execution");
    print(res);
    return 0;
}

/*
Problem: Edit Distance

  r o s
h 3 3 4 5
o 3 2 3 4
r 2 2 2 3
s 3 2 1 2
e 3 2 1 1
  3 2 1 0

3

  e x e c u t i o n
i 5 5 5 5 5 5 6 7 8 9
n 4 4 4 4 4 4 5 6 7 8
t 4 3 3 3 3 3 4 5 6 7
e 4 3 2 2 2 2 3 4 5 6
n 5 4 3 2 1 1 2 3 4 5
t 5 4 3 2 1 0 1 2 3 4
i 6 5 4 3 2 1 0 1 2 3
o 7 6 5 4 3 2 1 0 1 2
n 8 7 6 5 4 3 2 1 0 1
  9 8 7 6 5 4 3 2 1 0

5
*/