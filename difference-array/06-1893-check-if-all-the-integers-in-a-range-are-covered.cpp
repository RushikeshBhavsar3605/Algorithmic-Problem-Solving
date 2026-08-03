#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        vi diff(51, 0);

        iterate(range, ranges) {
            int l = range[0], r = range[1] + 1;

            diff[l] += 1;
            if (r < 51)
                diff[r] -= 1;
        }

        loop(i, 1, 51)
            diff[i] += diff[i - 1];

        loop(i, left, right + 1)
            if (diff[i] == 0)
                return false;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 2}, {3, 4}, {5, 6}};
    auto res = obj.isCovered(v, 2, 5);
    print(res);
    v = {{1, 10}, {10, 20}};
    res = obj.isCovered(v, 21, 21);
    print(res);
    return 0;
}

/*
Problem: Check if All the Integers in a Range Are Covered
*/