#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    int n = s.size();
    string ans = "";
    int balance = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            if (balance > 0)
                ans += ch;
            balance++;
        }
        else
        {
            balance--;
            if (balance > 0)
                ans += ch;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 4, 5, 10};
    cout << removeOuterParentheses("(()())(())(()(()))") << endl;
    return 0;
}

/*
Problem: Remove Outermost Parentheses.
*/