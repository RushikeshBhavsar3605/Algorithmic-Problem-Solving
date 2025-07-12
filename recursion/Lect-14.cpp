#include <bits/stdc++.h>
using namespace std;
bool isSafe(int row, int col, vector<string> &board, int n)
{
}
void solve(int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[n - 1 + col - row] == 0 && upperDiagonal[row + col] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[n - 1 + col - row] = 1;
            upperDiagonal[row + col] = 1;
            solve(col + 1, ans, board, leftRow, lowerDiagonal, upperDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[n - 1 + col - row] = 0;
            upperDiagonal[row + col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    solve(0, ans, board, leftRow, lowerDiagonal, upperDiagonal, n);
    return ans;
}
int main()
{
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << endl;
        cout << endl;
    }
}

/*
Problem: N-Queens Optimized approach by using hash table.
*/