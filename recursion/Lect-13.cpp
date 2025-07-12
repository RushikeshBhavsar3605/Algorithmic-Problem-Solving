#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &v, int n, vector<vector<int>> &ans)
{
    if (ind == n)
    {
        ans.push_back(v);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        swap(v[ind], v[i]);
        solve(ind + 1, v, n, ans);
        swap(v[ind], v[i]);
    }
}
vector<vector<int>> permutation(vector<int> &v, int n)
{
    vector<vector<int>> ans;
    solve(0, v, n, ans);
    return ans;
}
int main()
{
    int n = 3;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> result = permutation(v, n);
    for (auto it : result)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Return all possible permutations of an array (answer is accepted in any order) (without using extra space).
*/