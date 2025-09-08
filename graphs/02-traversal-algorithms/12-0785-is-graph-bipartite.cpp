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
    bool dfs(int node, int col, vi &color, vvi &graph) {
        color[node] = col;

        iterate(it, graph[node])
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph))
                    return false;
            }
            else if (color[it] == col)
                return false;

        return true;
    }

  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vi color(graph.size(), -1);
        loop(i, 0, graph.size())
            if (color[i] == -1)
                if (!dfs(i, 0, color, graph))
                    return false;

        return true;
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  private:
    bool check(int startNode, vi &color, vvi &graph) {
        queue<int> q;
        color[startNode] = 0;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            iterate(it, graph[node])
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
        }

        return true;
    }

  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vi color(graph.size(), -1);
        loop(i, 0, graph.size())
            if (color[i] == -1)
                if (!check(i, color, graph))
                    return false;

        return true;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    cout << obj.isBipartite(v);
    return 0;
}

/*
Problem: Is Graph Bipartite?
*/