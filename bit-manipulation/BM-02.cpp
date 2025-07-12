#include <bits/stdc++.h>
using namespace std;
bool checkKthBit(int n, int k)
{
    return (n >> k) & 1;
}
int main()
{
    cout << checkKthBit(500, 3) << endl;
    return 0;
}

/*
Problem: K-th Bit is Set or Not
*/