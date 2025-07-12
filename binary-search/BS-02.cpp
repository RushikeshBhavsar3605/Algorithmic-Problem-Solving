#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &v, int target)
{
    int low = 0, high = v.size() - 1;
    int ans = v.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int upperBound(vector<int> &v, int target)
{
    int low = 0, high = v.size() - 1;
    int ans = v.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> v = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << lowerBound(v, 9) << endl;
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << endl;
    cout << upperBound(v, 9) << endl;
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << endl;
    return 0;
}

/*
Problem: Implement Lower Bound and Upper Bound.
*/