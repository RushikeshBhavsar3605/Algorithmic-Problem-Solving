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

/* Approach 1 (Bellman Ford Algorithm): */
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src) {
        // Initialize distances to infinity, source to 0
        vi dist(V, 1e8);
        dist[src] = 0;

        // Relax all edges V-1 times
        while (V--) {
            iterate(it, edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                // Update distance if shorter path found
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }

        // Check for negative cycles
        iterate(it, edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // If we can still relax, negative cycle exists
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }

        // Return shortest distances
        return dist;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    dump(obj.bellmanFord(5, v, 0));
    v = {{0, 1, 4}, {1, 2, -6}, {2, 3, 5}, {3, 1, -2}};
    dump(obj.bellmanFord(4, v, 0));
}

/*
Problem: Bellman-Ford
Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/