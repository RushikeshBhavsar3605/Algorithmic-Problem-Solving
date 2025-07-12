#include <bits/stdc++.h>
using namespace std;
bool canEatInTime(vector<int> &piles, int k, int hour)
{
    long long totalH = 0;
    for (auto pile : piles)
    {
        int div = pile / k;
        totalH += div;
        if (pile % k != 0)
            totalH++;
    }
    return totalH <= hour;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = 1000000000;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canEatInTime(piles, mid, h))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> v = {3, 6, 7, 11};
    cout << minEatingSpeed(v, 8) << endl;
}

/*
Problem: Koko Eating Bananas.
*/