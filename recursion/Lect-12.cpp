#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &v, int n, vector<vector<int>> &ans, vector<int> &ds, vector<bool> &freq)
{
    if (ds.size() == n)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!freq[i])
        {
            ds.push_back(v[i]);
            freq[i] = 1;
            solve(v, n, ans, ds, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permutation(vector<int> &v, int n)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> freq(n, 0);
    solve(v, n, ans, ds, freq);
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
Problem: Return all possible permutations of an array (answer is accepted in any order).
*/