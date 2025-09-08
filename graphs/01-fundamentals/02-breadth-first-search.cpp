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

class Solution {
  public:
    vi bfs(int n, vvi &adj) {
        vi result;
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            iterate(it, adj[node])
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
        }

        return result;
    }
};
/*
Time Complexity: O(n + (2 * E))
Space Complexity: O(n)
*/

int main() {
    Solution obj;
    int n = 9;
    vvi v = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    vvi graph(n);
    iterate(it, v) {
        int v = it[0], u = it[1];
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    vi result = obj.bfs(n, graph);
    iterate(it, result)
        cout << it << " ";
    return 0;
}

/*
Problem:
*/