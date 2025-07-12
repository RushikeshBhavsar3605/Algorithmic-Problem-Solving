#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool maxSubstringLength(string s, int k)
{
    int n = s.size();
    if (k == 0)
        return true;
    vector<int> left(26, n), right(26, -1);
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        left[c] = min(left[c], i);
        right[c] = max(right[c], i);
    }
    vector<pair<int, int>> intervals;
    string str = s;
    for (int i = 0; i < n; i++)
    {
        if (i != left[s[i] - 'a'])
            continue;
        int end = right[s[i] - 'a'];
        int j = i;
        bool valid = true;
        while (j <= end)
        {
            if (left[s[j] - 'a'] < i)
            {
                valid = false;
                break;
            }
            end = max(end, right[s[j] - 'a']);
            j++;
        }
        if (valid && !(i == 0 && end == n - 1))
            intervals.push_back({i, end});
    }
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    int count = 0, prev = -1;
    for (const auto &inter : intervals)
    {
        if (inter.first > prev)
        {
            count++;
            prev = inter.second;
        }
    }
    return count >= k;
}
int main()
{
    vector<int> v = {2, 1};
    cout << maxSubstringLength("abcdbaefab", 2) << endl;
    return 0;
}

/*
Problem:
*/