#include "template.hpp"

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int left = 0, right = sz(nums) - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }

        return nums[left];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 4, 5, 1, 2};
    auto res = obj.findMin(v);
    print(res);
    v = {4, 5, 6, 7, 0, 1, 2};
    res = obj.findMin(v);
    print(res);
    v = {11, 13, 15, 17};
    res = obj.findMin(v);
    print(res);
    return 0;
}

/*
Problem: Find Minimum in Rotated Sorted Array
*/