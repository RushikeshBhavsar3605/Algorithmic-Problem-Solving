#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

/* Approach 1 (Breadth First Search):
class Solution {
  private:
    bool detect(int startNode, unordered_map<int, vi> &adj, vector<bool> &vis) {
        vis[startNode] = true;
        queue<pii> q;
        q.push({startNode, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            iterate(adjNode, adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = true;
                    q.push({adjNode, node});
                } else if (parent != adjNode)
                    return true;
            }
        }

        return false;
    }

  public:
    bool isCycle(int n, vvi &graph) {
        unordered_map<int, vi> adj;
        iterate(it, graph) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        loop(i, 0, n) {
            if (!vis[i])
                if (detect(i, adj, vis))
                    return true;
        }

        return false;
    }
};
*/

/* Approach 2 (Depth First Search): */
class Solution {
  private:
    bool detect(int node, int parent, unordered_map<int, vi> &adj, vector<bool> &vis) {
        vis[node] = true;
        iterate(adjNode, adj[node]) {
            if (!vis[adjNode]) {
                if (detect(adjNode, node, adj, vis))
                    return true;
            } else if (parent != adjNode)
                return true;
        }

        return false;
    }

  public:
    bool isCycle(int n, vvi &graph) {
        unordered_map<int, vi> adj;
        iterate(it, graph) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        loop(i, 0, n) {
            if (!vis[i])
                if (detect(i, -1, adj, vis))
                    return true;
        }

        return false;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2}, {1, 3}, {2, 5}, {3, 6}, {5, 7}, {6, 7}, {3, 4}};
    cout << obj.isCycle(8, v);
    return 0;
}

/*
Problem:
*/