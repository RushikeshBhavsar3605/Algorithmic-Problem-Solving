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

/* Approach 1 (Breadth First Search) (Topological Sort): */
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        umap<int, vi> adj;
        iterate(edge, prerequisites)
            adj[edge[1]].pb(edge[0]);

        vi indeg(numCourses, 0);
        loop(i, 0, numCourses)
            iterate(it, adj[i])
                indeg[it]++;

        queue<int> q;
        loop(i, 0, numCourses)
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

        return topo.size() == numCourses ? topo : vi{};
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 0}};
    vi result = obj.findOrder(2, v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Course Schedule II
*/