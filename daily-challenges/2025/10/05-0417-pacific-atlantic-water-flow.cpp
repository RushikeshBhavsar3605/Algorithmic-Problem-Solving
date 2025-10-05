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

/* Approach 1 (Multi Source BFS): */
class Solution {
  private:
    vvi multisourceBFS(vvi &heights, bool isPacific) {
        int n = sz(heights);
        int m = sz(heights[0]);

        vvi vis(n, vi(m, 0));
        priority_queue<vi, vvi, greater<vi>> minHeap; // Process cells in nondecreasing height for stable uphill expansion

        // Seed with ocean-border cells: Pacific = top/left, Atlantic = bottom/right; mark visited
        loop(row, 0, n)
            loop(col, 0, m)
                if ((isPacific && (row == 0 || col == 0)) ||
                    (!isPacific && (row == n - 1 || col == m - 1))) {
                        minHeap.push({heights[row][col], row, col});
                        vis[row][col] = 1;
                }

        // Reverse flow: expand from ocean into land, only to neighbors with height >= current (can flow back downhill
        // to ocean)
        while (!minHeap.empty()) {
            int height = minHeap.top()[0];
            int row = minHeap.top()[1];
            int col = minHeap.top()[2];
            minHeap.pop();

            vvi neighbors = {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
            iterate(it, neighbors) {
                int newRow = it[0];
                int newCol = it[1];

                // Skip OOB/visited; require heights[new] >= heights[cur] to maintain uphill traversal
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m ||
                    vis[newRow][newCol] || heights[newRow][newCol] < heights[row][col])
                        continue;

                minHeap.push({heights[newRow][newCol], newRow, newCol}); // Enqueue next reachable plateau/uphill cell
                vis[newRow][newCol] = 1;                                 // Mark reachable from this ocean
            }
        }

        return vis; // Reachability map from chosen ocean
    }

  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        int n = sz(heights);
        int m = sz(heights[0]);

        vvi pacific = multisourceBFS(heights, true);   // Cells reachable from Pacific borders
        vvi atlantic = multisourceBFS(heights, false); // Cells reachable from Atlantic borders

        vvi result;
        loop(row, 0, n)
            loop(col, 0, m)
                if (pacific[row][col] && atlantic[row][col])
                    result.pb({row, col}); // Intersection = cells that can reach both oceans

        return result; // List of coordinates flowing to both oceans
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    dump2D(obj.pacificAtlantic(v));
    v = {{1}};
    dump2D(obj.pacificAtlantic(v));
}

/*
Problem: Pacific Atlantic Water Flow
*/