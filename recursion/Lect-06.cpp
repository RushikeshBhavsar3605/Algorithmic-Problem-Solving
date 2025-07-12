#include <bits/stdc++.h>
using namespace std;
void solve(int ind, vector<int> &ans, vector<int> v, int n)
{
    if (ind == n)
    {
        if (ans.size() == 0)
            cout << "{}";
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
        return;
    }
    ans.push_back(v[ind]);
    solve(ind + 1, ans, v, n);
    ans.pop_back();
    solve(ind + 1, ans, v, n);
}
int main()
{
    vector<int> v = {3, 1, 2};
    vector<int> ans;
    solve(0, ans, v, v.size());
    return 0;
}

/*
Problem: 1. Print all Subsequences.
    Subsequence Defination:** A contiguous/non-contiguous sequence, which follows the order.
*/