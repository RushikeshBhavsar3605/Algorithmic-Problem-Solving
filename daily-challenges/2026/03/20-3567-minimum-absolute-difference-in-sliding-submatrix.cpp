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

/* Approach 1 (Brute Force TLE):
class Solution {
  public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
        int n = sz(grid);
        int m = sz(grid[0]);
        vec<vec<int>> res(n - k + 1, vec<int>(m - k + 1, 0));

        loop(row, 0, n - k + 1)
            loop(col, 0, m - k + 1) {
                int mini = INT_MAX;
                vec<vec<set<int>>> gridEle(n, vec<set<int>>(m));

                loop(newRow, row, row + k)
                    loop(newCol, col, col + k) {
                        set<int> diagonal = (newRow != row && newCol != col) ? gridEle[newRow - 1][newCol - 1] :
set<int>(); set<int> top = (newRow != row) ? gridEle[newRow - 1][newCol] : set<int>(); set<int> left = (newCol != col) ?
gridEle[newRow][newCol - 1] : set<int>();

                        gridEle[newRow][newCol].insert(grid[newRow][newCol]);
                        gridEle[newRow][newCol].insert(all(diagonal));
                        gridEle[newRow][newCol].insert(all(top));
                        gridEle[newRow][newCol].insert(all(left));

                        vec<int> temp = {all(gridEle[newRow][newCol])};
                        loop(i, 1, sz(temp)) updateMin(mini, abs(temp[i - 1] - temp[i]));
                    }

                res[row][col] = (mini != INT_MAX) ? mini : 0;
            }

        return res;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
        int n = sz(grid);
        int m = sz(grid[0]);
        vec<vec<int>> res(n - k + 1, vec<int>(m - k + 1));

        loop(i, 0, n - k + 1)
            loop(j, 0, m - k + 1) {
                vec<int> kGrid;
                loop(x, i, i + k)
                    loop(y, j, j + k)
                        kGrid.pb(grid[x][y]);

                int kmin = INT_MAX;
                sort(all(kGrid));

                loop(t, 1, sz(kGrid)) {
                    if (kGrid[t] == kGrid[t - 1])
                        continue;

                    updateMin(kmin, kGrid[t] - kGrid[t - 1]);
                }

                if (kmin != INT_MAX)
                    res[i][j] = kmin;
            }

        return res;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{1, 8}, {3, -2}};
    auto res = obj.minAbsDiff(v, 2);
    print(res);
    v = {{3, -1}};
    res = obj.minAbsDiff(v, 1);
    print(res);
    v = {{1, -2, 3}, {2, 3, 5}};
    res = obj.minAbsDiff(v, 2);
    print(res);
    return 0;
}

/*
Problem: Minimum Absolute Difference in Sliding Submatrix
*/