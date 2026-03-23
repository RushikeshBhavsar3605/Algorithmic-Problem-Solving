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

/* Approach 1 (Recursion):
class Solution {
  private:
    int MOD = 1e9 + 7;
    int n, m;

    pair<ll, ll> solve(int row, int col, vec<vec<int>> &grid) {
        if (row == n - 1 && col == m - 1)
            return {grid[row][col], grid[row][col]};

        ll maxi = LLONG_MIN, mini = LLONG_MAX;

        if (col != m - 1) {
            auto [rmax, rmin] = solve(row, col + 1, grid);
            maxi = max({maxi, rmax * grid[row][col], rmin * grid[row][col]});
            mini = min({mini, rmax * grid[row][col], rmin * grid[row][col]});
        }

        if (row != n - 1) {
            auto [dmax, dmin] = solve(row + 1, col, grid);
            maxi = max({maxi, dmax * grid[row][col], dmin * grid[row][col]});
            mini = min({mini, dmax * grid[row][col], dmin * grid[row][col]});
        }

        return {maxi, mini};
    }

  public:
    int maxProductPath(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);
        auto [maxi, _] = solve(0, 0, grid);

        return maxi >= 0 ? maxi % MOD : -1;
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int n, m;
    int MOD = 1e9 + 7;
    vec<vec<pair<ll, ll>>> memo;
    vec<vec<bool>> vis;

    pair<ll, ll> solve(int row, int col, vec<vec<int>> &grid) {
        if (row == n - 1 && col == m - 1)
            return {grid[row][col], grid[row][col]};

        if (vis[row][col])
            return memo[row][col];
        vis[row][col] = true;

        ll maxi = LLONG_MIN, mini = LLONG_MAX;

        if (col != m - 1) {
            auto [rmax, rmin] = solve(row, col + 1, grid);
            maxi = max({maxi, rmax * grid[row][col], rmin * grid[row][col]});
            mini = min({mini, rmax * grid[row][col], rmin * grid[row][col]});
        }

        if (row != n - 1) {
            auto [dmax, dmin] = solve(row + 1, col, grid);
            maxi = max({maxi, dmax * grid[row][col], dmin * grid[row][col]});
            mini = min({mini, dmax * grid[row][col], dmin * grid[row][col]});
        }

        return memo[row][col] = {maxi, mini};
    }

  public:
    int maxProductPath(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);
        memo.assign(n, vec<pair<ll, ll>>(m));
        vis.assign(n, vec<bool>(m, false));

        auto [maxi, _] = solve(0, 0, grid);
        return maxi >= 0 ? maxi % MOD : -1;
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  private:
  public:
    int maxProductPath(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);
        int MOD = 1e9 + 7;
        vec<vec<pair<ll, ll>>> dp(n, vec<pair<ll, ll>>(m));
        dp[n - 1][m - 1] = {grid[n - 1][m - 1], grid[n - 1][m - 1]};

        revloop(row, n - 1, 0) {
            revloop(col, m - 1, 0) {
                if (row == n - 1 && col == m - 1)
                    continue;

                ll maxi = LLONG_MIN, mini = LLONG_MAX;

                if (col != m - 1) {
                    auto [rmax, rmin] = dp[row][col + 1];
                    maxi = max({maxi, rmax * grid[row][col], rmin * grid[row][col]});
                    mini = min({mini, rmax * grid[row][col], rmin * grid[row][col]});
                }

                if (row != n - 1) {
                    auto [dmax, dmin] = dp[row + 1][col];
                    maxi = max({maxi, dmax * grid[row][col], dmin * grid[row][col]});
                    mini = min({mini, dmax * grid[row][col], dmin * grid[row][col]});
                }

                dp[row][col] = {maxi, mini};
            }
        }

        return dp[0][0].first >= 0 ? dp[0][0].first % MOD : -1;
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  private:
  public:
    int maxProductPath(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);
        int MOD = 1e9 + 7;
        vec<pair<ll, ll>> curr(m);
        vec<pair<ll, ll>> next(m);
        curr[m - 1] = {grid[n - 1][m - 1], grid[n - 1][m - 1]};

        revloop(row, n - 1, 0) {
            revloop(col, m - 1, 0) {
                if (row == n - 1 && col == m - 1)
                    continue;

                ll maxi = LLONG_MIN, mini = LLONG_MAX;

                if (col != m - 1) {
                    auto [rmax, rmin] = curr[col + 1];
                    maxi = max({maxi, rmax * grid[row][col], rmin * grid[row][col]});
                    mini = min({mini, rmax * grid[row][col], rmin * grid[row][col]});
                }

                if (row != n - 1) {
                    auto [dmax, dmin] = next[col];
                    maxi = max({maxi, dmax * grid[row][col], dmin * grid[row][col]});
                    mini = min({mini, dmax * grid[row][col], dmin * grid[row][col]});
                }

                curr[col] = {maxi, mini};
            }

            swap(curr, next);
        }

        return next[0].first >= 0 ? next[0].first % MOD : -1;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}};
    auto res = obj.maxProductPath(v);
    print(res);
    v = {{1, -2, 1}, {1, -2, 1}, {3, -4, 1}};
    res = obj.maxProductPath(v);
    print(res);
    v = {{1, 3}, {0, -4}};
    res = obj.maxProductPath(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Non Negative Product in a Matrix
*/