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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vvi dist(n, vi(m, 0));

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<vi> q;
        loop(row, 0, n) {
            loop(col, 0, m) {
                if (mat[row][col] == 0) {
                    vis[row][col] = true;
                    q.push({row, col, 0});
                }
            }
        }

        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front()[0];
            int col = q.front()[1];
            int steps = q.front()[2];
            q.pop();

            dist[row][col] = steps;

            loop(i, 0, 4) {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    q.push({newRow, newCol, steps + 1});
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vvi result = obj.updateMatrix(v);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    v = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    result = obj.updateMatrix(v);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: 01 Matrix
*/