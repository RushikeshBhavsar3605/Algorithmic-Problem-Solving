#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int row, int col, vector<vector<int>> &mat, string &path, vector<string> &result)
{
    if (row == mat.size() - 1 && col == mat[0].size() - 1)
    {
        result.push_back(path);
        return;
    }
    vector<int> dRow = {-1, 1, 0, 0};
    vector<int> dCol = {0, 0, -1, 1};
    vector<char> dir = {'U', 'D', 'L', 'R'};
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];
        if (newRow >= 0 && newRow < mat.size() &&
            newCol >= 0 && newCol < mat[0].size() &&
            mat[newRow][newCol] == 1)
        {
            mat[newRow][newCol] = -1;
            path.push_back(dir[i]);
            solve(newRow, newCol, mat, path, result);
            path.pop_back();
            mat[newRow][newCol] = 1;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> result;
    string path;
    if (mat[0][0] == 1)
        mat[0][0] = -1;
    solve(0, 0, mat, path, result);
    return result;
}
int main()
{
    vvi mat = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 0, 1, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1}};
    vector<string> result = findPath(mat);
    for (auto i : result)
        cout << i << endl;
    return 0;
}

/*
Problem: Rat in a maze
*/