#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
void solve(int open, int close, vector<string> &result, string &current)
{
    if (open == 0 && close == 0)
    {
        result.push_back(current);
        return;
    }
    if (open > 0)
    {
        current.push_back('(');
        solve(open - 1, close, result, current);
        current.pop_back();
    }
    if (close > 0 && close > open)
    {
        current.push_back(')');
        solve(open, close - 1, result, current);
        current.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> result;
    string current;
    solve(n, n, result, current);
    return result;
}
int main()
{
    vector<string> result = generateParenthesis(3);
    for (auto i : result)
        cout << i << endl;
    return 0;
}

/*
Problem: Generate Parentheses.
*/