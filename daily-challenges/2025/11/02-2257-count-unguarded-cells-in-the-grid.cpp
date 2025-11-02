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

struct Cell {
    int val, up, right, down, left;
};

/* Approach 1 (Naive): */
class Solution {
  private:
    void markGuarded(int row, int col, vector<vector<Cell>> &mat, int m, int n) {
        mat[row][col].val = 1;

        // Up traversal
        revloop(newRow, row, 0) {
            if (mat[newRow][col].val == 2 || mat[newRow][col].up == 1)
                break;
            mat[newRow][col].val = 1;
            mat[newRow][col].up = 1;
        }

        // Right traversal
        loop(newCol, col, n) {
            if (mat[row][newCol].val == 2 || mat[row][newCol].right == 1)
                break;
            mat[row][newCol].val = 1;
            mat[row][newCol].right = 1;
        }

        // Down traversal
        loop(newRow, row, m) {
            if (mat[newRow][col].val == 2 || mat[newRow][col].down == 1)
                break;
            mat[newRow][col].val = 1;
            mat[newRow][col].down = 1;
        }

        // Left traversal
        revloop(newCol, col, 0) {
            if (mat[row][newCol].val == 2 || mat[row][newCol].left == 1)
                break;
            mat[row][newCol].val = 1;
            mat[row][newCol].left = 1;
        }
    }

  public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<Cell>> mat(m, vector<Cell>(n, {0, 0, 0, 0, 0}));
        iterate(it, walls)
            mat[it[0]][it[1]].val = 2;

        iterate(it, guards) {
            int row = it[0];
            int col = it[1];
            markGuarded(row, col, mat, m, n);
        }

        int count = 0;
        iterate(it, mat)
            iterate(i, it)
                if (i.val == 0)
                    count++;

        return count;
    }
};

int main() {
    Solution obj;
    vvi g = {{0, 0}, {1, 1}, {2, 3}};
    vvi w = {{0, 1}, {2, 2}, {1, 4}};
    println(obj.countUnguarded(4, 6, g, w));
    g = {{1, 1}};
    w = {{0, 1}, {1, 0}, {2, 1}, {1, 2}};
    println(obj.countUnguarded(3, 3, g, w));
}

/*
Problem: Count Unguarded Cells in the Grid
*/