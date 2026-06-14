#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vi res;
        loop(i, 0, n) {
            res.pb(nums[i]);
            res.pb(nums[i + n]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 5, 1, 3, 4, 7};
    auto res = obj.shuffle(v, 3);
    print(res);
    v = {1, 2, 3, 4, 4, 3, 2, 1};
    res = obj.shuffle(v, 4);
    print(res);
    v = {1, 1, 2, 2};
    res = obj.shuffle(v, 2);
    print(res);
    return 0;
}

/*
Problem: Shuffle the Array
*/