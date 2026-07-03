#include "template.hpp"

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        int i = sz(nums) - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            int j = sz(nums) - 1;
            while (nums[i] >= nums[j])
                j--;

            swap(nums[i], nums[j]);
        }

        reverse(begin(nums) + i + 1, end(nums));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3};
    obj.nextPermutation(v);
    print(v);
    v = {3, 2, 1};
    obj.nextPermutation(v);
    print(v);
    v = {1, 1, 5};
    obj.nextPermutation(v);
    print(v);
    return 0;
}

/*
Problem: Next Permutation
*/