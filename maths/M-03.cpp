#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    vector<bool> primes(n, true);
    for (int i = 2; i * i <= n; i++)
        if (primes[i])
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
    int result = 0;
    for (int i = 2; i < n; i++)
        if (primes[i])
            result++;
    return result;
}
int main()
{
    cout << countPrimes(10) << endl;
    return 0;
}

/*
Problem: Count Primes
*/