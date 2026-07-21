#include "template.hpp"

/* Approach (Binary Search): */
class Solution {
  public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0, right = sz(arr) - 1;

        while (left < right) {
            int mid = left + ((right - left) >> 1);

            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 4, 5, 1};
    auto res = obj.peakIndexInMountainArray(v);
    print(res);
    v = {0, 2, 1, 0};
    res = obj.peakIndexInMountainArray(v);
    print(res);
    v = {0, 10, 5, 2};
    res = obj.peakIndexInMountainArray(v);
    print(res);
    return 0;
}

/*
Problem: Peak Index in a Mountain Array
*/