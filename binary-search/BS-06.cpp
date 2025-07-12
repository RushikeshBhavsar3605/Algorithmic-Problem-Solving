#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[low] <= v[high])
        {
            ans = min(ans, v[low]);
            break;
        }
        if (v[low] <= v[mid])
        {
            ans = min(ans, v[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, v[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int findMinForDuplicates(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[low] == v[mid] && v[mid] == v[high])
        {
            low++, high--;
            continue;
        }
        if (v[low] <= v[high])
        {
            ans = min(ans, v[low]);
            break;
        }
        if (v[low] <= v[mid])
        {
            ans = min(ans, v[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, v[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {7, 8, 1, 2, 3, 4, 5, 6};
    vector<int> v2 = {3, 3, 1, 3, 3, 3, 3};
    cout << findMin(v) << endl;
    cout << findMinForDuplicates(v2) << endl;
    return 0;
}

/*
Problem: Minimum in Rotated Sorted Array.
*/