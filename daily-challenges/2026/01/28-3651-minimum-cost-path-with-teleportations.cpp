#include <bits/stdc++.h>
using namespace std;

// ---------- Types ----------
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> using vec = vector<T>;

template <class K, class V> using umap = unordered_map<K, V>;

template <class T> using uset = unordered_set<T>;

// ---------- STL Shortcuts ----------
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    (v).erase(unique(all(v)), (v).end())

// ---------- Loops ----------
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define revloop(i, a, b) for (int i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : a)

// ---------- Min / Max ----------
#define updateMin(a, b) ((a) = min((a), (b)))
#define updateMax(a, b) ((a) = max((a), (b)))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

class Solution {
  public:
    int minCost(vector<vector<int>> &grid, int k) {
        int n = sz(grid), m = sz(grid[0]);
        vec<vec<vec<int>>> dist(n, vec<vec<int>>(m, vec<int>(k + 1, INT_MAX)));

        vec<pair<int, pii>> vals;

        loop(i, 0, n)
            loop(j, 0, m)
                vals.pb({grid[i][j], {i, j}});

        sort(all(vals));

        vec<vec<int>> pos(n, vec<int>(m));
        vec<vec<int>> sortedDist(k + 1, vec<int>(n * m));
        vec<vec<int>> prefixMin(k + 1, vec<int>(n * m));

        loop(i, 0, n * m)
            pos[vals[i].ss.ff][vals[i].ss.ss] = i;

        revloop(nums, k, 0) {
            if (nums != k) {
                loop(i, 0, n)
                    loop(j, 0, m) {
                        auto it = upper_bound(all(vals), make_pair(grid[i][j], make_pair(n, m)));
                        dist[i][j][nums] = min(dist[i][j][nums], prefixMin[nums + 1][it - vals.begin() - 1]);
                    }
            }

            dist[n - 1][m - 1][nums] = 0;
            revloop(i, n - 1, 0)
                revloop(j, m - 1, 0) {
                    if (i != 0)
                        dist[i - 1][j][nums] = min(dist[i - 1][j][nums], dist[i][j][nums] + grid[i][j]);
                    if (j != 0)
                        dist[i][j - 1][nums] = min(dist[i][j - 1][nums], dist[i][j][nums] + grid[i][j]);
                }

            loop(i, 0, n)
                loop(j, 0, m)
                    sortedDist[nums][pos[i][j]] = dist[i][j][nums];

            prefixMin[nums][0] = sortedDist[nums][0];
            loop(i, 1, n * m)
                prefixMin[nums][i] = min(prefixMin[nums][i - 1], sortedDist[nums][i]);
        }

        return dist[0][0][0];
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
    println(obj.minCost(v, 2));
    v = {{1, 2}, {2, 3}, {3, 4}};
    println(obj.minCost(v, 1));
}

/*
Problem: Minimum Cost Path with Teleportations
*/