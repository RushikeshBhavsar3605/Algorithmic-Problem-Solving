#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int index, int k, int n, vector<int> &current, vector<bool> &vis, vector<vector<int>> &result)
{
    if (k == 0)
    {
        if (n == 0)
            result.push_back(current);
        return;
    }
    for (int i = index; i <= 9; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        current.push_back(i);
        solve(i + 1, k - 1, n - i, current, vis, result);
        current.pop_back();
        vis[i] = false;
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> vis(10, false);
    solve(1, k, n, current, vis, result);
    return result;
}
int main()
{
    vvi result = combinationSum3(3, 7);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Combination Sum - III
*/