#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool solve(int index, int row, int col, const string &word, vector<vector<char>> &board)
{
    if (index == word.size())
        return true;
    if (row < 0 || col < 0 || row == board.size() || col == board[0].size() || board[row][col] == '!' || word[index] != board[row][col])
        return false;
    char character = board[row][col];
    board[row][col] = '!';
    bool found = solve(index + 1, row - 1, col, word, board) ||
                 solve(index + 1, row, col - 1, word, board) ||
                 solve(index + 1, row + 1, col, word, board) ||
                 solve(index + 1, row, col + 1, word, board);
    board[row][col] = character;
    return found;
}
bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            if (solve(0, i, j, word, board))
                return true;
    return false;
}
int main()
{
    vector<vector<char>> v = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << exist(v, "ABCCED") << endl;
    return 0;
}

/*
Problem: Word Search
*/