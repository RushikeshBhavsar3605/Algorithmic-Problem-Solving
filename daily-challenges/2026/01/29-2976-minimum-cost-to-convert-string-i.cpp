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

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Dijkstra's Algorithm):
class Solution {
  private:
    // Dijkstra from a single source character
    void dijkstra(int src, umap<int, vector<pii>> &adj, vi &dist) {
        // init: min-heap and source distance
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        dist[src] = 0;
        minHeap.push({0, src});

        // loop: process nodes with minimum current cost
        while (!minHeap.empty()) {
            int cost = minHeap.top().ff;
            int node = minHeap.top().ss;
            minHeap.pop();

            // skip outdated heap entries
            if (cost > dist[node])
                continue;

            // relax all outgoing edges
            iterate(it, adj[node]) {
                int edgeCost = it.ss;
                int edgeNode = it.ff;

                // update shortest path if improved
                if (cost + edgeCost < dist[edgeNode]) {
                    dist[edgeNode] = cost + edgeCost;
                    minHeap.push({dist[edgeNode], edgeNode});
                }
            }
        }
    }

  public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int>
&cost) {
        // build graph: character transformations
        umap<int, vector<pii>> adj;
        loop(i, 0, sz(original))
            adj[original[i] - 'a'].pb({changed[i] - 'a', cost[i]});

        // dist[u][v]: min cost to convert char u -> v
        vvi dist(26, vi(26, INT_MAX));
        // run Dijkstra from every character
        loop(i, 0, 26)
            dijkstra(i, adj, dist[i]);

        // compute total cost for source -> target conversion
        ll res = 0;
        loop(i, 0, sz(source)) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            // no cost if characters already match
            if (src == dest)
                continue;
            // impossible transformation
            if (dist[src][dest] == INT_MAX)
                return -1;

            // accumulate minimal cost
            res += dist[src][dest];
        }

        return res;
    }
};
*/

/* Approach 2 (Floyd–Warshall Algorithm): */
class Solution {
  private:
    // Floyd–Warshall: all-pairs shortest paths on 26 characters
    void FloydWarshall(vvi &adj, vector<char> &original, vector<char> &changed, vi &cost) {
        // init: direct transformation costs
        loop(i, 0, sz(original)) {
            int src = original[i] - 'a';
            int dest = changed[i] - 'a';
            updateMin(adj[src][dest], cost[i]);
        }

        // core: try all intermediate characters
        loop(k, 0, 26)
            loop(i, 0, 26)
                loop(j, 0, 26) {
                    // guard: avoid overflow on unreachable paths
                    if (adj[i][k] > INT_MAX - adj[k][j])
                        continue;

                    // relax path i -> k -> j
                    updateMin(adj[i][j], adj[i][k] + adj[k][j]);
                }
    }

  public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost) {
        // init: adjacency matrix with INF
        vvi adj(26, vi(26, INT_MAX));
        // preprocess all character-to-character costs
        FloydWarshall(adj, original, changed, cost);

        // compute total conversion cost
        ll res = 0;
        loop(i, 0, sz(source)) {
            int src = source[i] - 'a';
            int dest = target[i] - 'a';

            // no cost if already same character
            if (src == dest)
                continue;
            // impossible transformation
            if (adj[src][dest] == INT_MAX)
                return -1;

            // accumulate minimal cost
            res += adj[src][dest];
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vi cost = {2, 5, 5, 1, 2, 20};
    println(obj.minimumCost("abcd", "acbe", original, changed, cost));
    original = {'a', 'c'};
    changed = {'c', 'b'};
    cost = {1, 2};
    println(obj.minimumCost("aaaa", "bbbb", original, changed, cost));
    original = {'a'};
    changed = {'e'};
    cost = {10000};
    println(obj.minimumCost("abcd", "abce", original, changed, cost));
}

/*
Problem: Minimum Cost to Convert String I
*/