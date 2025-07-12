#include <bits/stdc++.h>
using namespace std;
vector<int> AllPrimeFactors(int N)
{
    vector<int> result;
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
        {
            result.push_back(i);
            while (N % i == 0)
                N /= i;
        }
    if (N != 1)
        result.push_back(N);
    return result;
}
int main()
{
    vector<int> result = AllPrimeFactors(100);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Prime Factors
*/