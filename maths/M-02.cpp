#include <bits/stdc++.h>
using namespace std;
void print_divisors(int n)
{
    vector<int> result;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            result.push_back(i);
            if (n / i != i)
                result.push_back(n / i);
        }
    sort(begin(result), end(result));
    for (auto i : result)
        cout << i << " ";
}
int main()
{
    print_divisors(20);
    return 0;
}

/*
Problem: All divisors of a Number
*/