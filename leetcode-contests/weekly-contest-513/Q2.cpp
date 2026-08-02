#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int countRatioSubarrays(vector<int> &nums, int a, int b) {
        int n = sz(nums);
        int res = 0;

        loop(i, 0, n) {
            int x = 0;
            int y = 0;

            loop(j, i, n) {
                if (nums[j] & 1)
                    y++;
                else
                    x++;

                if (y > 0 && 1LL * x * b <= 1LL * y * a)
                    res++;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 1, 2};
    auto res = obj.countRatioSubarrays(v, 3, 2);
    print(res);
    v = {2, 2, 1};
    res = obj.countRatioSubarrays(v, 2, 1);
    print(res);
    v = {2, 2, 2};
    res = obj.countRatioSubarrays(v, 1, 1);
    print(res);
    return 0;
}

/*
Problem: Count Subarrays With Even Odd Ratio I
*/