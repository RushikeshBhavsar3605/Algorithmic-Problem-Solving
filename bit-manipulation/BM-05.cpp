#include <bits/stdc++.h>
using namespace std;
int setKthBit(int n, int k)
{
    return (1 << k) | n;
}
int main()
{
    cout << setKthBit(9, 2) << endl;
    return 0;
}

/*
Problem: Set K-th Bit
*/