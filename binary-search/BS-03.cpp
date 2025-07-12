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
pair<int, int> firstAndLastPosition(vector<int> &v, int n, int target)
{
    int lb = lowerBound(v, target);
    if (lb == n || v[lb] != target)
        return {-1, -1};
    return {lb, upperBound(v, target) - 1};
}
int firstOccurrence(vector<int> &v, int n, int target)
{
    int low = 0, high = n - 1, first = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            first = mid, high = mid - 1;
        else if (v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}
int lastOccurrence(vector<int> &v, int n, int target)
{
    int low = 0, high = n - 1, last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            last = mid, low = mid + 1;
        else if (v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}
int main()
{
    vector<int> v = {3, 4, 6, 8, 8, 12, 16, 17};
    pair<int, int> result = firstAndLastPosition(v, v.size(), 8);
    cout << result.first << " " << result.second << endl;

    cout << firstOccurrence(v, v.size(), 8) << " " << lastOccurrence(v, v.size(), 8) << endl;
    return 0;
}

/*
Problem: First and Last Occurrences in Array.
*/