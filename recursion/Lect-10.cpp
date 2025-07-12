#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &v, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }
    solve(ind + 1, v, n, ans, sum + v[ind]);
    solve(ind + 1, v, n, ans, sum);
}
vector<int> subsetSums(vector<int> &v, int n)
{
    vector<int> ans;
    solve(0, v, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n = 3;
    vector<int> v = {3, 1, 2};
    vector<int> result = subsetSums(v, n);
    for (auto i : result)
        cout << i << " ";
    return 0;
}

/*
Problem: Print sums of all subsets in array (in increasing order).
*/