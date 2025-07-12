#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &v, int n)
{
    if (n == 1)
        return v[0];
    if (v[0] != v[1])
        return v[0];
    if (v[n - 1] != v[n - 2])
        return v[n - 1];
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] != v[mid - 1] && v[mid] != v[mid + 1])
            return v[mid];
        if (v[mid] == v[mid - 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout << singleNonDuplicate(v, v.size()) << endl;
    return 0;
}

/*
Problem: Single Element in Sorted Array.
*/