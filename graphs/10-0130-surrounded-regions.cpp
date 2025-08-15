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

    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &board, int n, int m) {
        vis[row][col] = true;
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                board[newRow][newCol] == 'O' &&
                !vis[newRow][newCol])
                    dfs(newRow, newCol, vis, board, n, m);
        }
    }

  public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        loop(row, 0, n) {
            if (!vis[row][0] && board[row][0] == 'O')
                dfs(row, 0, vis, board, n, m);

            if (!vis[row][m - 1] && board[row][m - 1] == 'O')
                dfs(row, m - 1, vis, board, n, m);
        }

        loop(col, 0, m) {
            if (!vis[0][col] && board[0][col] == 'O')
                dfs(0, col, vis, board, n, m);

            if (!vis[n - 1][col] && board[n - 1][col] == 'O')
                dfs(n - 1, col, vis, board, n, m);
        }

        loop(row, 0, n)
            loop(col, 0, m) {
                if (board[row][col] == 'O' && !vis[row][col])
                    board[row][col] = 'X';
            }
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();

        const vi deltaRow = {-1, 0, 1, 0};
        const vi deltaCol = {0, 1, 0, -1};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pii> q;

        loop(row, 0, n) {
            if (!vis[row][0] && board[row][0] == 'O') {
                vis[row][0] = true;
                q.push({row, 0});
            }

            if (!vis[row][m - 1] && board[row][m - 1] == 'O') {
                vis[row][m - 1] = true;
                q.push({row, m - 1});
            }
        }

        loop(col, 0, m) {
            if (!vis[0][col] && board[0][col] == 'O') {
                vis[0][col] = true;
                q.push({0, col});
            }

            if (!vis[n - 1][col] && board[n - 1][col] == 'O') {
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
                    board[newRow][newCol] == 'O' &&
                    !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                }
            }
        }

        loop(row, 0, n)
            loop(col, 0, m) {
                if (board[row][col] == 'O' && !vis[row][col])
                    board[row][col] = 'X';
            }
    }
};

int main() {
    Solution obj;
    vector<vector<char>> v = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    iterate(it, v) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    cout << endl;
    obj.solve(v);
    iterate(it, v) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Surrounded Regions
*/