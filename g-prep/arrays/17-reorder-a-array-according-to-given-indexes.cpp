#include "template.hpp"

class Solution {
  public:
    void reorderArray(vi &nums, vi &index) {
        int n = sz(nums);

        loop(i, 0, n) {
            while (index[i] != i) {
                swap(nums[i], nums[index[i]]);
                swap(index[i], index[index[i]]);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi nums = {24, 56, 74, -23, 87, 91};
    vi indexes = {1, 2, 3, 0, 4, 5};
    obj.reorderArray(nums, indexes);
    print(nums);
    nums = {10, 11, 12};
    indexes = {1, 0, 2};
    obj.reorderArray(nums, indexes);
    print(nums);
    return 0;
}

/*
Problem: Array rearrangement by given index
*/