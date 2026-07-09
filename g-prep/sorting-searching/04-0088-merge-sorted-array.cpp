#include "template.hpp"

/* Approach (Two Pointers): */
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];

        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 2, 3, 0, 0, 0}, v2 = {2, 5, 6};
    obj.merge(v1, 3, v2, 3);
    print(v1);
    return 0;
}

/*
Problem: Merge Sorted Array
*/