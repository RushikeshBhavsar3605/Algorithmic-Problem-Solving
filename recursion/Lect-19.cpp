#include <bits/stdc++.h>
using namespace std;
void solve(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<string> &ans, string path, int n, int m, vector<int> &dRow, vector<int> &dCol)
{
    if (row == n - 1 && col == m - 1)
    {
        ans.push_back(path);
        return;
    }
    string dir = "UDLR";
    for (int ind = 0; ind < 4; ind++)
    {
        int nextRow = row + dRow[ind];
        int nextCol = col + dCol[ind];
        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && !vis[nextRow][nextCol] && mat[nextRow][nextCol])
        {
            vis[row][col] = 1;
            solve(nextRow, nextCol, mat, vis, ans, path + dir[ind], n, m, dRow, dCol);
            vis[row][col] = 0;
        }
    }
}
vector<string> findPath(vector<vector<int>> &mat, int n, int m)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> dRow = {-1, +1, 0, 0};
    vector<int> dCol = {0, 0, -1, +1};
    solve(0, 0, mat, vis, ans, "", n, m, dRow, dCol);
    return ans;
}
int main()
{
    int n = 4, m = 4;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};
    vector<string> result = findPath(mat, n, m);
    for (auto i : result)
        cout << i << endl;
    return 0;
}

/*
Problem: Rat in maze.
*/