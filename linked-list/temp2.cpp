#include <bits/stdc++.h>
using namespace std;
int binarySearch(int group, vector<int> &elements)
{
    int low = 0, high = elements.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (group % elements[mid] == 0 && group >= elements[mid])
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
vector<int> assignElements(vector<int> &groups, vector<int> &elements)
{
    int n = groups.size();
    int m = elements.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        // for (int j = 0; j < m; j++)
        // {
        //     if (groups[i] % elements[j] == 0 && groups[i] >= elements[j])
        //     {
        //         ans[i] = j;
        //         break;
        //     }
        // }
        ans[i] = binarySearch(groups[i], elements);
    }
    return ans;
}
int main()
{
    vector<int> v1 = {2, 3, 5, 7};
    vector<int> v2 = {5, 3, 3};
    vector<int> result = assignElements(v1, v2);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem:
*/