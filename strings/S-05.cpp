#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t)
{
    int n = s.size();
    unordered_map<char, int> charIndexS;
    unordered_map<char, int> charIndexT;
    for (int i = 0; i < n; i++)
    {
        if (charIndexS.find(s[i]) == charIndexS.end())
            charIndexS[s[i]] = i;
        if (charIndexT.find(t[i]) == charIndexT.end())
            charIndexT[t[i]] = i;
        if (charIndexS[s[i]] != charIndexT[t[i]])
            return false;
    }
    return true;
}
int main()
{
    cout << isIsomorphic("egg", "add") << endl;
    return 0;
}

/*
Problem: Isomorphic Strings.
*/