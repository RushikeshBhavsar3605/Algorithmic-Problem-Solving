#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (divisor == 1)
        return dividend;

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    int result = 0;

    while (d <= n)
    {
        int p = 0;

        while (n >= (d << p))
            p++;

        p--;
        n -= (d << p);
        result += (1 << p);
    }

    return sign == 1 ? result : -result;
}
int main()
{
    cout << divide(10, 3) << endl;
    return 0;
}

/*
Problem: Divide Two Integers
*/