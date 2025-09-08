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

/* Approach 1 (Dijkstra's algorithm): */
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        // build adjacency list (0-indexed)
        umap<int, vector<pii>> adj;
        iterate(it, edges) {
            adj[it[0] - 1].pb({it[1] - 1, it[2]});
            adj[it[1] - 1].pb({it[0] - 1, it[2]});
        }

        // set to pick node with smallest distance
        set<pii> st;
        st.insert({0, 0});

        // parent array to reconstruct path
        vi parent(n, -1);

        // distance array
        vi dist(n, INT_MAX);
        dist[0] = 0;

        // Dijkstra's algorithm
        while (!st.empty()) {
            auto itt = *(st.begin());
            int dis = itt.ff;  // current distance
            int node = itt.ss; // current node
            st.erase(itt);

            // relax edges
            iterate(it, adj[node]) {
                int edgeWeight = it.ss;
                int edgeNode = it.ff;

                if (dis + edgeWeight < dist[edgeNode]) {
                    // remove old entry if exists
                    if (dist[edgeNode] != INT_MAX)
                        st.erase({dist[edgeNode], edgeNode});

                    parent[edgeNode] = node;               // update parent
                    dist[edgeNode] = dis + edgeWeight;     // update distance
                    st.insert({dist[edgeNode], edgeNode}); // push new distance
                }
            }
        }

        // no path exists
        if (dist[n - 1] == INT_MAX)
            return {-1};

        // reconstruct path from n-1 to 0
        vi result;
        int idx = n - 1;
        while (idx != -1) {
            result.pb(idx + 1); // convert back to 1-index
            idx = parent[idx];
        }

        reverse(all(result)); // reverse to get path from 0 to n-1
        return result;
    }
};

int main() {
    Solution obj;
    vvi e = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vi result = obj.shortestPath(5, 6, e);
    dump(result);
}

/*
Problem:
*/