#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int n = sz(grid), m = sz(grid[0]);
        k %= n * m;
        if (k == 0)
            return grid;

        vi temp;
        iterate(it, grid)
            iterate(i, it)
                temp.pb(i);

        reverse(begin(temp), end(temp));
        reverse(begin(temp), begin(temp) + k);
        reverse(begin(temp) + k, end(temp));

        vvi res(n, vi(m));
        int idx = 0;
        loop(i, 0, n)
            loop(j, 0, m)
                res[i][j] = temp[idx++];

        return res;
    }
};
*/

/* Approach 2 (Space Optimization):
class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int n = sz(grid), m = sz(grid[0]);
        int N = n * m;
        k %= N;

        vvi res(n, vi(m));
        int idx = (N - k) % N;

        loop(i, 0, N) {
            int srcRow = idx / m;
            int srcCol = idx % m;

            int desRow = i / m;
            int desCol = i % m;

            res[desRow][desCol] = grid[srcRow][srcCol];

            idx = (idx + 1) % N;
        }

        return res;
    }
};
*/

/* Approach 3 (Inplace Reverse): */
class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        int n = sz(grid), m = sz(grid[0]);
        int N = n * m;
        k %= N;

        auto shift = [&](int i, int j) {
            while (i < j) {
                int r1 = i / m, c1 = i % m;
                int r2 = j / m, c2 = j % m;

                swap(grid[r1][c1], grid[r2][c2]);

                i++, j--;
            }
        };

        shift(0, N - 1);
        shift(0, k - 1);
        shift(k, N - 1);

        return grid;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = obj.shiftGrid(v, 1);
    print(res);
    v = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
    res = obj.shiftGrid(v, 4);
    print(res);
    v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    res = obj.shiftGrid(v, 9);
    print(res);
    return 0;
}

/*
Problem: Shift 2D Grid
*/