#include <bits/stdc++.h>
using namespace std;
vector<int> findPrimeFactors(int N)
{
    vector<int> primes(N + 1);
    for (int i = 2; i <= N; i++)
        primes[i] = i;
    for (int i = 1; i * i <= N; i++)
        if (primes[i] == i)
            for (int j = i * i; j <= N; j += i)
                primes[j] = min(primes[j], i);
    vector<int> result;
    while (N != 1)
    {
        result.push_back(primes[N]);
        N /= primes[N];
    }
    return result;
}
int main()
{
    vector<int> result = findPrimeFactors(12246);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Prime Factorization using Sieve
*/