#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void solve(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, path, res);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    solve(0, s, path, res);
    return res;
}
int main()
{
    string s = "aabb";
    vector<vector<string>> result = partition(s);
    for (auto it : result)
    {
        for (auto i : it)
            cout << "[" << i << "]" << " ";
        cout << endl;
    }
    return 0;
}

/*
Problem: Palindrome Partitioning.
*/