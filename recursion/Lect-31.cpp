#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result)
{
    result.push_back(current);
    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        current.push_back(nums[i]);
        solve(i + 1, nums, current, result);
        current.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(begin(nums), end(nums));
    vector<vector<int>> result;
    vector<int> current;
    solve(0, nums, current, result);
    return result;
}
int main()
{
    vi v = {1, 2, 2};
    vvi result = subsetsWithDup(v);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Subsets - II
*/