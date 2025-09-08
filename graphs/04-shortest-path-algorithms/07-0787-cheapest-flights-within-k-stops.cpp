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

/* Approach 1 (Dijkstra Algorithm): */
class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        // Build adjacency list: node -> {destination, price}
        umap<int, vector<pii>> adj;
        iterate(it, flights)
            adj[it[0]].pb({it[1], it[2]});

        // Track minimum cost to reach each node
        vi dist(n, INT_MAX);
        dist[src] = 0;

        // Min-heap: {steps, cost, node} - prioritize by steps first
        priority_queue<vi, vvi, greater<vi>> minHeap;
        minHeap.push({0, 0, src});

        while (!minHeap.empty()) {
            int steps = minHeap.top()[0];
            int cost = minHeap.top()[1];
            int node = minHeap.top()[2];
            minHeap.pop();

            // Explore neighbors if within step limit
            iterate(it, adj[node]) {
                if (steps <= k && cost + it.ss < dist[it.ff]) {
                    dist[it.ff] = cost + it.ss;
                    minHeap.push({steps + 1, cost + it.ss, it.ff});
                }
            }
        }

        // Return cheapest price to destination or -1 if unreachable
        return dist[dst] != INT_MAX ? dist[dst] : -1;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << obj.findCheapestPrice(4, v, 0, 3, 1) << endl;
    v = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << obj.findCheapestPrice(3, v, 0, 2, 1) << endl;
    v = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << obj.findCheapestPrice(3, v, 0, 2, 0) << endl;
}

/*
Problem: Cheapest Flights Within K Stops
*/