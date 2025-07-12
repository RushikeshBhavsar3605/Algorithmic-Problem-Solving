#include <bits/stdc++.h>
using namespace std;
bool isEven(int n)
{
    return n == ((n >> 1) << 1);
}
int main()
{
    cout << isEven(4) << endl;
    return 0;
}

/*
Problem: Odd or Even
*/