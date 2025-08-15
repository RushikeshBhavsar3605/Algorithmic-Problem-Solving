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

    void dfs(int row, int col, vvi &vis, vvi &grid, vector<pii> &v, int baseRow, int baseCol, int n, int m) {
        vis[row][col] = 1;
        v.push_back({row - baseRow, col - baseCol});

        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 &&
                !vis[newRow][newCol])
                    dfs(newRow, newCol, vis, grid, v, baseRow, baseCol, n, m);
        }
    }

  public:
    int solve(vvi &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vvi vis(n, vi(m, 0));
        set<vector<pii>> st;

        loop(row, 0, n)
            loop(col, 0, m)
                if (grid[row][col] == 1 && !vis[row][col]) {
                    vector<pii> v;
                    dfs(row, col, vis, grid, v, row, col, n, m);
                    st.insert(v);
                }

        return st.size();
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  private:
    const vi deltaRow = {-1, 0, 1, 0};
    const vi deltaCol = {0, 1, 0, -1};

    vector<pii> bfs(int row, int col, vvi &grid, vvi &vis, int n, int m) {
        queue<pii> q;
        vis[row][col] = 1;
        q.push({row, col});
        vector<pii> result;

        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            result.push_back({currRow - row, currCol - col});
            q.pop();

            loop(i, 0, 4) {
                int newRow = currRow + deltaRow[i];
                int newCol = currCol + deltaCol[i];
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 &&
                    !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                }
            }
        }

        return result;
    }

  public:
    int solve(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        const vi deltaRow = {-1, 0, 1, 0};
        const vi deltaCol = {0, 1, 0, -1};
        set<vector<pii>> st;
        vvi vis(n, vi(m, 0));
        queue<pii> q;

        loop(row, 0, n)
            loop(col, 0, m)
                if (grid[row][col] == 1 && !vis[row][col])
                    st.insert(bfs(row, col, grid, vis, n, m));

        return st.size();
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
    cout << obj.solve(v);
    return 0;
}

/*
Problem: Number of Distinct Islands
*/