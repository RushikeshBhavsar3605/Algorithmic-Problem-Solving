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

/* Approach 1 (Heap):
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // build adjacency list (undirected graph)
        umap<int, vector<pii>> adj;
        iterate(it, edges) {
            adj[it[0]].pb({it[1], it[2]});
            adj[it[1]].pb({it[0], it[2]});
        }

        // min-heap: {distance, node}
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        min_heap.push({0, src});

        // distance array, initialized to INF
        vi dist(V, INT_MAX);
        dist[src] = 0;

        while (!min_heap.empty()) {
            int dis = min_heap.top().ff;  // current distance
            int node = min_heap.top().ss; // current node
            min_heap.pop();

            // relax all adjacent edges
            iterate(it, adj[node]) {
                int edgeWeight = it.ss;
                int edgeNode = it.ff;

                if (dis + edgeWeight < dist[edgeNode]) {
                    dist[edgeNode] = dis + edgeWeight;         // update shorter path
                    min_heap.push({dist[edgeNode], edgeNode}); // push updated dist
                }
            }
        }

        return dist; // shortest distance from src to every node
    }
};

Time Complexity: E log V
Space Complexity: E log V
*/

/* Approach 2 (Set) (Slight Time Complexity Optimization): */
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // build adjacency list (undirected graph)
        umap<int, vector<pii>> adj;
        iterate(it, edges) {
            adj[it[0]].pb({it[1], it[2]});
            adj[it[1]].pb({it[0], it[2]});
        }

        // set stores {distance, node} sorted by distance
        set<pii> st;
        st.insert({0, src});

        // distance array
        vi dist(V, INT_MAX);
        dist[src] = 0;

        while (!st.empty()) {
            auto itt = *(st.begin()); // pick node with smallest distance
            int dis = itt.ff;
            int node = itt.ss;
            st.erase(itt);

            // relax all neighbors
            iterate(it, adj[node]) {
                int edgeWeight = it.ss;
                int edgeNode = it.ff;

                if (dis + edgeWeight < dist[edgeNode]) {
                    if (dist[edgeNode] != INT_MAX)
                        st.erase({dist[edgeNode], edgeNode}); // remove old entry

                    dist[edgeNode] = dis + edgeWeight;     // update dist
                    st.insert({dist[edgeNode], edgeNode}); // push new dist
                }
            }
        }

        return dist; // shortest dist from src to all nodes
    }
};

int main() {
    Solution obj;
    vvi e = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
    vi result = obj.dijkstra(3, e, 2);
    dump(result);
}

/*
Problem: Dijkstra Algorithm
*/