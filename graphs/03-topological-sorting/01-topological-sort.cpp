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
    void dfs(int node, vi &vis, stack<int> &st, vvi &adj) {
        vis[node] = 1;
        iterate(it, adj[node])
            if (!vis[it])
                dfs(it, vis, st, adj);

        st.push(node);
    }

  public:
    vi topoSort(vvi &adj) {
        int n = sz(adj);
        vi vis(n, 0);
        stack<int> st;

        loop(i, 0, n)
            if (!vis[i])
                dfs(i, vis, st, adj);

        vi result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
*/

/* Approach 2 (Breadth First Search) (Kahn's Algorithm): */
class Solution {
  public:
    vi topoSort(vvi &adj) {
        int n = sz(adj);
        vi indeg(n, 0);

        loop(i, 0, n)
            iterate(it, adj[i])
                indeg[it]++;

        queue<int> q;
        loop(i, 0, n)
            if (indeg[i] == 0)
                q.push(i);

        vi topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.pb(node);

            iterate(it, adj[node])
                if (--indeg[it] == 0)
                    q.push(it);
        }

        return topo;
    }
};

/* Note:
1. Applies to:
    - Directed Acyclic Graphs (DAGs) only.
2. Use-cases:
    - Task scheduling, dependency resolution, build systems, etc.
3. Core idea:
    - Linear ordering of nodes such that for every directed edge u → v, node u comes before v.
4. Two main algorithms:
    - Kahn’s Algorithm (BFS):
        - Use in-degree array.
        - Queue nodes with in-degree 0.
        - Remove edges and update in-degrees.
        - Good for detecting cycles too (if result size < V → cycle exists).
    - DFS-based:
        - Post-order traversal, use a stack.
        - Detect cycles via coloring/visited status.
5. Cycle detection tip:
    - If not all nodes are included in the final topo order → cycle present.
6. Time complexity:
    - O(V + E) for both DFS and Kahn’s algorithm.
7. Space complexity:
    - O(V + E) for adjacency list and O(V) for in-degree/visited.
*/

int main() {
    Solution obj;
    vvi v = {{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}};
    vi result = obj.topoSort(v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem:
*/