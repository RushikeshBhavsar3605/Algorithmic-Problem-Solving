#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vector<int> singleNumber(vector<int> &nums)
{
    int xor2no = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    unsigned int diff = xor2no & -(unsigned int)xor2no;
    vector<int> result = {0, 0};

    for (int num : nums)
    {
        if ((num & diff) == 0)
            result[0] ^= num;
        else
            result[1] ^= num;
    }

    return result;
}
int main()
{
    vi v = {1, 2, 1, 3, 2, 5};
    vi result = singleNumber(v);
    for (auto i : result)
        cout << i << " ";
    cout << endl;
    return 0;
}

/*
Problem: Single Number - III
*/