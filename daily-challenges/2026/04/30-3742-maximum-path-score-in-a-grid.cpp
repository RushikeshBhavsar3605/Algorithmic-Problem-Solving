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

/* Approach 1 (Memoization) (TLE):
class Solution {
  private:
    int n, m;
    int dfs(int r, int c, vvi &grid, int k, int score, int cost, nvec_t<int, 4> &memo) {
        if (r == n || c == m)
            return -1;

        if (memo[r][c][score][cost] != -1)
            return memo[r][c][score][cost];

        int res = -1;
        int currScore = grid[r][c];
        int currCost = grid[r][c] > 0 ? 1 : 0;

        if (r == n - 1 && c == m - 1)
            return cost + currCost <= k ? score + currScore : -1;

        updateMax(res, dfs(r + 1, c, grid, k, score + currScore, cost + currCost, memo));
        updateMax(res, dfs(r, c + 1, grid, k, score + currScore, cost + currCost, memo));

        return memo[r][c][score][cost] = res;
    }

  public:
    int maxPathScore(vector<vector<int>> &grid, int k) {
        n = sz(grid);
        m = sz(grid[0]);
        int totalScore = 0;
        int totalCost = 0;
        iterate(it, grid)
            iterate(i, it) {
                totalScore += i;
                totalCost += i > 0;
            }

        nvec_t<int, 4> memo(n, nvec_t<int, 3>(m, vvi(totalScore, vi(totalCost, -1))));

        return dfs(0, 0, grid, k, 0, 0, memo);
    }
};
*/

/* Approach 2 (Optimized Memoization):
class Solution {
  private:
    int n, m;
    int dfs(int r, int c, int usedCost, vvi &grid, int k, nvec_t<int, 3> &memo) {
        if (r == n || c == m)
            return -1;

        int &res = memo[r][c][usedCost];
        if (res != -2)
            return res;

        int cost = (grid[r][c] > 0 ? 1 : 0);
        if (usedCost + cost > k)
            return -1;

        if (r == n - 1 && c == m - 1)
            return res = grid[r][c];

        int down = dfs(r + 1, c, usedCost + cost, grid, k, memo);
        int right = dfs(r, c + 1, usedCost + cost, grid, k, memo);

        int bestNext = max(down, right);
        if (bestNext == -1)
            return res = bestNext;

        return res = grid[r][c] + bestNext;
    }

  public:
    int maxPathScore(vector<vector<int>> &grid, int k) {
        n = sz(grid);
        m = sz(grid[0]);
        nvec_t<int, 3> memo(n, vvi(m, vi(k + 1, -2)));

        return dfs(0, 0, 0, grid, k, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int maxPathScore(vector<vector<int>> &grid, int k) {
        int n = sz(grid);
        int m = sz(grid[0]);
        nvec_t<int, 3> dp(n + 1, vvi(m + 1, vi(k + 1, -1)));

        loop(used, 0, k + 1) {
            int cost = (grid[n - 1][m - 1] > 0 ? 1 : 0);
            if (used + cost <= k)
                dp[n - 1][m - 1][used] = grid[n - 1][m - 1];
        }

        revloop(r, n - 1, 0)
            revloop(c, m - 1, 0) {
                if (r == n - 1 && c == m - 1)
                    continue;

                revloop(used, k, 0) {
                    int cost = (grid[r][c] > 0 ? 1 : 0);
                    if (used + cost > k) {
                        dp[r][c][used] = -1;
                        continue;
                    }

                    int down = dp[r + 1][c][used + cost];
                    int right = dp[r][c + 1][used + cost];

                    int bestNext = max(down, right);
                    if (bestNext == -1)
                        dp[r][c][used] = bestNext;
                    else
                        dp[r][c][used] = grid[r][c] + bestNext;
                }
            }

        return dp[0][0][0];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int maxPathScore(vector<vector<int>> &grid, int k) {
        int n = sz(grid);
        int m = sz(grid[0]);
        vvi curr(m + 1, vi(k + 1, -1));
        vvi next(m + 1, vi(k + 1, -1));

        loop(used, 0, k + 1) {
            int cost = (grid[n - 1][m - 1] > 0 ? 1 : 0);
            if (used + cost <= k)
                curr[m - 1][used] = next[m - 1][used] = grid[n - 1][m - 1];
        }

        revloop(r, n - 1, 0) {
            revloop(c, m - 1, 0) {
                if (r == n - 1 && c == m - 1)
                    continue;

                revloop(used, k, 0) {
                    int cost = (grid[r][c] > 0 ? 1 : 0);
                    if (used + cost > k) {
                        curr[c][used] = -1;
                        continue;
                    }

                    int down = next[c][used + cost];
                    int right = curr[c + 1][used + cost];

                    int bestNext = max(down, right);
                    if (bestNext == -1)
                        curr[c][used] = bestNext;
                    else
                        curr[c][used] = grid[r][c] + bestNext;
                }
            }

            swap(curr, next);
        }

        return next[0][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{0, 1}, {2, 0}};
    auto res = obj.maxPathScore(v, 1);
    print(res);
    v = {{0, 1}, {1, 2}};
    res = obj.maxPathScore(v, 1);
    print(res);
    return 0;
}

/*
Problem: Maximum Path Score in a Grid
*/