#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
int singleNumber(vector<int> &nums)
{
    int xorr = 0;
    for (int i = 0; i < nums.size(); i++)
        xorr = xorr ^ nums[i];
    return xorr;
}
int main()
{
    vi v = {4, 1, 2, 1, 2};
    cout << singleNumber(v) << endl;
    return 0;
}

/*
Problem: Single Number
*/