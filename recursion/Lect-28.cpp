#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, vector<int> &candidates, int target, vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    if (index == candidates.size())
        return;
    if (candidates[index] <= target)
    {
        current.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index], current, result);
        current.pop_back();
    }
    solve(index + 1, candidates, target, current, result);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> current;
    solve(0, candidates, target, current, result);
    return result;
}
int main()
{
    vi v = {2, 3, 6, 7};
    vvi result = combinationSum(v, 7);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Combination Sum
*/