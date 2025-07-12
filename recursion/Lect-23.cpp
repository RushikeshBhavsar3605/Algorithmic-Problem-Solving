#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
double power(double x, int n)
{
    if (n == 0)
        return 1;
    double half = power(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}
double myPow(double x, int n)
{
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    return power(x, n);
}
int main()
{
    cout << myPow(2, 10) << endl;
    return 0;
}

/*
Problem:
*/