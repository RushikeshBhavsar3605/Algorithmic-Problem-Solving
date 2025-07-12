#include <bits/stdc++.h>
using namespace std;
string prefixToPostfixConversion(string &s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
        if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
            st.push(string(1, s[i]));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string concat = t1 + t2 + s[i];
            st.push(concat);
        }
    return st.top();
}
int main()
{
    string s = "+AB";
    cout << prefixToPostfixConversion(s) << endl;
    return 0;
}

/*
Problem: Prefix to Postfix Conversion
*/