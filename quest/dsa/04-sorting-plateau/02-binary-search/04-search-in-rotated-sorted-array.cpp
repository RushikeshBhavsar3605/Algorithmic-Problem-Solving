#include "template.hpp"

/* Approach (Binary Search): */
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = sz(nums) - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] <= target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {4, 5, 6, 7, 0, 1, 2};
    auto res = obj.search(v, 0);
    print(res);
    v = {4, 5, 6, 7, 0, 1, 2};
    res = obj.search(v, 3);
    print(res);
    v = {1};
    res = obj.search(v, 0);
    print(res);
    return 0;
}

/*
Problem: Search in Rotated Sorted Array
*/