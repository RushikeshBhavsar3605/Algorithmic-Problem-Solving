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

/* Approach 1 (Recursion): */
class Solution {
  private:
    bool isSafe(int row, int col, vector<vector<char>> &board, char ch) {
        // check row, column, and 3x3 subgrid
        loop(i, 0, 9) {
            if (board[i][col] == ch)
                return false;

            if (board[row][i] == ch)
                return false;

            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
                return false;
        }

        return true;
    }

    bool solve(int row, int col, vector<vector<char>> &board) {
        if (row == 9)
            return true;                        // solved all rows

        if (col == 9)
            return solve(row + 1, 0, board);    // move to next row

        if (board[row][col] != '.')
            return solve(row, col + 1, board);  // skip filled cells

        // try digits 1–9
        for (char i = '1'; i <= '9'; i++)
            if (isSafe(row, col, board, i)) {
                board[row][col] = i;
                if (solve(row, col + 1, board))
                    return true;       // continue with next cell
                board[row][col] = '.'; // backtrack
            }

        return false; // no valid digit
    }

  public:
    void solveSudoku(vector<vector<char>> &board) {
        solve(0, 0, board); // start from top-left
    }
};

int main() {
    Solution obj;
    vector<vector<char>> v = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    obj.solveSudoku(v);
    dump2D(v);
}

/*
Problem: Sudoku Solver
*/