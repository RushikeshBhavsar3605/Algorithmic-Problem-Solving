#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int maxi = 0;
        int cnt = 0;

        loop(i, 0, sz(nums)) {
            if (nums[i] == 1)
                cnt++;
            else
                cnt = 0;

            updateMax(maxi, cnt);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 1, 0, 1, 1, 1};
    auto res = obj.findMaxConsecutiveOnes(v);
    print(res);
    v = {1, 0, 1, 1, 0, 1};
    res = obj.findMaxConsecutiveOnes(v);
    print(res);
    return 0;
}

/*
Problem: Max Consecutive Ones
*/