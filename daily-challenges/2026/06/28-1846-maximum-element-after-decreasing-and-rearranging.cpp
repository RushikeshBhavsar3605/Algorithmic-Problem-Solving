#include "template.hpp"

/* Approach (Sorting): */
class Solution {
  public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        sort(all(arr));
        int ele = 1;

        loop(i, 1, sz(arr)) {
            int currEle = ele + 1;

            ele = min(currEle, arr[i]);
        }

        return ele;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 2, 1, 2, 1};
    auto res = obj.maximumElementAfterDecrementingAndRearranging(v);
    print(res);
    v = {100, 1, 1000};
    res = obj.maximumElementAfterDecrementingAndRearranging(v);
    print(res);
    v = {1, 2, 3, 4, 5};
    res = obj.maximumElementAfterDecrementingAndRearranging(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Element After Decreasing and Rearranging
*/