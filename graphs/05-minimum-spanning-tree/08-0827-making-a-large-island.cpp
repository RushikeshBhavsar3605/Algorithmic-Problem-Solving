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

/* Approach 1 (Disjoint Set Union): */
class Solution {
  public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = sz(grid);
        DisjointSet ds(n * n);       // DSU over n*n cells; node id = row*n + col
        vi deltaRow = {-1, 0, 1, 0}; // 4-directional movement
        vi deltaCol = {0, 1, 0, -1};

        // 1) Build DSU by uniting adjacent land cells (1s) to form island components
        loop(row, 0, n) {
            loop(col, 0, n) {
                if (!grid[row][col]) // skip water
                    continue;

                int nodeNo = row * n + col;
                loop(i, 0, 4) {
                    int newRow = row + deltaRow[i];
                    int newCol = col + deltaCol[i];
                    int newNodeNo = newRow * n + newCol;

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                        continue; // out of bounds

                    if (grid[newRow][newCol]) // union adjacent land
                        ds.unionBySize(nodeNo, newNodeNo);
                }
            }
        }

        int maxi = 0;
        // 2) For each water cell, flip it to land and compute potential island size:
        //    sum of sizes of unique neighboring components + 1 (for the flipped cell)
        loop(row, 0, n) {
            loop(col, 0, n) {
                if (grid[row][col])
                    continue; // only consider flipping water

                set<int> components; // unique neighbor component leaders
                loop(i, 0, 4) {
                    int newRow = row + deltaRow[i];
                    int newCol = col + deltaCol[i];
                    int newNodeNo = newRow * n + newCol;

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                        continue; // out of bounds

                    if (grid[newRow][newCol])
                        components.insert(ds.findParent(newNodeNo)); // collect unique components
                }

                int currMax = 0;
                iterate(it, components)
                    currMax += ds.size[it]; // sum component sizes

                updateMax(maxi, currMax + 1); // +1 for the flipped cell
            }
        }

        // 3) Edge case: if grid already all land, take the largest existing component
        loop(cellNo, 0, n * n)
            updateMax(maxi, ds.size[ds.findParent(cellNo)]);

        return maxi;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 0}, {0, 1}};
    cout << obj.largestIsland(v) << endl;
    v = {{1, 1}, {1, 0}};
    cout << obj.largestIsland(v) << endl;
    v = {{1, 1}, {1, 1}};
    cout << obj.largestIsland(v) << endl;
}

/*
Problem: Making A Large Island
*/