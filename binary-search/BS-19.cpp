#include <bits/stdc++.h>
using namespace std;
int numberOfGasStationsRequired(long double dist, vector<int> &stations)
{
    int n = stations.size();
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((stations[i] - stations[i - 1]) / dist);
        if ((stations[i] - stations[i - 1]) == (dist * numberInBetween))
            numberInBetween--;
        cnt += numberInBetween;
    }
    return cnt;
}
long double findSmallestMaxDist(vector<int> &stations, int k)
{
    int n = stations.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
        high = max(high, (long double)(stations[i + 1] - stations[i]));
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = low + (high - low) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, stations);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << findSmallestMaxDist(v, 9) << endl;
    return 0;
}

/*
Problem: Minimize Max Distance to Gas Station.
*/