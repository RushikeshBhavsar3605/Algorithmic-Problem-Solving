#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string ans;
    if (strs[0].size() == 0)
        return ans;
    int i = 0;
    while (i < strs[0].size())
    {
        if (strs[0][i] == strs[strs.size() - 1][i])
            ans.push_back(strs[0][i]);
        else
            break;
        i++;
    }
    return ans;
}
int main()
{
    vector<string> v = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(v) << endl;
    return 0;
}

/*
Problem: Longest Common Prefix.
*/