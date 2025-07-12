#include <bits/stdc++.h>
using namespace std;
bool canFit(vector<int> &position, int dist, int m)
{
    int n = position.size();
    int cntBalls = 1;
    int last = position[0];
    for (int i = 1; i < n; i++)
    {
        if (position[i] - last >= dist)
        {
            cntBalls++;
            last = position[i];
        }
        if (cntBalls >= m)
            return true;
    }
    return false;
}
int maxDistance(vector<int> &position, int m)
{
    int n = position.size();
    sort(position.begin(), position.end());
    int low = 1, high = position[n - 1] - position[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canFit(position, mid, m))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 7};
    cout << maxDistance(v, 3) << endl;
    return 0;
}

/*
Problem: Magnetic Force Between Two Balls.
*/