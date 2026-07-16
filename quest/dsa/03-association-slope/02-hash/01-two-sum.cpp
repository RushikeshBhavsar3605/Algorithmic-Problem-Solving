#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        umap<int, int> indexOf;

        loop(i, 0, sz(nums)) {
            int complement = target - nums[i];

            if (indexOf.count(complement))
                return {indexOf[complement], i};

            indexOf[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 7, 11, 15};
    auto res = obj.twoSum(v, 9);
    print(res);
    v = {3, 2, 4};
    res = obj.twoSum(v, 6);
    print(res);
    v = {3, 3};
    res = obj.twoSum(v, 6);
    print(res);
    return 0;
}

/*
Problem: Two Sum
*/