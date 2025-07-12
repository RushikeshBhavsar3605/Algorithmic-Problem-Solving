#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
pair<int, int> secondSmallest(vector<int> &v, int n)
{
    int smallest = v[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (smallest > v[i])
        {
            ssmallest = smallest;
            smallest = v[i];
        }
        else if (v[i] <= ssmallest)
            ssmallest = v[i];
    }
    if (ssmallest == INT_MAX)
        return {-1, -1};
    return {smallest, ssmallest};
}
int minOperations(vector<int> &nums, int k)
{
    priority_queue<long long, vector<long long>, greater<long long>> min_heap(nums.begin(), nums.end());
    int cnt = 0;
    while (min_heap.top() < k)
    {
        long long x = min_heap.top();
        min_heap.pop();
        long long y = min_heap.top();
        min_heap.pop();
        min_heap.push(min(x, y) * 2 + max(x, y));
        cnt++;
    }
    return cnt;
}
int main()
{
    vector<int> v = {999999999, 999999999, 999999999};
    cout << minOperations(v, 1000000000) << endl;
    return 0;
}

/*
Problem:
*/