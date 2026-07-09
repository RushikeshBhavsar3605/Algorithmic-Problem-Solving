#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vi nums;
        int n = sz(nums1), m = sz(nums2);
        int it1 = 0, it2 = 0;

        while (it1 < n && it2 < m)
            if (nums1[it1] < nums2[it2])
                nums.pb(nums1[it1++]);
            else
                nums.pb(nums2[it2++]);

        while (it1 < n)
            nums.pb(nums1[it1++]);

        while (it2 < m)
            nums.pb(nums2[it2++]);

        int mid = sz(nums) >> 1;

        if (sz(nums) & 1)
            return nums[mid];

        return (nums[mid - 1] + nums[mid]) / 2.0;
    }
};
*/

/* Approach 2 (Binary Search): */
class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        if (sz(nums1) > sz(nums2))
            return findMedianSortedArrays(nums2, nums1);

        int n = sz(nums1), m = sz(nums2);
        int left = 0, right = n;

        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            if (max(l1, l2) <= min(r1, r2)) {
                if ((n + m) & 1)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2)
                right = cut1 - 1;
            else
                left = cut1 + 1;
        }

        return 0.0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 3}, v2 = {2};
    auto res = obj.findMedianSortedArrays(v1, v2);
    print(res);
    v1 = {1, 2}, v2 = {3, 4};
    res = obj.findMedianSortedArrays(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Median of Two Sorted Arrays
*/