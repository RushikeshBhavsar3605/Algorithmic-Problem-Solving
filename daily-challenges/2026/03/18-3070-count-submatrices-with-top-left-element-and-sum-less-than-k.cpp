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

/* Approach 1 (2D Prefix Sum): */
class Solution {
  public:
    int countSubmatrices(vector<vector<int>> &grid, int k) {
        int n = sz(grid);
        int m = sz(grid[0]);

        int count = 0;

        loop(row, 0, n)
            loop(col, 0, m) {
                int diagonal = (row != 0 && col != 0) ? grid[row - 1][col - 1] : 0;
                int top = (row != 0) ? grid[row - 1][col] : 0;
                int left = (col != 0) ? grid[row][col - 1] : 0;

                grid[row][col] += (top + left) - diagonal;

                if (grid[row][col] <= k)
                    count++;
            }

        return count;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{7, 6, 3}, {6, 6, 1}};
    auto res = obj.countSubmatrices(v, 18);
    print(res);
    v = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    res = obj.countSubmatrices(v, 20);
    print(res);
    return 0;
}

/*
Problem: Count Submatrices with Top-Left Element and Sum Less Than k
*/