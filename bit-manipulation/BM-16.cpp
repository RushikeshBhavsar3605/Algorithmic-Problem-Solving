#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (int num : nums)
    {
        ones ^= (num & ~twos);
        twos ^= (num & ~ones);
    }
    return ones;
}
int main()
{
    vector<int> v = {2, 2, 3, 2};
    cout << singleNumber(v) << endl;
    return 0;
}

/*
Problem: Single Number - II
*/