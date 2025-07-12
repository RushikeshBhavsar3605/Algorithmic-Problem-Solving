#include <bits/stdc++.h>
using namespace std;
void bitManipulation(int num, int i)
{
    int getBit = (num >> (i - 1)) & 1;
    int setBit = num | (1 << (i - 1));
    int clearBit = num & ~(1 << (i - 1));
    cout << getBit << " " << setBit << " " << clearBit;
}
int main()
{
    bitManipulation(70, 3);
    return 0;
}

/*
Problem: Bit Manipulation
*/