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
  public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        int n = sz(heightMap);
        int m = sz(heightMap[0]);

        // Min-heap of cells by height: {height, row, col}
        priority_queue<vi, vvi, greater<vi>> minHeap;

        // Seed heap with all boundary cells as initial "walls"; mark them visited.
        // Reuse heightMap as visited grid by setting visited cells to -1.
        loop(row, 0, n)
            loop(col, 0, m)
                if (row == 0 || row == n - 1 || col == 0 || col == m - 1) {
                    minHeap.push({heightMap[row][col], row, col});
                    heightMap[row][col] = -1; // visited
                }

        int result = 0;
        int maxHeight = -1; // highest boundary seen so far

        // Process cells from lowest boundary upwards (like Dijkstra's).
        while (!minHeap.empty()) {
            int height = minHeap.top()[0];
            int row = minHeap.top()[1];
            int col = minHeap.top()[2];
            minHeap.pop();

            // Current water level is bounded by the highest wall seen.
            updateMax(maxHeight, height);
            // Water trapped on this cell = water level - cell height (>= 0 by heap order).
            result += maxHeight - height;

            // Visit 4-directional neighbors.
            vvi neighbors = {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
            iterate(it, neighbors) {
                int newRow = it[0];
                int newCol = it[1];

                // Skip out-of-bounds or already visited.
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || heightMap[newRow][newCol] == -1)
                    continue;

                // Push neighbor with its own height; it will be compared against current water level
                // when popped later to compute trapped water correctly.
                minHeap.push({heightMap[newRow][newCol], newRow, newCol});
                heightMap[newRow][newCol] = -1; // mark visited when enqueued
            }
        }

        return result;
    }
};
/*
Note:
Standard problem of reverse engineering, instead of calculating how water is storable, instead start from border and
check how much water is not storable and at the end we get accurate value of inner blocks storage capacity The solution
is easy to implement, but hard to build and prove the clarified intuition As we start from minimum from border we always
calculate the appropriate maxHeight for all visiting cells
*/

int main() {
    Solution obj;
    vvi v = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    println(obj.trapRainWater(v));
    v = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};
    println(obj.trapRainWater(v));
    v = {{12, 13, 1, 12}, {13, 4, 13, 12}, {13, 8, 10, 12}, {12, 13, 12, 12}, {13, 13, 13, 13}};
    println(obj.trapRainWater(v));
}

/*
Problem: Trapping Rain Water II
*/