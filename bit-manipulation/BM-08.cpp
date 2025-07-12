#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    return ((n - 1) & n) == 0;
}
int main()
{
    cout << isPowerOfTwo(16) << endl;
    return 0;
}

/*
Problem: Set the Rightmost Unset Bit
*/