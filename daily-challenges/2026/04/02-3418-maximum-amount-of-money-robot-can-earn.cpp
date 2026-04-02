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

/* Approach 1 (Memoization): */
class Solution {
  public:
    int maximumAmount(vector<vector<int>> &coins) {
        int n = sz(coins);
        int m = sz(coins[0]);
        vector memo(n, vector(m, array<int, 3>{INT_MIN, INT_MIN, INT_MIN}));

        function<int(int, int, int)> dfs = [&](int row, int col, int count) -> int {
            if (row == n || col == m)
                return INT_MIN;

            int curr = coins[row][col];
            if (row == n - 1 && col == m - 1)
                return count > 0 ? max(0, curr) : curr;

            if (memo[row][col][count] != INT_MIN)
                return memo[row][col][count];

            int res = max(dfs(row + 1, col, count), dfs(row, col + 1, count)) + curr;
            if (count > 0 && curr < 0)
                res = max({res, dfs(row + 1, col, count - 1), dfs(row, col + 1, count - 1)});

            return memo[row][col][count] = res;
        };

        return dfs(0, 0, 2);
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{0, 1, -1}, {1, -2, 3}, {2, -3, 4}};
    auto res = obj.maximumAmount(v);
    print(res);
    v = {{10, 10, 10}, {10, 10, 10}};
    res = obj.maximumAmount(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Amount of Money Robot Can Earn
*/