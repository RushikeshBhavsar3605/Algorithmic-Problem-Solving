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

/* Approach 1 (Articulation Point): */
class Solution {
  private:
    int timer = 1;     // global DFS time counter (reset per solve if reusing the object)
    vi vis, disc, low; // vis: visited flag, disc: discovery time, low: lowest reachable disc

    void dfs(int node, int parent, vi adj[], vi &mark) {
        vis[node] = 1;
        disc[node] = low[node] = timer++; // set discovery time and initialize low-link
        int child = 0;                    // number of DFS tree children (used for root test)

        iterate(it, adj[node]) {
            if (it == parent)
                continue; // ignore the edge leading back to parent

            if (!vis[it]) { // tree-edge case
                child++;    // count a DFS child for root-condition
                dfs(it, node, adj, mark);

                updateMin(low[node], low[it]);             // propagate child's low-link up
                if (low[it] >= disc[node] && parent != -1) // non-root articulation condition
                    mark[node] = 1;                        // removing node separates child's subtree
            } else
                // back-edge to an ancestor: relax low using neighbor's discovery time
                updateMin(low[node], disc[it]);
        }

        if (child > 1 && parent == -1) // root is AP iff it has >1 DFS children
            mark[node] = 1;
    }

  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Note: set timer = 1 here if Solution instance might be reused across runs.
        vis.resize(V, 0);
        disc.resize(V, 0);
        low.resize(V, 0);

        vi mark(V, 0); // mark[u] == 1 iff u is an articulation point
        loop(i, 0, V)
            if (!vis[i])
                dfs(i, -1, adj, mark); // handle disconnected graphs

        vi result;
        loop(i, 0, V)
            if (mark[i])
                result.pb(i);

        if (!sz(result))
            return {-1}; // required output when no AP exists

        return result;
    }
};

int main() {
    Solution obj;
    vi v[] = {{1}, {4}, {3, 4}, {2, 4}, {1, 2, 3}};
    dump(obj.articulationPoints(5, v));
}

/*
Problem: Articulation Point - I
Link: https://www.geeksforgeeks.org/problems/articulation-point-1/1
*/