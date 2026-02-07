#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

/* Approach 1 (Dijkstra's Algorithm): */
class Solution {
  private:
    // dijkstra: compute shortest distance from src to all nodes
    vec<int> dijkstra(int src, int n, umap<int, vec<int>> &adj) {
        // init: min-heap storing {distance, node}
        priority_queue<pii, vec<pii>, greater<pii>> minHeap;
        minHeap.push({0, src});

        // init: distance array
        vec<int> dist(n, INT_MAX);
        dist[src] = 0;

        // loop: standard Dijkstra
        while (!minHeap.empty()) {
            int cost = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            // relax: all adjacent edges (unit weight)
            iterate(it, adj[node]) {
                int edgeNode = it;
                int edgeCost = 1;

                // update: shorter path found
                if (cost + edgeCost < dist[edgeNode]) {
                    dist[edgeNode] = cost + edgeCost;
                    minHeap.push({dist[edgeNode], edgeNode});
                }
            }
        }

        // return: shortest distances
        return dist;
    }

  public:
    int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z) {
        // init: adjacency list
        umap<int, vec<int>> adj;
        iterate(e, edges) {
            adj[e[0]].pb(e[1]);
            adj[e[1]].pb(e[0]);
        }

        // compute: distances from x, y, z
        vec<int> xDist = dijkstra(x, n, adj);
        vec<int> yDist = dijkstra(y, n, adj);
        vec<int> zDist = dijkstra(z, n, adj);

        // init: result counter
        int res = 0;

        // loop: check each node
        loop(node, 0, n) {
            // collect and sort distances
            vec<int> triplet({xDist[node], yDist[node], zDist[node]});
            sort(all(triplet));

            // assign: a <= b <= c
            ll a = triplet[0];
            ll b = triplet[1];
            ll c = triplet[2];

            // condition: Pythagorean check
            if (a * a == c * c - b * b)
                res++;
        }

        // return: count of special nodes
        return res;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> e = {{0, 1}, {0, 2}, {0, 3}};
    cout << obj.specialNodes(4, e, 1, 2, 3) << endl;
    e = {{0, 1}, {1, 2}, {2, 3}};
    cout << obj.specialNodes(4, e, 0, 3, 2) << endl;
    e = {{0, 1}, {1, 2}, {1, 3}};
    cout << obj.specialNodes(4, e, 1, 3, 0) << endl;
    return 0;
}

/*
Problem: Pythagorean Distance Nodes in a Tree
*/