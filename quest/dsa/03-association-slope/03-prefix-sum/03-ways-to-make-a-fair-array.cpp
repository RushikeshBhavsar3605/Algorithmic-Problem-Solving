#include "template.hpp"

/* Approach (Prefix Sum): */
class Solution {
  public:
    int waysToMakeFair(vector<int> &nums) {
        int n = sz(nums);
        int rightEven = 0, rightOdd = 0;

        loop(i, 0, n) {
            if (i % 2 == 0)
                rightEven += nums[i];
            else
                rightOdd += nums[i];
        }

        int res = 0;
        int leftEven = 0, leftOdd = 0;

        loop(i, 0, n) {
            if (i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            int evenSum = leftEven + rightOdd;
            int oddSum = leftOdd + rightEven;

            if (evenSum == oddSum)
                res++;

            if (i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 1, 6, 4};
    auto res = obj.waysToMakeFair(v);
    print(res);
    v = {1, 1, 1};
    res = obj.waysToMakeFair(v);
    print(res);
    v = {1, 2, 3};
    res = obj.waysToMakeFair(v);
    print(res);
    return 0;
}

/*
Problem: Ways to Make a Fair Array
*/