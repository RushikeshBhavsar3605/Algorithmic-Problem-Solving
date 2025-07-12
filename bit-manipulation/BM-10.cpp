#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    n++;
    int result = 0;
    for (int i = 0; i < 30; i++)
    {
        int size(1 << (i + 1));
        result += ((n / size) * (size / 2));
        int rem = n % size;
        if (rem - size / 2 > 0)
            result += (rem - size / 2);
    }
    return result;
}
int main()
{
    cout << countSetBits(17) << endl;
    return 0;
}

/*
Problem: Count Total Set Bits
*/