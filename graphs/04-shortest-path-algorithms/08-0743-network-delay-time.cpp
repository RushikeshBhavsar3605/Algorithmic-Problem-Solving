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
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        // Build adjacency list: node -> [(neighbor, weight)]
        umap<int, vector<pii>> adj;
        iterate(it, times)
            adj[it[0]].pb({it[1], it[2]});

        // Min heap for Dijkstra's algorithm: (distance, node)
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, k});

        // Distance array initialized to infinity, source distance = 0
        vi dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Dijkstra's algorithm
        while (!minHeap.empty()) {
            int time = minHeap.top().ff;
            int node = minHeap.top().ss;
            minHeap.pop();

            // Relax all neighbors
            iterate(it, adj[node]) {
                int currentTime = time + it.ss;

                // If shorter path found, update distance and add to heap
                if (currentTime < dist[it.ff]) {
                    dist[it.ff] = currentTime;
                    minHeap.push({currentTime, it.ff});
                }
            }
        }

        // Find maximum time among all nodes
        int time = 0;
        bool signal = true;
        loop(i, 1, n + 1) {
            // Check if any node is unreachable
            if (dist[i] == INT_MAX)
                signal = false;

            updateMax(time, dist[i]);
        }

        // Return max time if all nodes reachable, else -1
        return signal ? time : -1;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << obj.networkDelayTime(v, 4, 2) << endl;
    v = {{1, 2, 1}};
    cout << obj.networkDelayTime(v, 2, 1) << endl;
    v = {{1, 2, 1}};
    cout << obj.networkDelayTime(v, 2, 2) << endl;
}

/*
Problem: Network Delay Time
*/