#include "template.hpp"

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int n = sz(nums);
        umap<int, int> mp;
        mp[0] = 1;

        int res = 0, sum = 0;
        iterate(num, nums) {
            sum += num;

            if (mp.count(sum - k))
                res += mp[sum - k];

            mp[sum]++;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 1, 1};
    auto res = obj.subarraySum(v, 2);
    print(res);
    v = {1, 2, 3};
    res = obj.subarraySum(v, 3);
    print(res);
    return 0;
}

/*
Problem: Subarray Sum Equals K
*/