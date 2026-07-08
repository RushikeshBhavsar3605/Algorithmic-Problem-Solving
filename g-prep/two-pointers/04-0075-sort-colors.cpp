#include "template.hpp"

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int low = 0;
        int mid = 0;
        int high = sz(nums) - 1;

        while (mid <= high) {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 0, 2, 1, 1, 0};
    obj.sortColors(v);
    print(v);
    v = {2, 0, 1};
    obj.sortColors(v);
    print(v);
    return 0;
}

/*
Problem: Sort Colors
*/