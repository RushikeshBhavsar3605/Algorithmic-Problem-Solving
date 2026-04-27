#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach (DFS): */
class Solution {
  private:
    int n, m;
    vvi vis;
    vi canRight = {0, 1, 0, 0, 1, 0, 1};
    vi canLeft = {0, 1, 0, 1, 0, 1, 0};
    vi canUp = {0, 0, 1, 0, 0, 1, 1};
    vi canDown = {0, 0, 1, 1, 1, 0, 0};
    vvi dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool canMove(int curr, int next, int dir) {
        if (dir == 0)
            return canRight[curr] && canLeft[next];
        else if (dir == 1)
            return canLeft[curr] && canRight[next];
        else if (dir == 2)
            return canUp[curr] && canDown[next];
        else if (dir == 3)
            return canDown[curr] && canUp[next];

        return false;
    }

    bool dfs(int r, int c, vvi &grid) {
        if (r == n - 1 && c == m - 1)
            return true;

        vis[r][c] = 1;
        loop(i, 0, 4) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr < 0 || nr == n || nc < 0 || nc == m || vis[nr][nc] || !canMove(grid[r][c], grid[nr][nc], i))
                continue;

            if (dfs(nr, nc, grid))
                return true;
        }

        return false;
    }

  public:
    bool hasValidPath(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);
        vis.resize(n, vi(m, 0));

        return dfs(0, 0, grid);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{2, 4, 3}, {6, 5, 2}};
    auto res = obj.hasValidPath(v);
    print(res);
    v = {{1, 2, 1}, {1, 2, 1}};
    res = obj.hasValidPath(v);
    print(res);
    v = {{1, 1, 2}};
    res = obj.hasValidPath(v);
    print(res);
    return 0;
}

/*
Problem: Check if There is a Valid Path in a Grid
*/