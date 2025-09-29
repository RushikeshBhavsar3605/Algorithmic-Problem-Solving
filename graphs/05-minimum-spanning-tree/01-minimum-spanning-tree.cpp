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

/* Approach 1 (Prim's Algorithm): */
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> &edges) {
        // Build adjacency list: node -> {neighbor, weight}
        umap<int, vector<pii>> adj;
        iterate(edge, edges) {
            adj[edge[0]].pb({edge[1], edge[2]});
            adj[edge[1]].pb({edge[0], edge[2]});
        }

        // Min-heap: {weight, node} - always picks minimum weight edge
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        min_heap.push({0, 0}); // Start from node 0 with cost 0

        vi vis(V, 0);
        int sum = 0;
        // To store actual MST edges: vector<pii> mstEdges;

        while (!min_heap.empty()) {
            int cost = min_heap.top().ff;
            int node = min_heap.top().ss;
            min_heap.pop();

            if (vis[node])
                continue; // Skip if already in MST

            vis[node] = 1; // Add node to MST
            sum += cost;   // Add edge weight to total
            // To store edge: if(cost > 0) mstEdges.pb({parent[node], node});

            // Add all unvisited neighbors to heap
            iterate(it, adj[node]) {
                int edgeNode = it.ff;
                int edgeCost = it.ss;
                if (!vis[edgeNode]) {
                    min_heap.push({edgeCost, edgeNode});
                    // To track parent: parent[edgeNode] = node;
                }
            }
        }

        return sum; // Return total MST weight
        // To return edges: return {sum, mstEdges};
    }
};
/*
Time Complexity: O(E log V)
Space Complexity: O(V + E)
*/

int main() {
    Solution obj;
    vvi v = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    cout << obj.spanningTree(3, v) << endl;
    v = {{0, 1, 5}};
    cout << obj.spanningTree(2, v) << endl;
}

/*
Problem: Minimum Spanning Tree
Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/