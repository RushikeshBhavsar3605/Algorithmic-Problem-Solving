#include <bits/stdc++.h>
using namespace std;
string postfixToPrefix(string &s)
{
    stack<string> st;
    for (auto &it : s)
        if (('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z'))
            st.push(string(1, it));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string concat = it + t2 + t1;
            st.push(concat);
        }
    return st.top();
}
int main()
{
    string s = "AB+";
    cout << postfixToPrefix(s) << endl;
    return 0;
}

/*
Problem: Postfix to Prefix Conversion
*/