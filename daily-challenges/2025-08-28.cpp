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

/* Approach 1 (Sorting):
class Solution {
  private:
    int n, m;

    void computeDiagonal(int row, int col, vvi &grid, bool isSerial) {
        int rowIdx = row, colIdx = col;
        vi data;
        while (rowIdx < n && colIdx < m)
            data.pb(grid[rowIdx++][colIdx++]);

        if (isSerial)
            sort(all(data));
        else
            sort(all(data), greater<int>());

        rowIdx = row, colIdx = col;
        int idx = 0;
        while (rowIdx < n && colIdx < m)
            grid[rowIdx++][colIdx++] = data[idx++];
    }

  public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);

        revloop(i, m - 1, 1) computeDiagonal(0, i, grid, true);
        loop(i, 0, n) computeDiagonal(i, 0, grid, false);

        return grid;
    }
};
*/

/* Approach 2 (Hashing): */
class Solution {
  public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        umap<int, vi> mp;
        loop(row, 0, n)
            loop(col, 0, m) {
                int diag = row - col;
                mp[diag].pb(grid[row][col]);
            }

        iterate(it, mp)
            if (it.first >= 0)
                sort(all(it.second));
            else
                sort(all(it.second), greater<int>());

        loop(row, 0, n)
            loop(col, 0, m) {
                int diag = row - col;
                grid[row][col] = mp[diag].back();
                mp[diag].pop_back();
            }

        return grid;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vvi result = obj.sortMatrix(v);
    dump2D(result);
}

/*
Problem: Sort Matrix by Diagonals
*/