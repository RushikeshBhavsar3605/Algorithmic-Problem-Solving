#include <bits/stdc++.h>
using namespace std;
int searchIterative(vector<int> &v, int target)
{
    int n = v.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int searchRecursive(vector<int> &v, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (v[mid] == target)
        return mid;
    else if (v[mid] < target)
        return searchRecursive(v, mid + 1, high, target);
    else
        return searchRecursive(v, low, mid - 1, target);
}
int main()
{
    vector<int> v = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << searchIterative(v, 6) << endl;
    cout << searchRecursive(v, 0, v.size() - 1, 6) << endl;
    return 0;
}

/*
Problem: Binary Search Iterative/Recursive Code.
*/