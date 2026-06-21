#include "template.hpp"

/* Approach (Greedy): */
class Solution {
  public:
    int maxBuilding(int n, vector<vector<int>> &nums) {
        sort(all(nums));
        int len = sz(nums);

        if (len == 0)
            return n - 1;

        pii prev = {1, 0};

        loop(i, 0, len) {
            int diff = nums[i][0] - prev.ff;
            updateMin(nums[i][1], prev.ss + diff);

            prev = {nums[i][0], nums[i][1]};
        }

        prev = {n, INT_MAX};
        revloop(i, len - 1, 0) {
            int diff = prev.ff - nums[i][0];
            if (prev.ss != INT_MAX)
                updateMin(nums[i][1], prev.ss + diff);

            prev = {nums[i][0], nums[i][1]};
        }

        int maxi = 0;
        prev = {1, 0};

        loop(i, 0, len) {
            int diff = nums[i][0] - prev.ff;
            int peak = max(prev.ss, nums[i][1]) + (diff - abs(prev.ss - nums[i][1])) / 2;

            updateMax(maxi, peak);

            prev = {nums[i][0], nums[i][1]};
        }

        int diff = n - prev.ff;
        int peak = prev.ss + diff;

        updateMax(maxi, peak);

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{2, 1}, {4, 1}};
    auto res = obj.maxBuilding(5, v);
    print(res);
    v = {};
    res = obj.maxBuilding(6, v);
    print(res);
    v = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    res = obj.maxBuilding(10, v);
    print(res);
    v = {{8, 5}, {9, 0}, {6, 2}, {4, 0}, {3, 2}, {10, 0}, {5, 3}, {7, 3}, {2, 4}};
    res = obj.maxBuilding(10, v);
    print(res);
    v = {{2, 3}};
    res = obj.maxBuilding(10, v);
    print(res);
    return 0;
}

/*
Problem: Maximum Building Height
*/