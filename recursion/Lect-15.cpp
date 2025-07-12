#include <bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, vector<vector<char>> &board, int c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == c)
            return false;
        if (board[i][col] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
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
    for (char c = '1'; c <= '9'; c++)
    {
        if (isValid(row, col, board, c))
        {
            board[row][col] = c;
            if (solve(row, col + 1, board))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}
vector<vector<char>> solveSudoku(vector<vector<char>> &board)
{
    solve(0, 0, board);
    return board;
}
int main()
{
    vector<vector<char>> board = {
        {'3', '.', '6', '5', '.', '8', '4', '.', '.'},
        {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
        {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
        {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
        {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
        {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
        {'.', '.', '5', '2', '.', '6', '3', '.', '.'}};
    vector<vector<char>> result = solveSudoku(board);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
}

/*
Problem: Sudoku Solver.
*/