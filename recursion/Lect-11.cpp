#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &v, int n, vector<vector<int>> &ans, vector<int> &ds)
{
    ans.push_back(ds);
    for (int i = ind; i < n; i++)
    {
        if (i != ind && v[i] == v[i - 1])
            continue;
        ds.push_back(v[i]);
        solve(i + 1, v, n, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> subsetSums(vector<int> &v, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(v.begin(), v.end());
    solve(0, v, n, ans, ds);
    return ans;
}
int main()
{
    int n = 6;
    vector<int> v = {1, 2, 2, 2, 3, 3};
    vector<vector<int>> result = subsetSums(v, n);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Given array may contain duplicates, return all possible subsets (the power set).
    Note: The solution set must not contain duplicate subsets. Return the solution in any order.
*/