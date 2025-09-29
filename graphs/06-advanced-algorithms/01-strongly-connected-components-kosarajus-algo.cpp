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

/* Approach 1 (Kosaraju's Algorithm): */
class Solution {
  private:
    // DFS 1: explore graph and push node when all descendants are done (records finish time order)
    void dfs(int node, vi &vis, vvi &adj, stack<int> &st) {
        vis[node] = 1;         // mark visited
        iterate(it, adj[node]) // visit all outgoing edges
            if (!vis[it])
                dfs(it, vis, adj, st);

        st.push(node); // push after exploring children (postorder)
    }

    // DFS 2 on transpose: marks all nodes in the same SCC as 'node'
    void dfs3(int node, vi &vis, vvi &adjT) {
        vis[node] = 1;          // mark visited in transpose
        iterate(it, adjT[node]) // follow reversed edges
            if (!vis[it])
                dfs3(it, vis, adjT);
    }

  public:
    // Kosaraju: count strongly connected components in directed graph
    int kosaraju(vector<vector<int>> &adj) {
        int n = sz(adj); // number of vertices
        vi vis(n, 0);
        stack<int> st;

        // Pass 1: run DFS to fill stack by finish times
        loop(i, 0, n)
            if (!vis[i])
                dfs(i, vis, adj, st);

        // Build transpose graph (reverse every edge u -> v to v -> u) and reset visited
        vvi adjT(n);
        loop(i, 0, n) {
            vis[i] = 0;         // reset for second pass
            iterate(it, adj[i])
                adjT[it].pb(i); // reverse edge
        }

        // Pass 2: pop in decreasing finish time; each DFS on transpose = one SCC
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;                 // new SCC discovered
                dfs3(node, vis, adjT); // mark entire SCC
            }
        }

        return scc; // total number of SCCs
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 3}, {0}, {1}, {4}, {}};
    cout << obj.kosaraju(v) << endl;
}

/*
Problem: Strongly Connected
*/