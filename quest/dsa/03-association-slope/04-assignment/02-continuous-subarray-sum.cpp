#include "template.hpp"

/* Approach (Prefix Sum + Modulo Arithmetic): */
class Solution {
  public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        int n = sz(nums);
        ll prefix = 0;

        umap<int, int> lastIndex;
        lastIndex[0] = -1;

        loop(i, 0, n) {
            prefix = (prefix + nums[i]) % k;

            if (lastIndex.count(prefix)) {
                if (i - lastIndex[prefix] >= 2)
                    return true;
            } else
                lastIndex[prefix] = i;
        }

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {23, 2, 4, 6, 7};
    auto res = obj.checkSubarraySum(v, 6);
    print(res);
    v = {23, 2, 6, 4, 7};
    res = obj.checkSubarraySum(v, 6);
    print(res);
    v = {23, 2, 6, 4, 7};
    res = obj.checkSubarraySum(v, 13);
    print(res);
    return 0;
}

/*
Problem: Continuous Subarray Sum
*/