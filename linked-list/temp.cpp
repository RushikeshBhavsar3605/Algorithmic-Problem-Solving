#include <bits/stdc++.h>
using namespace std;
void sortDiagonals(vector<vector<int>> &matrix, int rowStart, int colStart, int rowCount, int colCount, bool flag)
{
    int row = rowStart, col = colStart;
    vector<int> diagonalElements;
    while (row < rowCount && col < colCount)
    {
        diagonalElements.push_back(matrix[row][col]);
        row++;
        col++;
    }
    if (!flag)
        sort(diagonalElements.begin(), diagonalElements.end());
    else
        sort(diagonalElements.begin(), diagonalElements.end(), greater<int>());
    row = rowStart;
    col = colStart;
    for (auto element : diagonalElements)
    {
        matrix[row][col] = element;
        row++;
        col++;
    }
}
vector<vector<int>> solve(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    for (int row = 0; row < rowCount; row++)
        sortDiagonals(matrix, row, 0, rowCount, colCount, true);
    for (int col = 1; col < colCount; col++)
        sortDiagonals(matrix, 0, col, rowCount, colCount, false);
    return matrix;
}
int main()
{
    vector<vector<int>> v = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    v = solve(v);
    for (auto i : v)
    {
        for (auto it : i)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem:
*/