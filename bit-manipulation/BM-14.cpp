#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vector<vector<int>> subsets(vector<int> &nums)
{
    int subsets = (1 << nums.size());
    vector<vector<int>> result;
    for (int num = 0; num < subsets; num++)
    {
        vector<int> subset;
        for (int i = 0; i < nums.size(); i++)
            if (num & (1 << i))
                subset.push_back(nums[i]);
        result.push_back(subset);
    }
    return result;
}
int main()
{
    vi v = {1, 2, 3};
    vvi result = subsets(v);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Subsets
*/