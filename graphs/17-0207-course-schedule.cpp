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
    bool dfsCheck(int node, vi &vis, umap<int, vi> &adj) {
        vis[node] = 2;

        iterate(it, adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, vis, adj))
                    return true;
            } else if (vis[it] == 2)
                return true;
        }

        vis[node] = 1;
        return false;
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        umap<int, vi> adj;
        iterate(edge, prerequisites)
            adj[edge[0]].pb(edge[1]);

        vi vis(numCourses, 0);
        loop(i, 0, numCourses)
            if (!vis[i])
                if (dfsCheck(i, vis, adj))
                    return false;

        return true;
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        umap<int, vi> adj;
        iterate(edge, prerequisites)
            adj[edge[0]].pb(edge[1]);

        vi indeg(numCourses, 0);
        loop(i, 0, numCourses)
            iterate(it, adj[i])
                indeg[it]++;

        queue<int> q;
        loop(i, 0, numCourses)
            if (indeg[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            iterate(it, adj[node])
                if (--indeg[it] == 0)
                    q.push(it);
        }

        return count == numCourses;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 0}};
    cout << obj.canFinish(2, v);
    return 0;
}

/*
Problem: Course Schedule
*/