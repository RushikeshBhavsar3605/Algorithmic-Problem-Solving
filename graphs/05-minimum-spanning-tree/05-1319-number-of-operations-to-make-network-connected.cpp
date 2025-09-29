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

/* Approach 1 (Disjoint Set Union): */
class DisjointSet {
  public:
    vi size, parent;

    // Initialize DSU with n nodes (1-indexed)
    DisjointSet(int n) {
        size.resize(n + 1, 1); // Each component initially has size 1
        parent.resize(n + 1);
        loop(i, 0, n + 1) parent[i] = i; // Each node is its own parent initially
    }

    // Find root with path compression - O(α(n)) amortized
    int findParent(int node) {
        if (node == parent[node])
            return node;

        // Path compression: make all nodes on path point directly to root
        return parent[node] = findParent(parent[node]);
    }

    // Union two components by size - O(α(n)) amortized
    void unionBySize(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return; // Already in same component

        // Always attach smaller tree under larger tree to minimize height
        else if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        } else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
  public:
    // Find minimum cables needed to connect all computers, or -1 if impossible
    // Time: O(E * α(n) + n), Space: O(n)
    int makeConnected(int n, vector<vector<int>> &connections) {
        DisjointSet st(n);
        int extraEdges = 0;

        // Process all connections and count redundant edges (cycles)
        iterate(connection, connections) {
            int u = connection[0];
            int v = connection[1];

            // If nodes already connected, this edge is redundant (can be reused)
            if (st.findParent(u) == st.findParent(v))
                extraEdges++;

            // Union regardless to build connected components
            st.unionBySize(u, v);
        }

        // Count number of disconnected components
        int components = 0;
        loop(i, 0, n)
            if (st.parent[i] == i) // Root node represents a component
                components++;

        // Need (components-1) edges to connect all components
        // Return minimum operations if we have enough spare cables, otherwise impossible
        return extraEdges >= components - 1 ? components - 1 : -1;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1}, {0, 2}, {1, 2}};
    cout << obj.makeConnected(4, v) << endl;
    v = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
    cout << obj.makeConnected(6, v) << endl;
    v = {{0, 1}, {0, 2}, {0, 3}, {1, 2}};
    cout << obj.makeConnected(6, v) << endl;
}

/*
Problem: Number of Operations to Make Network Connected
*/