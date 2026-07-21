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
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {-1, 0, 3, 5, 9, 12};
    auto res = obj.search(v, 9);
    print(res);
    v = {-1, 0, 3, 5, 9, 12};
    res = obj.search(v, 2);
    print(res);
    return 0;
}

/*
Problem: Binary Search
*/