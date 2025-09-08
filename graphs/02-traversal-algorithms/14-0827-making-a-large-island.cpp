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

/* Approach 1 (Depth First Search): */
class Solution {
  private:
    int n;
    // Direction vectors for 4-directional movement (up, right, down, left)
    vi deltaRow = {-1, 0, 1, 0};
    vi deltaCol = {0, 1, 0, -1};

    // DFS to calculate size of connected island
    int islandSize(int row, int col, vvi &grid, vvi &vis) {
        vis[row][col] = 1;
        int count = 1;

        // Explore all 4 directions
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            // Check bounds
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                continue;

            // Recursively count connected land cells
            if (grid[newRow][newCol] == 1 && !vis[newRow][newCol])
                count += islandSize(newRow, newCol, grid, vis);
        }

        return count;
    }

    // Assign group ID and size to all cells in the same island
    void compute(int row, int col, vvi &grid, int size, vvi &group, int groupCount) {
        group[row][col] = groupCount;
        grid[row][col] = size; // Store island size in grid cell

        // Propagate to all connected cells
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            // Check bounds
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                continue;

            if (grid[newRow][newCol] == 1)
                compute(newRow, newCol, grid, size, group, groupCount);
        }
    }

  public:
    int largestIsland(vector<vector<int>> &grid) {
        n = sz(grid);
        vvi vis(n, vi(n, 0));
        vvi group(n, vi(n, -1)); // Track which group each cell belongs to

        int groupCount = 0;
        int largestIsland = 0;

        // Phase 1: Find all existing islands and their sizes
        loop(row, 0, n)
            loop(col, 0, n)
                if (grid[row][col] == 1 && !vis[row][col]) {
                    int size = islandSize(row, col, grid, vis);
                    updateMax(largestIsland, size);

                    // Assign group ID and size to this island
                    compute(row, col, grid, size, group, groupCount);
                    groupCount++;
                }

        // Phase 2: Try flipping each 0 to 1 and calculate potential island size
        loop(row, 0, n)
            loop(col, 0, n) {
                if (grid[row][col] != 0) // Skip existing land
                    continue;

                umap<int, int> mp;           // Track unique adjacent groups
                updateMax(largestIsland, 1); // Single cell island

                // Check all 4 adjacent cells
                loop(i, 0, 4) {
                    int newRow = row + deltaRow[i], newCol = col + deltaCol[i];

                    // Check bounds
                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                        continue;

                    // Consider connecting to adjacent island
                    updateMax(largestIsland, grid[newRow][newCol] + 1);

                    // Store unique adjacent groups
                    mp[group[newRow][newCol]] = grid[newRow][newCol];
                }

                // Calculate total size by connecting all adjacent unique groups
                int sum = 0;
                iterate(it, mp) {
                    sum += it.ss;
                    updateMax(largestIsland, sum + 1); // +1 for the flipped cell
                }
            }

        return largestIsland;
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
    v = {{0}};
    cout << obj.largestIsland(v) << endl;
    v = {{0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {1, 0, 1, 0, 1, 0, 0},
         {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 1, 1, 1, 1, 0, 0}};
    cout << obj.largestIsland(v) << endl;
}

/*
Problem: Making A Large Island
*/