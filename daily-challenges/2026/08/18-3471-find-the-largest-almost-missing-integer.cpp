#include "template.hpp"

/* Approach (Hashing + Sliding Window): */
class Solution {
  public:
    int largestInteger(vector<int> &nums, int k) {
        int n = sz(nums);
        umap<int, int> mp;

        loop(start, 0, n - k + 1) {
            uset<int> seen;
            loop(i, start, start + k)
                seen.insert(nums[i]);

            iterate(it, seen) mp[it]++;
        }

        int res = -1;
        iterate(it, mp)
            if (it.ss == 1)
                updateMax(res, it.ff);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vector<int> v = {3, 9, 2, 1, 7};
    auto res = obj.largestInteger(v, 3);
    print(res);
    v = {3, 9, 7, 2, 1, 7};
    res = obj.largestInteger(v, 4);
    print(res);
    v = {0, 0};
    res = obj.largestInteger(v, 1);
    print(res);
    return 0;
}

/*
Problem: Find the Largest Almost Missing Integer
*/