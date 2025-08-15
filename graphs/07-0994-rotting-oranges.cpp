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

/* Approach 1 (Breadth First Search): */
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pii> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        loop(row, 0, n)
            loop(col, 0, m)
                if (grid[row][col] == 2) {
                    q.push({row, col});
                    vis[row][col] = true;
                }

        int count = 0;
        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int row = q.front().first;
                int col = col = q.front().second;
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

            if (!q.empty())
                count++;
        }

        loop(row, 0, n)
            loop(col, 0, m)
                if (!vis[row][col] && grid[row][col] == 1)
                    return -1;

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << obj.orangesRotting(v);
    return 0;
}

/*
Problem: Rotting Oranges
*/