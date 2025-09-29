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
  private:
    vi size, parent;

  public:
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

/* Approach 1 (Disjoint Set Union): */
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vi deltaRow = {-1, 0, 1, 0}; // 4-direction row offsets
        vi deltaCol = {0, 1, 0, -1}; // 4-direction col offsets

        DisjointSet ds(n * m); // DSU over flattened n*m grid
        vvi vis(n, vi(m, 0));  // visited land cells (0: water, 1: land)
        int count = 0;         // current number of islands
        vi result;

        iterate(it, operators) {
            int row = it[0];
            int col = it[1];

            // If already land, island count unchanged
            if (vis[row][col]) {
                result.pb(count);
                continue;
            }
            vis[row][col] = 1; // turn water -> land
            count++;           // new land initially forms a new island

            int nodeNo = row * m + col; // 2D -> 1D index
            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                // Skip out-of-bounds neighbors
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                    continue;

                // If neighbor is land, try to union sets
                if (vis[newRow][newCol]) {
                    int newNodeNo = newRow * m + newCol;
                    // Merge distinct islands; decrement count on successful union
                    if (ds.findParent(nodeNo) != ds.findParent(newNodeNo)) {
                        count--;
                        ds.unionBySize(nodeNo, newNodeNo);
                    }
                }
            }

            // Record island count after this operation
            result.pb(count);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    dump(obj.numOfIslands(4, 5, v));
}

/*
Problem: Number Of Islands
Link: https://www.geeksforgeeks.org/problems/number-of-islands/1
*/