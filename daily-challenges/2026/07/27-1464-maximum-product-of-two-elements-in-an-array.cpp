#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int max1 = 0, max2 = 0;

        iterate(num, nums) {
            if (max1 < num) {
                max2 = max1;
                max1 = num;
            } else if (max2 < num)
                max2 = num;
        }

        return (max1 - 1) * (max2 - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 4, 5, 2};
    auto res = obj.maxProduct(v);
    print(res);
    v = {1, 5, 4, 5};
    res = obj.maxProduct(v);
    print(res);
    v = {3, 7};
    res = obj.maxProduct(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Product of Two Elements in an Array
*/