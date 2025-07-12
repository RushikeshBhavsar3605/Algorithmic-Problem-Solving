#include <bits/stdc++.h>
using namespace std;
vector<int> assignElements(vector<int> &groups, vector<int> &elements)
{
    int n = groups.size();
    int m = elements.size();
    vector<int> ans(n, 0);
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        if (mp.find(elements[i]) == mp.end())
            mp[elements[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int groupSize = groups[i];
        int minIndex = INT_MAX;
        for (int j = 1; j < sqrt(groupSize) + 1; j++)
        {
            if (groupSize % j == 0)
            {
                if (mp.find(j) != mp.end())
                {
                    minIndex = min(minIndex, mp[j]);
                }
                if (j != groupSize / j && mp.find(groupSize / j) != mp.end())
                {
                    minIndex = min(minIndex, mp[groupSize / j]);
                }
            }
        }
        ans[i] = minIndex != INT_MAX ? minIndex : -1;
    }
    return ans;
}
int main()
{
    vector<int> v1 = {1, 1};
    vector<int> v2 = {1};
    vector<int> result = assignElements(v1, v2);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem:
*/