#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &v, int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            return mid;
        if (v[low] <= v[mid])
        {
            if (v[low] <= target && target <= v[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (v[mid] <= target && target <= v[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << search(v, v.size(), 1) << endl;
    return 0;
}

/*
Problem: Search Element in Rotated Sorted Array - I (Unique Elements).
*/