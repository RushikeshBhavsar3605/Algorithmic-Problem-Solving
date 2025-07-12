#include <bits/stdc++.h>
using namespace std;
bool check(int ind, string s, int n)
{
    if (ind == n / 2)
        return true;
    if (s[ind] != s[n - ind - 1])
        return false;
    return check(ind + 1, s, n);
}
int main()
{
    string s = "racecar";
    cout << check(0, s, s.size()) << endl;
    return 0;
}

/*
Problem: Check if a string is palindrome or not.
*/