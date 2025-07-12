#include <bits/stdc++.h>
using namespace std;
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int max_row = 0;
        for (int i = 0; i < n; i++)
        {
            if (mat[max_row][mid] < mat[i][mid])
                max_row = i;
        }
        if ((mid == 0 || mat[max_row][mid] > mat[max_row][mid - 1]) && (mid == m - 1 || mat[max_row][mid] > mat[max_row][mid + 1]))
            return {max_row, mid};
        else if (mid > 0 && mat[max_row][mid - 1] > mat[max_row][mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> result = findPeakGrid(mat);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Find a Peak Element - II.
*/