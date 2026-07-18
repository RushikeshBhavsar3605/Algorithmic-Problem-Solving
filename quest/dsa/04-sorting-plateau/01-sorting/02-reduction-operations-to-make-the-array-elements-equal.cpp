#include "template.hpp"

/* Approach (Sorting): */
class Solution {
  public:
    int reductionOperations(vector<int> &nums) {
        int n = sz(nums);
        sort(all(nums), greater<int>());

        int res = 0;
        loop(i, 1, n)
            if (nums[i - 1] > nums[i])
                res += i;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {5, 1, 3};
    auto res = obj.reductionOperations(v);
    print(res);
    v = {1, 1, 1};
    res = obj.reductionOperations(v);
    print(res);
    v = {1, 1, 2, 2, 3};
    res = obj.reductionOperations(v);
    print(res);
    return 0;
}

/*
Problem: Reduction Operations to Make the Array Elements Equal
*/