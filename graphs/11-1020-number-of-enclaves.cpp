#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

/* Approach 1 (Depth First Search):
class Solution {
  private:
    const vi deltaRow = {-1, 0, 1, 0};
    const vi deltaCol = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<bool>> &vis, vvi &grid, int n, int m) {
        vis[row][col] = true;
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 &&
                !vis[newRow][newCol])
                    dfs(newRow, newCol, vis, grid, n, m);
        }
    }

  public:
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        loop(row, 0, n) {
            if (!vis[row][0] && grid[row][0] == 1)
                dfs(row, 0, vis, grid, n, m);

            if (!vis[row][m - 1] && grid[row][m - 1] == 1)
                dfs(row, m - 1, vis, grid, n, m);
        }

        loop(col, 0, m) {
            if (!vis[0][col] && grid[0][col] == 1)
                dfs(0, col, vis, grid, n, m);

            if (!vis[n - 1][col] && grid[n - 1][col] == 1)
                dfs(n - 1, col, vis, grid, n, m);
        }

        int count = 0;
        loop(row, 0, n)
            loop(col, 0, m) {
                if (grid[row][col] == 1 && !vis[row][col])
                    count++;
            }

        return count;
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  public:
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        const vi deltaRow = {-1, 0, 1, 0};
        const vi deltaCol = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pii> q;

        loop(row, 0, n) {
            if (!vis[row][0] && grid[row][0] == 1) {
                vis[row][0] = true;
                q.push({row, 0});
            }

            if (!vis[row][m - 1] && grid[row][m - 1] == 1) {
                vis[row][m - 1] = true;
                q.push({row, m - 1});
            }
        }

        loop(col, 0, m) {
            if (!vis[0][col] && grid[0][col] == 1) {
                vis[0][col] = true;
                q.push({0, col});
            }

            if (!vis[n - 1][col] && grid[n - 1][col] == 1) {
                vis[n - 1][col] = true;
                q.push({n - 1, col});
            }
        }

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 &&
                    !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                }
            }
        }

        int count = 0;
        loop(row, 0, n)
            loop(col, 0, m) {
                if (grid[row][col] == 1 && !vis[row][col])
                    count++;
            }

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << obj.numEnclaves(v);
    return 0;
}

/*
Problem: Number of Enclaves
*/