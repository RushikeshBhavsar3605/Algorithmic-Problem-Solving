#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = sz(nums);
        vi diff(n, 0);

        iterate(q, queries) {
            diff[q[0]] += 1;
            if (q[1] + 1 < n)
                diff[q[1] + 1] -= 1;
        }

        int cover = 0;
        loop(i, 0, n) {
            cover += diff[i];
            if (cover < nums[i])
                return false;
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 0, 1};
    vvi v2 = {{0, 2}};
    auto res = obj.isZeroArray(v1, v2);
    print(res);
    v1 = {4, 3, 2, 1};
    v2 = {{1, 3}, {0, 2}};
    res = obj.isZeroArray(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Zero Array Transformation I
*/