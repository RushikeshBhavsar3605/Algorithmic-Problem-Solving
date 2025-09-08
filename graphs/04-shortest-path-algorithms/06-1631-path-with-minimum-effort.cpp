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

/* Approach 1 (Naive DFS) (TLE):
class Solution {
  private:
    int n, m;
    vi deltaRow = {-1, 0, 1, 0};
    vi deltaCol = {0, 1, 0, -1};

    // DFS explores all paths, tracking the max effort seen so far
    void dfs(int row, int col, vvi &heights, int &result, vvi &vis, int diff, int curr) {
        // Reached bottom-right → update answer
        if (row == n - 1 && col == m - 1) {
            updateMin(result, diff);
            return;
        }

        // Explore 4 directions
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            // Skip out-of-bounds
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                continue;

            // Visit unvisited neighbor
            if (!vis[newRow][newCol]) {
                vis[newRow][newCol] = 1;
                // Update max diff along this path
                int currDiff = max(diff, abs(curr - heights[newRow][newCol]));
                dfs(newRow, newCol, heights, result, vis, currDiff, heights[newRow][newCol]);
                vis[newRow][newCol] = 0; // backtrack
            }
        }
    }

  public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        n = sz(heights);
        m = sz(heights[0]);

        vvi vis(n, vi(m, 0));
        int result = INT_MAX;
        // Start DFS from (0,0) with initial effort 0
        dfs(0, 0, heights, result, vis, 0, heights[0][0]);

        return result;
    }
};
*/

/* Approach 2 (BFS + Binary Search on Answers):
class Solution {
  private:
    int n, m;
    vi deltaRow = {-1, 0, 1, 0};
    vi deltaCol = {0, 1, 0, -1};

    // Check if bottom-right can be reached with max allowed diff <= threshold
    bool bfs(vvi &heights, int threshold) {
        int n = sz(heights);
        int m = sz(heights[0]);

        queue<pii> q;
        q.push({0, 0});

        vvi vis(n, vi(m, 0));
        vis[0][0] = 1; // mark start as visited

        while (!q.empty()) {
            int row = q.front().ff;
            int col = q.front().ss;
            q.pop();

            // Reached destination
            if (row == n - 1 && col == m - 1)
                return true;

            // Explore 4 directions
            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                // Skip out-of-bounds
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                    continue;

                int prev = heights[row][col];
                int curr = heights[newRow][newCol];

                // Visit neighbor if diff <= threshold
                if (!vis[newRow][newCol] && abs(prev - curr) <= threshold) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return false; // not reachable with this threshold
    }

  public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        n = sz(heights);
        m = sz(heights[0]);

        vvi vis(n, vi(m, 0));

        // Compute min and max heights to define search range
        int miniEle = INT_MAX;
        int maxiEle = 0;
        iterate(it, heights) iterate(i, it) {
            updateMin(miniEle, i);
            updateMax(maxiEle, i);
        }

        // Binary search on effort threshold
        int low = 0, high = maxiEle - miniEle;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (bfs(heights, mid))  // feasible
                high = mid - 1;
            else                    // not feasible
                low = mid + 1;
        }

        return low; // minimum effort
    }
};
*/

/* Approach 3 (Dijkstra Algorithm): */
class Solution {
  public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = sz(heights);
        int m = sz(heights[0]);

        // Direction vectors for 4-directional movement (up, right, down, left)
        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        // Distance array to track minimum effort to reach each cell
        vvi dist(n, vi(m, INT_MAX));
        dist[0][0] = 0;

        // Min-heap priority queue: {effort, row, col}
        priority_queue<vi, vvi, greater<vi>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int diff = curr[0], row = curr[1], col = curr[2];

            // Explore all 4 adjacent cells
            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                // Check bounds
                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
                    continue;

                // Calculate effort as max of current path effort and height difference
                int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), diff);

                // Update if we found a better path to this cell
                if (newEffort < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newEffort;
                    pq.push({newEffort, newRow, newCol});
                }
            }
        }

        // Return minimum effort to reach bottom-right corner
        return dist[n - 1][m - 1];
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << obj.minimumEffortPath(v) << endl;
    v = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << obj.minimumEffortPath(v) << endl;
}

/*
Problem: Path With Minimum Effort
*/