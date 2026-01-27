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

/* Approach 1 (Dijkstra's Algorithm): */
class Solution {
  public:
    int minCost(int n, vector<vector<int>> &edges) {
        // Build adjacency list
        // Forward edge: cost = w
        // Reverse edge: cost = 2 * w
        umap<int, vector<pii>> adj;
        iterate(it, edges) {
            adj[it[0]].pb({it[1], it[2]});     // u -> v
            adj[it[1]].pb({it[0], it[2] * 2}); // v -> u (penalized)
        }

        // Min-heap for Dijkstra: {currentDistance, node}
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, 0});

        // Distance array initialization
        vi dist(n, INT_MAX);
        dist[0] = 0;

        // Standard Dijkstra's algorithm
        while (!minHeap.empty()) {
            int distance = minHeap.top().ff;
            int node = minHeap.top().ss;
            minHeap.pop();

            // Relax all adjacent edges
            iterate(it, adj[node]) {
                int edgeWeight = it.ss;
                int edgeNode = it.ff;

                // Relaxation check
                if (distance + edgeWeight < dist[edgeNode]) {
                    dist[edgeNode] = distance + edgeWeight;
                    minHeap.push({dist[edgeNode], edgeNode});
                }
            }
        }

        // Return shortest distance to node n-1, or -1 if unreachable
        return dist[n - 1] != INT_MAX ? dist[n - 1] : -1;
    }
};

int main() {
    Solution obj;
    vvi e = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    println(obj.minCost(4, e));
    e = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
    println(obj.minCost(4, e));
}

/*
Problem: Minimum Cost Path with Edge Reversals
*/