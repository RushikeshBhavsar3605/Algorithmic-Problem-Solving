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

class Solution {
  private:
    ll total;

    vec<vec<int>> reversedRows(vec<vec<int>> grid) {
        reverse(all(grid));
        return grid;
    }

    vec<vec<int>> transposed(const vec<vec<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vec<vec<int>> res(m, vec<int>(n));
        loop(i, 0, n)
            loop(j, 0, m)
                res[j][i] = grid[i][j];

        return res;
    }

    bool check(const vec<vec<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        uset<ll> seen;
        seen.reserve((size_t)n * m * 2 + 1);

        ll curr = 0;
        loop(i, 0, n - 1) {
            loop(j, 0, m) {
                curr += grid[i][j];
                seen.insert(grid[i][j]);
            }

            ll diff = curr - (total - curr);

            if (diff == 0)
                return true;

            if (i > 0 && m > 1) {
                if (seen.count(diff))
                    return true;
            } else if (i == 0) {
                if (grid[0][0] == diff || grid[0][m - 1] == diff)
                    return true;
            } else if (grid[0][0] == diff || grid[i][0] == diff)
                return true;
        }

        return false;
    }

  public:
    bool canPartitionGrid(vector<vector<int>> &grid) {
        total = 0;
        iterate(row, grid)
            iterate(it, row)
                total += it;

        if (grid.empty() || grid[0].empty())
            return false;

        return check(grid) ||
               check(reversedRows(grid)) ||
               check(transposed(grid)) ||
               check(reversedRows(transposed(grid)));
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{1, 4}, {2, 3}};
    auto res = obj.canPartitionGrid(v);
    print(res);
    v = {{1, 2}, {3, 4}};
    res = obj.canPartitionGrid(v);
    print(res);
    v = {{1, 2, 4}, {2, 3, 5}};
    res = obj.canPartitionGrid(v);
    print(res);
    return 0;
}

/*
Problem: Equal Sum Grid Partition II
*/