#include "template.hpp"

class Solution {
  public:
    int maximumDifference(vector<int> &nums) {
        int maxi = -1, mini = INT_MAX;

        iterate(num, nums) {
            if (num != mini)
                updateMax(maxi, num - mini);

            updateMin(mini, num);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {7, 1, 5, 4};
    auto res = obj.maximumDifference(v);
    print(res);
    v = {9, 4, 3, 2};
    res = obj.maximumDifference(v);
    print(res);
    v = {1, 5, 2, 10};
    res = obj.maximumDifference(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Difference Between Increasing Elements
*/