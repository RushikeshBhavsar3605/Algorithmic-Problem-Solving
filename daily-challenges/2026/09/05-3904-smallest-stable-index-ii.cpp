#include "template.hpp"

/* Approach (Prefix + Suffix): */
class Solution {
  public:
    int firstStableIndex(vector<int> &nums, int k) {
        int n = sz(nums);
        vi suffix(n, 0);

        int mn = INT_MAX;
        revloop(i, n - 1, 0) {
            updateMin(mn, nums[i]);
            suffix[i] = mn;
        }

        int mx = 0;
        loop(i, 0, n) {
            updateMax(mx, nums[i]);
            int score = mx - suffix[i];
            if (score <= k)
                return i;
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {5, 0, 1, 4};
    auto res = obj.firstStableIndex(v, 3);
    print(res);
    v = {3, 2, 1};
    res = obj.firstStableIndex(v, 1);
    print(res);
    v = {0};
    res = obj.firstStableIndex(v, 0);
    print(res);
    return 0;
}

/*
Problem: Smallest Stable Index II
*/