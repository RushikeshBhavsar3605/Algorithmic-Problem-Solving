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

/* Approach 1 (Dijkstra's Algorithm): */
class Solution {
  public:
    int countPaths(int n, vector<vector<int>> &roads) {
        int MOD = 1e9 + 7;

        // Build undirected adjacency list
        umap<int, vector<pii>> adj;
        iterate(it, roads) {
            adj[it[0]].pb({it[1], it[2]});
            adj[it[1]].pb({it[0], it[2]});
        }

        // Min heap for Dijkstra: (distance, node)
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> minHeap;
        minHeap.push({0, 0});

        // Track shortest distances to each node
        vector<ll> dist(n, LLONG_MAX);
        dist[0] = 0;

        // Count number of shortest paths to each node
        vi ways(n, 0);
        ways[0] = 1;

        // Modified Dijkstra to count paths
        while (!minHeap.empty()) {
            ll time = minHeap.top().ff;
            int node = minHeap.top().ss;
            minHeap.pop();

            // Explore all neighbors
            iterate(it, adj[node]) {
                ll currTime = time + it.ss;

                // Found shorter path - update distance and reset ways
                if (currTime < dist[it.ff]) {
                    dist[it.ff] = currTime;
                    minHeap.push({currTime, it.ff});

                    ways[it.ff] = ways[node];
                }
                // Found another shortest path - add to ways count
                else if (currTime == dist[it.ff])
                    ways[it.ff] = (ways[it.ff] + ways[node]) % MOD;
            }
        }

        // Return number of shortest paths to destination
        return ways[n - 1];
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3},
             {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    cout << obj.countPaths(7, v) << endl;
    v = {{1, 0, 10}};
    cout << obj.countPaths(2, v) << endl;
}

/*
Problem: Number of Ways to Arrive at Destination
*/