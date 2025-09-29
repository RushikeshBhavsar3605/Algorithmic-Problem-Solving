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

class DisjointSet {
  public:
    vi size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        loop(i, 0, n + 1) parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;
        else if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        } else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

/* Approach 1 (Disjoint Set Union):
Note: In this type of problem reverse engineering is key, instead of finding ways if we found components and sum them up by excluding 1 element in each component then we get our number of ways, and that can be achievable by total elements - components size
*/
class Solution {
  public:
    int removeStones(vector<vector<int>> &stones) {
        // Find coordinate bounds to create proper node mapping
        int maxRow = 0;
        int maxCol = 0;
        iterate(it, stones) {
            updateMax(maxRow, it[0]);
            updateMax(maxCol, it[1]);
        }

        // Create DSU with enough nodes for both row and column indices
        // Offset column indices by (maxRow + 1) to avoid collision with row indices
        DisjointSet ds(maxRow + maxCol + 1);

        iterate(it, stones) {
            int rowNode = it[0];              // Row index as node ID
            int colNode = it[1] + maxRow + 1; // Column index offset to unique range

            // Connect row and column nodes - stones sharing row/column get connected
            ds.unionBySize(rowNode, colNode);
        }

        // Count connected components that contain at least one stone
        // Each component represents stones that can be removed except one
        int count = 0;
        loop(i, 0, maxRow + maxCol + 1)
            if (ds.findParent(i) == i && ds.size[i] > 1) // Root with multiple nodes
                count++;

        // Answer: total stones - number of components (keep one stone per component)
        return sz(stones) - count;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << obj.removeStones(v) << endl;
    v = {{0, 0}, {0, 2}, {3, 2}, {3, 1}, {1, 3}, {4, 3}};
    cout << obj.removeStones(v) << endl;
}

/*
Problem: Most Stones Removed with Same Row or Column
*/