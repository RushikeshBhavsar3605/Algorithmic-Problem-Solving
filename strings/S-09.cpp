#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    int n = s.size();
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
            cnt++;
        else if (ch == ')')
            cnt--;
        maxi = max(maxi, cnt);
    }
    return maxi;
}
int main()
{
    cout << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    return 0;
}

/*
Problem: Maximum Nesting Depth of the parentheses.
*/