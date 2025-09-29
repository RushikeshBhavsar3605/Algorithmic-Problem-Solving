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

/* Approach 3 (Kruskal's Algorithm): */
class DisjointSet {
  public:
    vi size, parent;

    // Initialize DSU with n nodes (1-indexed)
    DisjointSet(int n) {
        size.resize(n + 1, 1); // Each component initially has size 1
        parent.resize(n + 1);
        loop(i, 0, n + 1)
            parent[i] = i; // Each node is its own parent initially
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
    // Count number of provinces (connected components) in adjacency matrix
    // Time: O(n² * α(n)), Space: O(n)
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = sz(isConnected);
        DisjointSet st(n);

        // Process adjacency matrix and union connected cities
        loop(row, 0, n)
            loop(col, 0, n)
                if (isConnected[row][col] == 1)
                    st.unionBySize(row + 1, col + 1); // Convert to 1-indexed

        // Count number of distinct components (root nodes)
        int provinces = 0;
        loop(i, 1, n + 1)
            if (st.parent[i] == i) // Node is root of its component
                provinces++;

        return provinces;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << obj.findCircleNum(v) << endl;
    v = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << obj.findCircleNum(v) << endl;
}

/*
Problem: Number of Provinces
*/