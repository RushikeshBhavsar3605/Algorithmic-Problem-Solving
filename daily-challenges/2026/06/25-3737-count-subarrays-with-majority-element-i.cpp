#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int countMajoritySubarrays(vector<int> &nums, int target) {
        int n = sz(nums);
        int res = 0;

        loop(i, 0, n) {
            int cnt = 0;
            loop(j, i, n) {
                if (nums[j] == target)
                    cnt++;

                if (cnt > ((j - i + 1) >> 1))
                    res++;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 2, 3};
    auto res = obj.countMajoritySubarrays(v, 2);
    print(res);
    v = {1, 1, 1, 1};
    res = obj.countMajoritySubarrays(v, 1);
    print(res);
    v = {1, 2, 3};
    res = obj.countMajoritySubarrays(v, 4);
    print(res);
    return 0;
}

/*
Problem: Count Subarrays With Majority Element I
*/