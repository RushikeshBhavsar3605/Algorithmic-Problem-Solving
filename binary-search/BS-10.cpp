#include <bits/stdc++.h>
using namespace std;
int floorSqrt(int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
int main()
{
    cout << floorSqrt(28) << endl;
    return 0;
}

/*
Problem: Finding Sqrt of a number using Binary Search.
*/