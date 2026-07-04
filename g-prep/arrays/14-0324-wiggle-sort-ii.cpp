#include "template.hpp"

class Solution {
  public:
    void wiggleSort(vector<int> &nums) {
        vi sorted = nums;
        sort(all(sorted));

        int n = sz(nums);
        int j = (n - 1) >> 1;
        int k = n - 1;

        loop(i, 0, n) {
            if (i & 1)
                nums[i] = sorted[k--];
            else
                nums[i] = sorted[j--];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 5, 1, 1, 6, 4};
    obj.wiggleSort(v);
    print(v);
    v = {1, 3, 2, 2, 3, 1};
    obj.wiggleSort(v);
    print(v);
    v = {4, 5, 5, 6};
    obj.wiggleSort(v);
    print(v);
    return 0;
}

/*
Problem: Wiggle Sort II
*/