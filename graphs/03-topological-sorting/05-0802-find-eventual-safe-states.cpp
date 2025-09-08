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

/* Approach 1 (Depth First Search):
class Solution {
  private:
    bool dfsCheck(int node, vvi &adj, vi &vis, vi &pathVis, vi &check) {
        vis[node] = 1;
        pathVis[node] = 1;

        iterate(it, adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathVis, check))
                    return true;
            } else if (pathVis[it])
                return true;
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vi vis(n, 0);
        vi pathVis(n, 0);
        vi check(n, 0);
        vi safeNodes;

        loop(i, 0, n)
            if (!vis[i])
                dfsCheck(i, graph, vis, pathVis, check);

        loop(i, 0, n)
            if (check[i] == 1)
                safeNodes.pb(i);

        return safeNodes;
    }
};
*/

/* Approach 2 (Depth First Search Optimized):
0 Not visited
1 Done visiting
2 Currently visiting in path

class Solution {
  private:
    bool dfsCheck(int node, vvi &adj, vi &vis, vi &check) {
        vis[node] = 2;

        iterate(it, adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, check))
                    return true;
            } else if (vis[it] == 2)
                return true;
        }

        check[node] = 1;
        vis[node] = 1;
        return false;
    }

  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vi vis(n, 0);
        vi check(n, 0);
        vi safeNodes;

        loop(i, 0, n)
            if (!vis[i])
                dfsCheck(i, graph, vis, check);

        loop(i, 0, n)
            if (check[i] == 1)
                safeNodes.pb(i);

        return safeNodes;
    }
};
*/

/* Approach 3 (Breadth First Search) (Topological Sort): */
class Solution {
  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = sz(graph);

        umap<int, vi> adj;
        vi indeg(n, 0);
        loop(i, 0, n)
            iterate(it, graph[i]) {
                adj[it].pb(i);
                indeg[i]++;
            }

        queue<int> q;
        loop(i, 0, n)
            if (indeg[i] == 0)
                q.push(i);

        vi safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safeNodes.pb(node);

            iterate(it, adj[node])
                if (--indeg[it] == 0)
                    q.push(it);
        }

        sort(all(safeNodes));
        return safeNodes;
    }
};

int main() {
    Solution obj;
    vvi v = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}};
    vi result = obj.eventualSafeNodes(v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Find Eventual Safe States
*/