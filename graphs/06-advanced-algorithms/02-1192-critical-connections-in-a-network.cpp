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

/* Approach 1 (Tarjan's Algorithm): */
class Solution {
  private:
    int timer = 1;     // global timestamp
    vi vis, disc, low; // steps = discovery time, minTime = low-link

    void dfs(int node, int parent, umap<int, vi> &adj, vvi &bridges) {
        vis[node] = 1;
        disc[node] = low[node] = timer++; // time-in and initialize low-link

        iterate(it, adj[node]) {
            if (it == parent)
                continue; // ignore the edge to parent

            if (!vis[it]) {
                dfs(it, node, adj, bridges); // tree edge

                updateMin(low[node], low[it]); // propagate child's low-link up
                if (low[it] > disc[node])      // bridge if child cannot reach an ancestor of node
                    bridges.pb({node, it});
            } else
                // back-edge to an ancestor: use neighbor's discovery time (not its low-link)
                updateMin(low[node], low[it]);
        }
    }

  public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        vis.resize(n, 0);
        disc.resize(n, 0);
        low.resize(n, 0);

        umap<int, vi> adj;
        iterate(it, connections) {
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }

        vvi bridges;
        // For disconnected graphs, run DFS from every unvisited node
        dfs(0, -1, adj, bridges);

        return bridges;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vvi result = obj.criticalConnections(4, v);
    dump2D(result);

    v = {{0, 1}};
    result = obj.criticalConnections(2, v);
    dump2D(result);
}

/*
Problem: Critical Connections in a Network
*/