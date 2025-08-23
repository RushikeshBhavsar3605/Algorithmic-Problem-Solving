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

/* Approach 1 (Brute Force): */
class Solution {
  private:
    vvi rotateClockWise(vvi &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        vvi rotatedGrid(m, vi(n));
        loop(row, 0, n)
            loop(col, 0, m)
                rotatedGrid[col][n - row - 1] = grid[row][col];

        return rotatedGrid;
    }

    int minimumArea(int startRow, int endRow, int startCol, int endCol, vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        int left = m, right = 0;
        int top = n, bottom = 0;

        loop(row, startRow, endRow)
            loop(col, startCol, endCol)
                if (grid[row][col]) {
                    updateMin(left, col);
                    updateMax(right, col);

                    updateMin(top, row);
                    updateMax(bottom, row);
                }

        return (right - left + 1) * (bottom - top + 1);
    }

    int utility(vvi &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        int result = INT_MAX;

        loop(rowSplit, 1, n)
            loop(colSplit, 1, m) {
                int top = minimumArea(0, rowSplit, 0, m, grid);
                int bottomLeft = minimumArea(rowSplit, n, 0, colSplit, grid);
                int bottomRight = minimumArea(rowSplit, n, colSplit, m, grid);

                updateMin(result, top + bottomLeft + bottomRight);

                int topLeft = minimumArea(0, rowSplit, 0, colSplit, grid);
                int topRight = minimumArea(0, rowSplit, colSplit, m, grid);
                int bottom = minimumArea(rowSplit, n, 0, m, grid);

                updateMin(result, topLeft + topRight + bottom);
            }

        loop(split1, 1, n)
            loop(split2, split1 + 1, n) {
                int top = minimumArea(0, split1, 0, m, grid);
                int middle = minimumArea(split1, split2, 0, m, grid);
                int bottom = minimumArea(split2, n, 0, m, grid);

                updateMin(result, top + middle + bottom);
            }

        return result;
    }

  public:
    int minimumSum(vector<vector<int>> &grid) {
        int result = utility(grid);

        vvi rotatedGrid = rotateClockWise(grid);
        updateMin(result, utility(rotatedGrid));

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 0, 1}, {1, 1, 1}};
    cout << obj.minimumSum(v) << endl;
    return 0;
}

/*
Problem: Find the Minimum Area to Cover All Ones II
*/