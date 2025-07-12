#include <bits/stdc++.h>
using namespace std;
void findCombination(int ind, vector<int> &v, int target, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == v.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }
    if (v[ind] <= target)
    {
        ds.push_back(v[ind]);
        findCombination(ind, v, target - v[ind], ans, ds);
        ds.pop_back();
    }
    findCombination(ind + 1, v, target, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &v, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, v, k, ans, ds);
    return ans;
}
int main()
{
    int n = 4, k = 7;
    vector<int> v = {2, 3, 6, 7};
    vector<vector<int>> result = combinationSum(v, k);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Print unique combinations whose sum is equal to target (elements can be pick infinite).
*/