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

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Naive): */
class Solution {
  private:
    int n, m;

    bool isValid(int row, int col, vvi &grid) {
        umap<int, int> vis;
        loop(newRow, row, row + 3) {
            loop(newCol, col, col + 3) {
                if (grid[newRow][newCol] <= 0 || grid[newRow][newCol] > 9)
                    return false;
                if (vis.count(grid[newRow][newCol]))
                    return false;
                vis[grid[newRow][newCol]] = 1;
            }
        }

        int row1 = 0, row2 = 0, row3 = 0;
        loop(i, col, col + 3) {
            row1 += grid[row][i];
            row2 += grid[row + 1][i];
            row3 += grid[row + 2][i];
        }
        if (row1 != row2 || row2 != row3)
            return false;

        int col1 = 0, col2 = 0, col3 = 0;
        loop(i, row, row + 3) {
            col1 += grid[i][col];
            col2 += grid[i][col + 1];
            col3 += grid[i][col + 2];
        }
        if (col1 != col2 || col2 != col3)
            return false;

        int diagonal1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int diagonal2 = grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];

        return diagonal1 == diagonal2;
    }

  public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);
        if (n < 3 || m < 3)
            return 0;

        int count = 0;

        loop(row, 0, n - 2)
            loop(col, 0, m - 2)
                if (isValid(row, col, grid))
                    count++;

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    println(obj.numMagicSquaresInside(v));
    v = {{8}};
    println(obj.numMagicSquaresInside(v));
}

/*
Problem: Magic Squares In Grid
*/