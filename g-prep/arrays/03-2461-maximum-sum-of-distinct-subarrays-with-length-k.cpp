#include "template.hpp"

class Solution {
  public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        int n = sz(nums);
        ll maxi = 0, currSum = 0;
        umap<int, int> mp;

        int left = 0;
        loop(right, 0, n) {
            currSum += nums[right];
            mp[nums[right]]++;

            while (right - left + 1 > k || mp[nums[right]] > 1) {
                currSum -= nums[left];
                mp[nums[left]]--;
                left++;
            }

            if (right - left + 1 == k)
                updateMax(maxi, currSum);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 5, 4, 2, 9, 9, 9};
    auto res = obj.maximumSubarraySum(v, 3);
    print(res);
    v = {4, 4, 4};
    res = obj.maximumSubarraySum(v, 3);
    print(res);
    return 0;
}

/*
Problem: Maximum Sum of Distinct Subarrays With Length K
*/