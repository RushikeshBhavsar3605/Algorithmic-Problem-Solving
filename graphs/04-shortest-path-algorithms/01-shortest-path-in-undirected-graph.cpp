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

/* Approach 1 (Breadth First Search): */
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src) {
        int n = sz(adj);
        vi dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            iterate(it, adj[node])
                if (dist[it] == -1 || dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
        }

        return dist;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    vi result = obj.shortestPath(v, 0);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem:
*/