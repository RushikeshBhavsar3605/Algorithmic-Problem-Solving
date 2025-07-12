#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, vector<int> &candidates, vector<int> &current, vector<vector<int>> &result)
{
    if (index == candidates.size())
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < candidates.size(); i++)
    {
        current.push_back(candidates[i]);
        solve(i + 1, candidates, current, result);
        current.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates)
{
    sort(begin(candidates), end(candidates));
    vector<vector<int>> result;
    vector<int> current;
    solve(0, candidates, current, result);
    return result;
}
int main()
{
    vi v = {1, 2, 3, 4, 5};
    vvi result = combinationSum(v);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Combination Sum - II
1  1  2  5  6  7  10
*/