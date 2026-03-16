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

struct Answer {
    array<int, 3> ans{};

    void put(int x) {
        if (x > ans[0])
            tie(ans[0], ans[1], ans[2]) = tuple{x, ans[0], ans[1]};
        else if (x != ans[0] && x > ans[1])
            tie(ans[1], ans[2]) = tuple{x, ans[1]};
        else if (x != ans[0] && x != ans[1] && x > ans[2])
            ans[2] = x;
    }

    vec<int> get() const {
        vec<int> ret;
        iterate(num, ans)
            if (num)
                ret.pb(num);

        return ret;
    }
};

class Solution {
  public:
    vector<int> getBiggestThree(vector<vector<int>> &grid) {
        int m = sz(grid), n = sz(grid[0]);
        vec<vec<int>> sum1(m + 1, vec<int>(n + 2));
        vec<vec<int>> sum2(m + 1, vec<int>(n + 2));

        loop(i, 1, m + 1) loop(j, 1, n + 1) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }

        Answer ans;
        loop(i, 0, m) loop(j, 0, n) {
            ans.put(grid[i][j]);

            for (int k = i + 2; k < m; k += 2) {
                int ux = i, uy = j;
                int dx = k, dy = j;
                int lx = (i + k) / 2, ly = j - (k - i) / 2;
                int rx = (i + k) / 2, ry = j + (k - i) / 2;

                if (ly < 0 || ry >= n)
                    break;

                ans.put((sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                        (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                        (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                        (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                        (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]));
            }
        }

        return ans.get();
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    auto res = obj.getBiggestThree(v);
    print(res);
    v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    res = obj.getBiggestThree(v);
    print(res);
    v = {{7, 7, 7}};
    res = obj.getBiggestThree(v);
    print(res);
    return 0;
}

/*
Problem: Get Biggest Three Rhombus Sums in a Grid
*/