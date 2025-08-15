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

/* Approach 1 (Topological Sort): */
class Solution {
  private:
    void topoSort(int node, vector<vector<pii>> &adj, vi &vis, stack<int> &st) {
        vis[node] = 1;
        iterate(it, adj[node])
            if (!vis[it.first])
                topoSort(it.first, adj, vis, st);

        st.push(node);
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        vector<vector<pii>> adj(V);
        iterate(edge, edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].pb({v, wt});
        }

        vi vis(V, 0);
        stack<int> st;
        loop(i, 0, V)
            if (!vis[i])
                topoSort(i, adj, vis, st);

        vi dist(V, -1);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] == -1)
                continue;

            iterate(it, adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[v] == -1 || dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }

        return dist;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vi result = obj.shortestPath(6, 7, v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Shortest path in Directed Acyclic Graph
*/