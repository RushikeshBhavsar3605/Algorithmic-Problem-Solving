#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    vector<int> resultArray(vector<int> &nums) {
        vi arr1 = {nums[0]};
        vi arr2 = {nums[1]};

        loop(i, 2, nums.size())
            if (arr1.back() > arr2.back())
                arr1.pb(nums[i]);
            else
                arr2.pb(nums[i]);

        arr1.insert(end(arr1), all(arr2));
        return arr1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 1, 3};
    auto res = obj.resultArray(v);
    print(res);
    v = {5, 4, 3, 8};
    res = obj.resultArray(v);
    print(res);
    return 0;
}

/*
Problem: Distribute Elements Into Two Arrays I
*/