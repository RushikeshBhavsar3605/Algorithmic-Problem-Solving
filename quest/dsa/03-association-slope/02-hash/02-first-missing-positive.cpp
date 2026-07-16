#include "template.hpp"

/* Approach (Inplace Hashing): */
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        int n = sz(nums);
        iterate(num, nums)
            if (num <= 0)
                num = n + 1;

        loop(i, 0, n) {
            int idx = abs(nums[i]) - 1;
            if (idx < n)
                nums[idx] = -abs(nums[idx]);
        }

        loop(i, 0, n)
            if (nums[i] > 0)
                return i + 1;

        return n + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 0};
    auto res = obj.firstMissingPositive(v);
    print(res);
    v = {3, 4, -1, 1};
    res = obj.firstMissingPositive(v);
    print(res);
    v = {7, 8, 9, 11, 12};
    res = obj.firstMissingPositive(v);
    print(res);
    return 0;
}

/*
Problem: First Missing Positive
*/