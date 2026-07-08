#include "template.hpp"

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(all(nums));
        vvi res;

        int n = sz(nums);

        loop(i, 0, n - 2) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0)
                    left++;
                else if (sum > 0)
                    right--;
                else {
                    res.pb({nums[i], nums[left++], nums[right--]});

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {-1, 0, 1, 2, -1, -4};
    auto res = obj.threeSum(v);
    print(res);
    return 0;
}

/*
Problem: 3 sum
*/