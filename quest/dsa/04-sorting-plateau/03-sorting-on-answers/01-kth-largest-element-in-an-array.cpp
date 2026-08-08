#include "template.hpp"

/* Approach (Quick Select): */
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int target = k - 1;
        int left = 0, right = sz(nums) - 1;

        while (left <= right) {
            int pivot = nums[right];
            int store = left;

            loop(i, left, right)
                if (nums[i] > pivot)
                    swap(nums[store++], nums[i]);

            swap(nums[store], nums[right]);

            if (store == target)
                return nums[store];
            else if (store < target)
                left = store + 1;
            else
                right = store - 1;
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 2, 1, 5, 6, 4};
    auto res = obj.findKthLargest(v, 2);
    print(res);
    v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    res = obj.findKthLargest(v, 4);
    print(res);
    return 0;
}

/*
Problem: Kth Largest Element in an Array
*/