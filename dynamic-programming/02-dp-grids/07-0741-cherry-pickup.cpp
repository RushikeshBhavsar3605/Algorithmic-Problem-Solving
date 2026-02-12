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

/* Approach 1 (Recursion):
class Solution {
  private:
    int solve(int row1, int col1, int row2, int col2, vvi &grid, int n) {
        // Out of bounds or thorns
        if (row1 >= n || col1 >= n || row2 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return INT_MIN;

        // Both reached destination (they reach together always)
        else if (row1 == n - 1 && col1 == n - 1)
            return grid[row1][col1];

        // Count cherries at current positions
        int cherries = grid[row1][col1];
        if (row1 != row2 || col1 != col2) // Different cells
            cherries += grid[row2][col2];

        // Explore all 4 movement combinations
        int nextMax = max({
            solve(row1, col1 + 1, row2, col2 + 1, grid, n), // both right
            solve(row1 + 1, col1, row2 + 1, col2, grid, n), // both down
            solve(row1, col1 + 1, row2 + 1, col2, grid, n), // p1 right, p2 down
            solve(row1 + 1, col1, row2, col2 + 1, grid, n)  // p1 down, p2 right
        });

        // If all paths fail, propagate failure
        if (nextMax == INT_MIN)
            return INT_MIN;

        return cherries + nextMax;
    }

  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int result = solve(0, 0, 0, 0, grid, sz(grid));
        return max(0, result); // Return 0 if no valid path exists
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int row1, int col1, int row2, int col2, vvi &grid, int n, vector<vector<vector<vector<int>>>> &memo) {
        // Invalid path: out of bounds or thorn cell
        if (row1 >= n || col1 >= n || row2 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return INT_MIN;

        // Base case: both reach destination together
        else if (row1 == n - 1 && col1 == n - 1)
            return grid[row1][col1];

        // Return memoized result if already computed
        if (memo[row1][col1][row2][col2] != -1)
            return memo[row1][col1][row2][col2];

        // Collect cherries: count once if both on same cell
        int cherries = grid[row1][col1];
        if (row1 != row2 || col1 != col2)
            cherries += grid[row2][col2];

        // Explore all 4 movement combinations: RR, DD, RD, DR
        int nextMax = max({
            solve(row1, col1 + 1, row2, col2 + 1, grid, n, memo),
            solve(row1 + 1, col1, row2 + 1, col2, grid, n, memo),
            solve(row1, col1 + 1, row2 + 1, col2, grid, n, memo),
            solve(row1 + 1, col1, row2, col2 + 1, grid, n, memo)
        });

        // Propagate invalid path upward
        if (nextMax == INT_MIN)
            return memo[row1][col1][row2][col2] = INT_MIN;

        // Memoize and return result
        return memo[row1][col1][row2][col2] = cherries + nextMax;
    }

  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = sz(grid);
        // Initialize 4D memo: -1 means uncomputed
        vector<vector<vector<vector<int>>>> memo(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n,
-1)))); int result = solve(0, 0, 0, 0, grid, n, memo);
        // Return 0 if no valid path exists
        return max(0, result);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = sz(grid);
        // 4D DP array to store max cherries collected with 2 persons at positions (row1,col1) and (row2,col2)
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));

        // Bottom-right corner base case: both persons reach destination
        revloop(row1, n - 1, 0)
        revloop(col1, n - 1, 0)
        revloop(row2, n - 1, 0)
        revloop(col2, n - 1, 0) {
            // If both at destination, cherries equal grid value there
            if (row1 == n - 1 && col1 == n - 1 && row2 == n - 1 && col2 == n - 1) {
                dp[row1][col1][row2][col2] = grid[row1][col1];
                continue;
            }

            // If either cell is blocked (-1), mark this state as invalid
            if (grid[row1][col1] == -1 || grid[row2][col2] == -1) {
                dp[row1][col1][row2][col2] = INT_MIN;
                continue;
            }

            // Collect cherries for both positions; avoid double counting if same cell
            int cherries = grid[row1][col1];
            if (row1 != row2 || col1 != col2)
                cherries += grid[row2][col2];

            // Initialize next moves to invalid paths
            int move1 = INT_MIN, move2 = INT_MIN, move3 = INT_MIN, move4 = INT_MIN;

            // Compute max cherries from all 4 possible next moves (RR, DD, RD, DR)
            if (col1 + 1 < n && col2 + 1 < n)
                move1 = dp[row1][col1 + 1][row2][col2 + 1];
            if (row1 + 1 < n && row2 + 1 < n)
                move2 = dp[row1 + 1][col1][row2 + 1][col2];
            if (col1 + 1 < n && row2 + 1 < n)
                move3 = dp[row1][col1 + 1][row2 + 1][col2];
            if (row1 + 1 < n && col2 + 1 < n)
                move4 = dp[row1 + 1][col1][row2][col2 + 1];

            // Get max cherries possible from next states
            int nextMax = max({move1, move2, move3, move4});

            // If all next moves invalid, mark this state invalid
            if (nextMax == INT_MIN) {
                dp[row1][col1][row2][col2] = INT_MIN;
                continue;
            }

            // Update DP with cherries collected at current cells plus best next
            dp[row1][col1][row2][col2] = cherries + nextMax;
        }

        // Return max cherries that can be collected starting from (0,0) for both persons
        // Ensure non-negative result if no valid path found
        return max(0, dp[0][0][0][0]);
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    println(obj.cherryPickup(v));
    v = {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    println(obj.cherryPickup(v));
}

/*
Problem: Cherry Pickup
*/