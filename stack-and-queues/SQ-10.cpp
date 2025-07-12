#include <bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    reverse(begin(s), end(s));
    string result;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (('A' <= s[i] && s[i] <= 'Z') ||
            ('a' <= s[i] && s[i] <= 'z') ||
            ('0' <= s[i] && s[i] <= '9'))
            result += s[i];

        else if (s[i] == ')')
            st.push(s[i]);

        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(begin(result), end(result));
    return result;
}
int main()
{
    cout << infixToPrefix("A+B") << endl;
    return 0;
}

/*
Problem: Infix to Prefix Conversion
*/