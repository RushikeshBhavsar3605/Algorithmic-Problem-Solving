#include "template.hpp"

/* Approach (Two Pointers): */
class Solution {
  public:
    bool judgeSquareSum(int c) {
        ll left = 0;
        ll right = sqrt(c);

        while (left <= right) {
            ll sum = left * left + right * right;

            if (sum == c)
                return true;
            else if (sum < c)
                left++;
            else
                right--;
        }

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.judgeSquareSum(5);
    print(res);
    res = obj.judgeSquareSum(3);
    print(res);
    return 0;
}

/*
Problem: Sum of Square Numbers
*/