#include "template.hpp"

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int n = sz(nums);
        int maxi = INT_MIN, sum = 0;

        iterate(num, nums) {
            if (sum < 0)
                sum = 0;

            sum += num;
            updateMax(maxi, max(sum, num));
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto res = obj.maxSubArray(v);
    print(res);
    v = {1};
    res = obj.maxSubArray(v);
    print(res);
    v = {5, 4, -1, 7, 8};
    res = obj.maxSubArray(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Subarray
*/