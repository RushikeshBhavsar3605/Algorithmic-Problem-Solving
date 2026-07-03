#include "template.hpp"

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        k %= sz(nums);

        reverse(begin(nums), end(nums) - k);
        reverse(end(nums) - k, end(nums));
        reverse(begin(nums), end(nums));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4, 5, 6, 7};
    obj.rotate(v, 3);
    print(v);
    v = {-1, -100, 3, 99};
    obj.rotate(v, 2);
    print(v);
    return 0;
}

/*
Problem: Rotate Array
*/