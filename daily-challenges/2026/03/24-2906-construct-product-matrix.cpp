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

/* Approach 1 (Prefix + Suffix): */
class Solution {
  public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
        const int MOD = 12345;
        int n = sz(grid), m = sz(grid[0]);
        vec<vec<int>> res(n, vec<int>(m));

        ll suffix = 1;
        revloop(i, n - 1, 0)
            revloop(j, m - 1, 0) {
                res[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }

        ll prefix = 1;
        loop(i, 0, n)
            loop(j, 0, m) {
                res[i][j] = (res[i][j] * prefix) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }

        return res;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{1, 2}, {3, 4}};
    auto res = obj.constructProductMatrix(v);
    print(res);
    v = {{12345}, {2}, {1}};
    res = obj.constructProductMatrix(v);
    print(res);
    return 0;
}

/*
Problem: Construct Product Matrix
*/