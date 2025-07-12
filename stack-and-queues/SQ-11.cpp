#include <bits/stdc++.h>
using namespace std;
string postToInfix(string postfix)
{
    stack<string> st;
    for (auto &it : postfix)
        if (('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z'))
            st.push(string(1, it));
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string concat = "(" + t2 + it + t1 + ")";
            st.push(concat);
        }
    return st.top();
}
int main()
{
    cout << postToInfix("AB+") << endl;
    return 0;
}

/*
Problem: Postfix to Infix Conversion
*/