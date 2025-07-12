#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[low] <= v[high])
        {
            if (v[low] < ans)
            {
                index = low;
                ans = v[low];
            }
            break;
        }
        if (v[low] <= v[mid])
        {
            if (v[low] < ans)
            {
                index = low;
                ans = v[low];
            }
            low = mid + 1;
        }
        else
        {
            if (v[mid] < ans)
            {
                index = mid;
                ans = v[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}
int findKRotationForDuplicates(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    int ans = INT_MAX;
    int index = -1;
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
            if (v[low] < ans)
            {
                index = low;
                ans = v[low];
            }
            break;
        }
        if (v[low] <= v[mid])
        {
            if (v[low] < ans)
            {
                index = low;
                ans = v[low];
            }
            low = mid + 1;
        }
        else
        {
            if (v[low] < ans)
            {
                index = low;
                ans = v[low];
            }
            high = mid - 1;
        }
    }
    return index;
}
int main()
{
    vector<int> v = {7, 8, 1, 2, 3, 4, 5, 6};
    vector<int> v2 = {3, 3, 1, 3, 3, 3, 3};
    cout << findKRotation(v) << endl;
    cout << findKRotationForDuplicates(v2) << endl;
    return 0;
}

/*
Problem: Find out how many times array has been rotated.
*/