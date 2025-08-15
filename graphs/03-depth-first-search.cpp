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
  private:
    void helper(int node, vvi &adj, vector<bool> &vis, vi &result) {
        vis[node] = true;
        result.push_back(node);

        iterate(it, adj[node]) {
            if (!vis[it])
                helper(it, adj, vis, result);
        }
    }

  public:
    vi dfs(int n, vvi &adj) {
        vi result;
        vector<bool> vis(n, false);
        loop(i, 0, n) {
            if (!vis[i])
                helper(i, adj, vis, result);
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
    vi result = obj.dfs(n, graph);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem:
*/