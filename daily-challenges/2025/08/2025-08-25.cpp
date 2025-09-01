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

/* Approach 1 (Naive):
class Solution {
  private:
    void solve(vvi &mat, int &row, int &col, int n, int m, bool &direction, vi &result) {
        result.pb(mat[row][col]);

        if (direction && row > 0 && col < m - 1)
            row--, col++;
        else if (!direction && row < n - 1 && col > 0)
            row++, col--;
        else
            return;

        solve(mat, row, col, n, m, direction, result);
    }

  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int n = sz(mat), m = sz(mat[0]);

        vi result;
        bool direction = true;
        int row = 0, col = 0;

        while (row >= 0 && row < n && col >= 0 && col < m) {
            solve(mat, row, col, n, m, direction, result);

            if (direction)
                col < m - 1 ? col++ : row++;
            else
                row < n - 1 ? row++ : col++;

            direction = !direction;
        }

        return result;
    }
};
*/

/* Approach 2 (Interview Ready): */
class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int n = sz(mat), m = sz(mat[0]);

        vi result;
        bool direction = true;
        int row = 0, col = 0;

        while (row < n && col < m) {
            result.pb(mat[row][col]);

            int newRow = row + (direction ? -1 : 1);
            int newCol = col + (direction ? 1 : -1);

            if (newRow < 0 || newRow == n || newCol < 0 || newCol == m) {
                if (direction) {
                    row += (col == m - 1 ? 1 : 0);
                    col += (col < m - 1 ? 1 : 0);
                } else {
                    col += (row == n - 1 ? 1 : 0);
                    row += (row < n - 1 ? 1 : 0);
                }
                direction = !direction;
            } else {
                row = newRow;
                col = newCol;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vi result = obj.findDiagonalOrder(v);
    iterate(it, result) cout << it << " ";
}

/*
Problem: Diagonal Traverse
*/