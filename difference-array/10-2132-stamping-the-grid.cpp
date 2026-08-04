#include "template.hpp"

/* Approach (2D Prefix Sum + 2D Difference Array): */
class Solution {
  public:
    bool possibleToStamp(vector<vector<int>> &grid, int H, int W) {
        int n = sz(grid);
        int m = sz(grid[0]);

        // pre[i][j] = number of occupied cells (1s) in rectangle [0..i-1][0..j-1]
        vvi pre(n + 1, vi(m + 1, 0));

        loop(i, 0, n) {
            loop(j, 0, m) {
                pre[i + 1][j + 1] =
                    grid[i][j]
                    + pre[i][j + 1]
                    + pre[i + 1][j]
                    - pre[i][j];
            }
        }

        // Difference array for stamp coverage.
        // After prefixing, diff[i][j] = number of valid stamps covering (i,j).
        vvi diff(n + 1, vi(m + 1, 0));

        // Try every possible top-left corner of a H x W stamp.
        loop(i, 0, n - H + 1) {
            loop(j, 0, m - W + 1) {
                // Number of occupied cells inside this stamp.
                int ones =
                    pre[i + H][j + W]
                    - pre[i][j + W]
                    - pre[i + H][j]
                    + pre[i][j];

                // Stamp is valid only if it covers no occupied cell.
                if (ones == 0) {
                    // Rectangle update (2D difference array).
                    diff[i][j]++;
                    diff[i][j + W]--;
                    diff[i + H][j]--;
                    diff[i + H][j + W]++;
                }
            }
        }

        // Recover coverage counts from the difference array.
        loop(i, 0, n) {
            loop(j, 0, m) {
                if (i > 0)
                    diff[i][j] += diff[i - 1][j];
                if (j > 0)
                    diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0)
                    diff[i][j] -= diff[i - 1][j - 1];

                // Only empty cells need to be covered.
                if (grid[i][j] == 0 && diff[i][j] == 0)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
    auto res = obj.possibleToStamp(v, 4, 3);
    print(res);
    v = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    res = obj.possibleToStamp(v, 2, 2);
    print(res);
    return 0;
}

/*
Problem: Stamping the Grid
*/