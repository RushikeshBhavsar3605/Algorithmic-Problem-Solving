#include "template.hpp"

/* Approach (Bit Manipulation): */
class Solution {
  public:
    int longestSubsequence(vector<int> &nums) {
        int res = 0;
        bool flag = true;

        iterate(num, nums) {
            res ^= num;
            if (num != 0)
                flag = false;
        }

        if (flag)
            return 0;

        return (res == 0 ? nums.size() - 1 : nums.size());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3};
    auto res = obj.longestSubsequence(v);
    print(res);
    v = {2, 3, 4};
    res = obj.longestSubsequence(v);
    print(res);
    return 0;
}

/*
Problem: Longest Subsequence With Non-Zero Bitwise XOR
*/