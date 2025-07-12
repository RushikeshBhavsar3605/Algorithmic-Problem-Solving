#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int cnt_max = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(arr[i], 1);
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
int main()
{
    vector<vector<int>> mat = {
        {0, 0},
        {1, 1},
        {0, 1}};
    cout << rowWithMax1s(mat) << endl;
    return 0;
}

/*
Problem: Row With Max Ones (Sorted).
*/