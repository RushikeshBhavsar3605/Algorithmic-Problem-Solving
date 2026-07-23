#include "template.hpp"

/* Approach (Bit Manipulation): */
class Solution {
  public:
    int uniqueXorTriplets(vector<int> &nums) {
        int n = sz(nums);
        if (n == 1 || n == 2)
            return n;

        int res = 1;
        while (res <= n)
            res <<= 1;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2};
    auto res = obj.uniqueXorTriplets(v);
    print(res);
    v = {3, 1, 2};
    res = obj.uniqueXorTriplets(v);
    print(res);
    return 0;
}

/*
Problem: Number of Unique XOR Triplets I
*/