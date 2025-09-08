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

/* Approach 1 (Floyd Warshall Algorithm): */
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = sz(dist);

        // Floyd-Warshall: try all intermediate vertices k
        loop(k, 0, n)
            loop(i, 0, n)
                loop(j, 0, n)
                    // Update shortest path from i to j through k
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        updateMin(dist[i][j], dist[i][k] + dist[k][j]);

        /* Negative cycle detection
        loop(i,0,n)
            if (dist[i][i] < 0)  // If distance to self becomes negative
                return true;     // Negative cycle exists
        return false;
        */
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 4, (int)1e8, 5, (int)1e8},
             {(int)1e8, 0, 1, (int)1e8, 6},
             {2, (int)1e8, 0, 3, (int)1e8},
             {(int)1e8, (int)1e8, 1, 0, 2},
             {1, (int)1e8, (int)1e8, 4, 0}};
    obj.floydWarshall(v);
    dump2D(v);
}

/*
Problem: Floyd Warshall
Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
*/