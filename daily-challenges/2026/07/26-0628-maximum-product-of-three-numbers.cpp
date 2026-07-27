#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        iterate(num, nums) {
            if (max1 < num) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (max2 < num) {
                max3 = max2;
                max2 = num;
            } else if (max3 < num)
                max3 = num;

            if (min1 > num) {
                min2 = min1;
                min1 = num;
            } else if (min2 > num)
                min2 = num;
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3};
    auto res = obj.maximumProduct(v);
    print(res);
    v = {1, 2, 3, 4};
    res = obj.maximumProduct(v);
    print(res);
    v = {-1, -2, -3};
    res = obj.maximumProduct(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Product of Three Numbers
*/