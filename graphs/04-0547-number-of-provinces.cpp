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

/* Approach 1 (Depth First Search):
class Solution {
  private:
    void helper(int node, unordered_map<int, vi> &adj, vector<bool> &vis) {
        vis[node] = true;

        iterate(it, adj[node]) {
            if (!vis[it])
                helper(it, adj, vis);
        }
    }

    int dfs(int numVertices, unordered_map<int, vi> &adj) {
        int count = 0;
        vector<bool> vis(numVertices, false);
        loop(i, 1, numVertices) {
            if (!vis[i]) {
                count++;
                helper(i, adj, vis);
            }
        }

        return count;
    }

  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        unordered_map<int, vi> adj;
        loop(i, 0, isConnected.size()) {
            loop(j, 0, isConnected[0].size()) {
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);
            }
        }
        return dfs(isConnected.size() + 1, adj);
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  private:
    void bfs(int startNode, unordered_map<int, vi> &adj, vector<bool> &vis) {
        queue<int> q;

        vis[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            iterate(it, adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }

  public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        unordered_map<int, vi> adj;
        loop(i, 0, isConnected.size()) {
            loop(j, 0, isConnected[0].size()) {
                if (isConnected[i][j] == 1)
                    adj[i + 1].push_back(j + 1);
            }
        }

        int count = 0;
        vector<bool> vis(n + 1, false);
        loop(i, 1, n + 1) {
            if (!vis[i]) {
                count++;
                bfs(i, adj, vis);
            }
        }

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << obj.findCircleNum(v);
    return 0;
}

/*
Problem: Number of Provinces
*/