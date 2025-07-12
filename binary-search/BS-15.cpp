#include <bits/stdc++.h>
using namespace std;
int findDays(vector<int> &weights, int capacity)
{
    int days = 1;
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > capacity)
        {
            days += 1;
            load = weights[i];
        }
        else
            load += weights[i];
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (findDays(weights, mid) <= days)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << shipWithinDays(v, 5) << endl;
    return 0;
}

/*
Problem: Capacity To Ship Packages Within D Days.
*/