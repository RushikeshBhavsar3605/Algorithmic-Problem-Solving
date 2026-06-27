#include "template.hpp"

class Solution {
  public:
    long long countMajoritySubarrays(vector<int> &nums, int target) {
        int n = sz(nums);

        vi countAtSum(2 * n + 2, 0);
        vl countAtSumPrefix(2 * n + 2, 0);

        int idx = n + 1;
        countAtSum[idx] = countAtSumPrefix[idx] = 1;

        ll res = 0;

        iterate(num, nums) {
            if (target == num)
                idx++;
            else
                idx--;

            countAtSum[idx]++;
            res += countAtSumPrefix[idx - 1];

            countAtSumPrefix[idx] = countAtSumPrefix[idx - 1] + countAtSum[idx];
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
Problem: Count Subarrays With Majority Element II
*/