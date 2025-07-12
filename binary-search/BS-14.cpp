#include <bits/stdc++.h>
using namespace std;
int sumByD(vector<int> &nums, int div)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ceil((double)nums[i] / (double)div);
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int low = 1, high = *max_element(nums.begin(), nums.end());
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (sumByD(nums, mid) <= threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> v = {1, 2, 5, 9};
    cout << smallestDivisor(v, 6) << endl;
    return 0;
}

/*
Problem: Find the Smallest Divisor Given a Threshold.
*/