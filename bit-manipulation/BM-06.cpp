#include <bits/stdc++.h>
using namespace std;
int replaceBit(int n, int k)
{
    int temp = n;
    int pos = 0;
    while (temp)
        temp /= 2, pos++;
    return n & ~(1 << (pos - k));
}
int main()
{
    cout << replaceBit(13, 2) << endl;
    return 0;
}

/*
Problem: Replace the Bit
*/