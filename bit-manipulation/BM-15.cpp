#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
int calculateXOR(int n)
{
    if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
    else
        return n;
}
int findXOR(int l, int r)
{
    return calculateXOR(r) ^ calculateXOR(l - 1);
}
int main()
{
    cout << findXOR(4, 8) << endl;
    return 0;
}

/*
Problem: Find XOR of Numbers from L to R
*/