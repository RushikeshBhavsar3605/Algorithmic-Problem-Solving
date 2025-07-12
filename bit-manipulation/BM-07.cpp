#include <bits/stdc++.h>
using namespace std;
int toggleBit(int n, int k)
{
    return n ^ (1 << (k));
}
int main()
{
    cout << toggleBit(13, 2) << endl;
    return 0;
}

/*
Problem: Toggle the K-th Bit
*/