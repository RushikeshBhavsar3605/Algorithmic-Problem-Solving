#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

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

/* Approach 1 (Proof of Contradiction): */
class Solution {
  public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k) {
        umap<int, vi> adj;
        iterate(it, edges) {
            int u = it[0], v = it[1];
            adj[u].pb(v);
            adj[v].pb(u);
        }

        int res = 0;

        function<int(int, int)> dfs = [&](int curr, int parent) -> int {
            int total = values[curr];

            iterate(child, adj[curr])
                if (child != parent)
                    total += dfs(child, curr);

            if (total % k == 0)
                res++;

            return total % k;
        };

        dfs(0, -1);

        return res;
    }
};

int main() {
    Solution obj;
    vvi v1 = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vi v2 = {1, 8, 1, 4, 4};
    println(obj.maxKDivisibleComponents(5, v1, v2, 6));
    v1 = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    v2 = {3, 0, 6, 1, 5, 2, 1};
    println(obj.maxKDivisibleComponents(7, v1, v2, 3));
}

/*
Problem: Maximum Number of K-Divisible Components
*/