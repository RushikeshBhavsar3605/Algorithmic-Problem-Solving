#include <bits/stdc++.h>
using namespace std;
int upperBound(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += upperBound(mat[i], target);
    return cnt;
}
int median(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(mat, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
    cout << median(mat) << endl;
    return 0;
}

/*
Problem: Median in a Row Wise Sorted Matrix.
*/