#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
    for (auto &it : s)
    {
        if (mp.find(it) == mp.end())
            st.push(it);
        else if (!st.empty() && mp[it] == st.top())
            st.pop();
        else
            return false;
    }
    return st.empty();
}
int main()
{
    cout << isValid("()[]{}") << endl;
    return 0;
}

/*
Problem: Valid Parentheses
*/