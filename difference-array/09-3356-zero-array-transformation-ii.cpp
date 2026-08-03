#include "template.hpp"

/* Approach (Binary Search on Answers + Difference Array): */
class Solution {
  private:
    bool check(vi &nums, vvi &queries, int k) {
        int n = sz(nums);
        vi diff(n + 1, 0);

        loop(i, 0, k) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val;
            diff[r + 1] -= val;
        }

        int cover = 0;
        loop(i, 0, n) {
            cover += diff[i];
            if (cover < nums[i])
                return false;
        }

        return true;
    }

  public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
        int n = sz(queries);

        if (!check(nums, queries, n))
            return -1;

        int low = 0, high = n;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (check(nums, queries, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {2, 0, 2};
    vvi v2 = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    auto res = obj.minZeroArray(v1, v2);
    print(res);
    v1 = {4, 3, 2, 1};
    v2 = {{1, 3, 2}, {0, 2, 1}};
    res = obj.minZeroArray(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Zero Array Transformation II
*/