#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    return (s + s).find(goal) != string::npos;
}
int main()
{
    cout << rotateString("abcde", "cdeab") << endl;
    return 0;
}

/*
Problem: Rotate String.
*/