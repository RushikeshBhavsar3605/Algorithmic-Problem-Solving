#include <bits/stdc++.h>
using namespace std;
string solve(string &s, int left, int right)
{
    int n = s.size();
    while (left >= 0 && right < n && s[left] == s[right])
    {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}
string longestPalindrome(string s)
{
    int n = s.size();
    if (n <= 1)
        return s;
    string max_str = s.substr(0, 1);
    for (int i = 0; i < n - 1; i++)
    {
        string odd = solve(s, i, i);
        string even = solve(s, i, i + 1);
        if (odd.size() > max_str.size())
            max_str = odd;
        if (even.size() > max_str.size())
            max_str = even;
    }
    return max_str;
}
int main()
{
    cout << longestPalindrome("babad") << endl;
    return 0;
}

/*
Problem: Longest Palindromic Substring.
*/