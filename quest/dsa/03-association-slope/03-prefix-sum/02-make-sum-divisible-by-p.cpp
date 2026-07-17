#include "template.hpp"

/* Approach (Prefix Sum + Modulo Arithmetic): */
class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        ll total = accumulate(all(nums), 0LL);
        int rem = total % p;
        if (rem == 0)
            return 0;

        umap<int, int> lastIndex;
        lastIndex[0] = -1;

        ll prefix = 0;
        int res = sz(nums);

        loop(i, 0, sz(nums)) {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - rem + p) % p;

            if (lastIndex.count(target))
                updateMin(res, i - lastIndex[target]);

            lastIndex[prefix] = i;
        }

        return res == sz(nums) ? -1 : res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 1, 4, 2};
    auto res = obj.minSubarray(v, 6);
    print(res);
    v = {6, 7, 4};
    res = obj.minSubarray(v, 6);
    print(res);
    v = {6, 3, 5, 2};
    res = obj.minSubarray(v, 9);
    print(res);
    v = {1, 2, 3};
    res = obj.minSubarray(v, 3);
    print(res);
    return 0;
}

/*
Problem: Make Sum Divisible by P
*/