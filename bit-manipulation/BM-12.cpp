#include <bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal)
{
    int result = 0;
    int n = start ^ goal;
    while (n)
        result++, n &= (n - 1);
    return result;
}
int main()
{
    cout << minBitFlips(10, 7) << endl;
    return 0;
}

/*
Problem: Minimum Bit Flips to Convert Number
*/