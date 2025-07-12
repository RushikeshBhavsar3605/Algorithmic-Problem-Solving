#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool isSafe(int row, int col, vector<vector<char>> &board, int ch)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
            return false;
        if (board[row][i] == ch)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }
    return true;
}
bool solve(int row, int col, vector<vector<char>> &board)
{
    if (row == board.size())
        return true;
    if (col == board[0].size())
        return solve(row + 1, 0, board);
    if (board[row][col] != '.')
        return solve(row, col + 1, board);
    for (char i = '1'; i <= '9'; i++)
    {
        if (isSafe(row, col, board, i))
        {
            board[row][col] = i;
            if (solve(row, col + 1, board))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(0, 0, board);
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    solveSudoku(board);
    for (auto it : board)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Sudoku Solver
*/