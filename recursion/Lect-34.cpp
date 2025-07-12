#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool isPalindrome(string s, int start, int end)
{
    while (start < end)
        if (s[start++] != s[end--])
            return false;
    return true;
}
void solve(int index, string s, vector<string> &current, vector<vector<string>> &result)
{
    if (index == s.size())
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        if (!isPalindrome(s, index, i))
            continue;
        current.push_back(s.substr(index, i - index + 1));
        solve(i + 1, s, current, result);
        current.pop_back();
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> current;
    solve(0, s, current, result);
    return result;
}
int main()
{
    vector<vector<string>> result = partition("aab");
    for (auto it : result)
    {
        cout << "[";
        for (auto i : it)
            cout << i << " ";
        cout << "]" << endl;
    }
    return 0;
}

/*
Problem: Palindrome Partitioning
*/