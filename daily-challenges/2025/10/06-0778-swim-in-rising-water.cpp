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

/* Approach 1 (Binary Search on Answers):
class Solution {
  private:
    int n;
    int m;
    vi deltaRow = {-1, 0, 1, 0}; // 4-direction moves
    vi deltaCol = {0, 1, 0, -1};

    // DFS under threshold T: can we reach (n-1,m-1) using cells <= T?
    bool dfs(int row, int col, int threshold, vvi &grid, vvi &vis) {
        if (row == n - 1 && col == m - 1) // reached target
            return true;

        vis[row][col] = 1; // mark current as visited

        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            // skip out-of-bounds or already visited
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || vis[newRow][newCol])
                continue;

            // only traverse if next elevation <= threshold
            if (grid[newRow][newCol] <= threshold)
                if (dfs(newRow, newCol, threshold, grid, vis))
                    return true; // path found
        }

        return false; // no path from this branch
    }

    // Monotonic predicate: is a path possible at time = mid?
    bool isPossible(vvi &grid, int mid) {
        if (grid[0][0] > mid) // start must be accessible
            return false;
        vvi vis(n, vi(m, 0)); // fresh visited per check
        return dfs(0, 0, mid, grid, vis);
    }

  public:
    int swimInWater(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);

        int low = grid[0][0]; // minimal feasible time cannot be < start cell
        int high = 0;         // maximal elevation in grid (always feasible)
        iterate(it, grid)
            iterate(i, it)
                updateMax(high, i);

        // Inclusive bounds: find first T where isPossible(T) == true
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (isPossible(grid, mid))
                high = mid - 1; // shrink left to find first feasible
            else
                low = mid + 1; // need larger time
        }

        return low; // first feasible time (lower bound)
    }
};
*/

/* Approach 1 (Modified Dijkstra's Algorithm): */
class Solution {
  public:
    int swimInWater(vector<vector<int>> &grid) {
        int n = sz(grid);    // rows
        int m = sz(grid[0]); // cols

        vvi vis(n, vi(m, 0)); // visited; typical Dijkstra marks on pop for strict correctness

        // min-heap of states: {time_so_far (max elevation on path), row, col}
        priority_queue<vi, vvi, greater<vi>> min_heap;
        min_heap.push({grid[0][0], 0, 0}); // start with time = grid[0][0]
        vis[0][0] = 1;                     // visited-on-push (works in many cases; safer is visited-on-pop)

        while (!min_heap.empty()) {
            int height = min_heap.top()[0]; // best (lowest time) state available
            int row = min_heap.top()[1];
            int col = min_heap.top()[2];
            min_heap.pop();

            if (row == n - 1 && col == m - 1)
                return height; // first time reaching target gives minimal possible time

            // 4-directional neighbors
            vvi neighbors = {{row - 1, col}, {row, col + 1}, {row + 1, col}, {row, col - 1}};
            iterate(it, neighbors) {
                int newRow = it[0];
                int newCol = it[1];

                // bounds check + skip already taken cells
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || vis[newRow][newCol])
                    continue;

                // Dijkstra transition: cost to enter neighbor is max(path_time_so_far, neighbor_elevation)
                min_heap.push({max(height, grid[newRow][newCol]), newRow, newCol});
                vis[newRow][newCol] = 1; // note: stricter Dijkstra sets visited when popped, not when pushed
            }
        }

        return -1; // unreachable
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 2}, {1, 3}};
    println(obj.swimInWater(v));
    v = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    println(obj.swimInWater(v));
}

/*
Problem: Swim in Rising Water
*/