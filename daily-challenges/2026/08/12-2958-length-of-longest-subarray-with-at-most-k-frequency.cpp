#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        umap<int, int> mp;
        int maxi = 0;

        int left = 0;
        loop(right, 0, sz(nums)) {
            mp[nums[right]]++;

            while (mp[nums[right]] > k)
                mp[nums[left++]]--;

            updateMax(maxi, right - left + 1);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 1, 2, 3, 1, 2};
    auto res = obj.maxSubarrayLength(v, 2);
    print(res);
    v = {1, 2, 1, 2, 1, 2, 1, 2};
    res = obj.maxSubarrayLength(v, 1);
    print(res);
    v = {5, 5, 5, 5, 5, 5, 5};
    res = obj.maxSubarrayLength(v, 4);
    print(res);
    return 0;
}

/*
Problem: Length of Longest Subarray With at Most K Frequency
*/