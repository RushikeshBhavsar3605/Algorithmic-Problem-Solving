#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k)
{
    int n = a.size();
    int m = b.size();
    if (m > n)
        return kthElement(b, a, k);
    int left = k;
    int low = max(0, k - m), high = min(k, n);
    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n)
            r1 = a[mid1];
        if (mid2 < m)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int main()
{
    vector<int> v1 = {2, 3, 6, 7, 9};
    vector<int> v2 = {1, 4, 8, 10};
    cout << kthElement(v1, v2, 5) << endl;
    return 0;
}

/*
Problem: Kth Element of Two Sorted Arrays.
*/