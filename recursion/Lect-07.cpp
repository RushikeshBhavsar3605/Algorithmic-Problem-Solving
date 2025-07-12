#include <bits/stdc++.h>
using namespace std;
bool solve(int ind, vector<int> &ans, int s, int sum, vector<int> &v, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    ans.push_back(v[ind]);
    if (solve(ind + 1, ans, s + v[ind], sum, v, n))
        return true;
    ans.pop_back();
    if (solve(ind + 1, ans, s, sum, v, n))
        return true;
    return false;
}
int count(int ind, int s, int sum, vector<int> &v, int n)
{
    if (ind == n)
    {
        if (s == sum)
            return 1;
        return 0;
    }
    int l = count(ind + 1, s + v[ind], sum, v, n);
    int r = count(ind + 1, s, sum, v, n);
    return l + s;
}
int main()
{
    vector<int> v = {1, 2, 1};
    int sum = 2;
    vector<int> ans, ans2;
    solve(0, ans, 0, sum, v, v.size());
    sum = 0;
    cout << count(0, 0, sum, v, v.size()) << endl;
    return 0;
}

/*
Problem 1: Printing Subsequences whose sum is K.
Problem 2: Print any one subsequence whose sum is K.
Problem 3: Count the subsequences with sum equal to K.
*/