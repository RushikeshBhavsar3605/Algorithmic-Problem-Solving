#include <bits/stdc++.h>
using namespace std;
void findCombination(int ind, int target, vector<int> &v, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < v.size(); i++)
    {
        if (i != ind && v[i] == v[i - 1])
            continue;
        if (v[i] > target)
            break;
        ds.push_back(v[i]);
        findCombination(i + 1, target - v[i], v, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &v, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, k, v, ans, ds);
    return ans;
}
int main()
{
    int k = 4;
    vector<int> v = {1, 1, 1, 2, 2};
    vector<vector<int>> result = combinationSum(v, k);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
}

/*
Problem: Print unique combinations whose sum is equal to target (elements can be pick only once).
    Note: The solution set must not contain duplicate combinations.
*/