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
    void dfs(int row, int col, vvi &result, vvi &image, int &initialColor, int &newColor, vi &deltaRow, vi &deltaCol) {
        result[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        loop(i, 0, 4) {
            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                image[newRow][newCol] == initialColor &&
                result[newRow][newCol] != newColor)
                    dfs(newRow, newCol, result, image, initialColor, newColor, deltaRow, deltaCol);
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];

        vvi result = image;
        vi deltaRow = {-1, 0, 1, 0};
        vi deltaCol = {0, 1, 0, -1};

        dfs(sr, sc, result, image, initialColor, color, deltaRow, deltaCol);

        return result;
    }
};
*/

/* Approach 2 (Breadth First Search): */
class Solution {
  private:
    void bfs(int row, int col, vvi &result, vvi &image, int &initialColor, int &newColor) {
        queue<pii> q;

        result[row][col] = newColor;
        q.push({row, col});

        int n = image.size();
        int m = image[0].size();
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
                    image[newRow][newCol] == initialColor &&
                    result[newRow][newCol] != newColor) {
                        result[newRow][newCol] = newColor;
                        q.push({newRow, newCol});
                }
            }
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vvi result = image;

        bfs(sr, sc, result, image, initialColor, color);

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vvi result = obj.floodFill(v, 1, 1, 2);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Flood Fill
*/