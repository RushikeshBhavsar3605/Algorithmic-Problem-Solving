#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define MOD 1000000007
long long power(long long x, long long n)
{
    if (n == 0)
        return 1;
    long long half = power(x, n / 2);
    if (n % 2 == 0)
        return (half * half) % MOD;
    else
        return (half * half * x) % MOD;
}
int countGoodNumbers(long long n)
{
    long long odd = n / 2;
    long long even = n / 2 + n % 2;
    return (power(5, even) * power(4, odd)) % MOD;
}
int main()
{
    cout << countGoodNumbers(5) << endl;
    return 0;
}

/*
Problem:
*/