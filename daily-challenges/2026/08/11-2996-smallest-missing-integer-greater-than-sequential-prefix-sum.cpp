#include "template.hpp"

/* Approach (Inplace Hashing): */
class Solution {
  public:
    int missingInteger(vector<int> &nums) {
        int n = sz(nums);
        int sum = nums[0];

        int i = 1;
        while (i < n && nums[i - 1] + 1 == nums[i])
            sum += nums[i++];

        loop(j, 0, n) {
            int idx = abs(nums[j]) - sum;
            if (0 <= idx && idx < n)
                nums[idx] = -abs(nums[idx]);
        }

        loop(j, 0, n)
            if (nums[j] > 0)
                return sum + j;

        return sum + n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 2, 5};
    auto res = obj.missingInteger(v);
    print(res);
    v = {3, 4, 5, 1, 12, 14, 13};
    res = obj.missingInteger(v);
    print(res);
    v = {19, 20, 21, 22};
    res = obj.missingInteger(v);
    print(res);
    return 0;
}

/*
Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
*/