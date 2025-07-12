#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int n = s.size();
    double result = 0;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool pos = s[i] == '+';
    bool neg = s[i] == '-';
    pos == true ? i++ : i;
    neg == true ? i++ : i;
    while (i < n && s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    result = neg ? -result : result;
    result = (result > INT_MAX) ? INT_MAX : result;
    result = (result < INT_MIN) ? INT_MIN : result;
    return int(result);
}
int main()
{
    cout << myAtoi("1337c0d3") << endl;
    return 0;
}

/*
Problem: String to Integer (atoi).
*/