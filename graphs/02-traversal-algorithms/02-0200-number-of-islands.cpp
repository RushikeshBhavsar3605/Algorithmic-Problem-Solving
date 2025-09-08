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

/* Approach 1 (Breadth First Search):
class Solution {
  private:
    void bfs(int row, int col, const vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = true;
        queue<pii> q;
        q.push({row, col});

        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        while (!q.empty()) {
            row = q.front().first;
            col = q.front().second;
            q.pop();

            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == '1' &&
                    !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                }
            }
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        loop(row, 0, n)
            loop(col, 0, m) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    count++;
                    bfs(row, col, grid, vis);
                }
            }

        return count;
    }
};
*/

/* Approach 2 (Depth First Search): */
class Solution {
  private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis) {
        vis[row][col] = true;

        int n = grid.size();
        int m = grid[0].size();
        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == '1' &&
                !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    dfs(newRow, newCol, grid, vis);
            }
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        loop(row, 0, n)
            loop(col, 0, m) {
                if (grid[row][col] == '1' && !vis[row][col]) {
                    count++;
                    dfs(row, col, grid, vis);
                }
            }

        return count;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> v = {
        {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << obj.numIslands(v);
    return 0;
}

/*
Problem: Number of Islands
*/