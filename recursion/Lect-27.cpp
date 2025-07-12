#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool isPrime(int num)
{
    if (num == 1)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}
vector<int> closestPrimes(int left, int right)
{
    int num1 = -1;
    int num2 = -1;
    int prev = -1;
    int min = INT_MAX;
    for (int i = left; i <= right; i++)
    {
        if (isPrime(i) && prev != -1 && (i - prev) < min)
        {
            min = (i - prev);
            num1 = prev;
            num2 = i;
        }
        if (isPrime(i))
            prev = i;
    }
    return {num1, num2};
}
int main()
{
    vi v = closestPrimes(10, 19);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Perfect Sum Problem.
*/