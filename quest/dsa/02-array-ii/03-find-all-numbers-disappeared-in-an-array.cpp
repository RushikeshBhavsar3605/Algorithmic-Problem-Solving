#include "template.hpp"

/* Approach 1 (Hashing):
TC: O(n)
SC: O(n)

class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = sz(nums);
        vi freq(n + 1, 0);
        iterate(num, nums)
            freq[num]++;

        vi res;
        loop(i, 1, n + 1)
            if (freq[i] == 0)
                res.pb(i);

        return res;
    }
};
*/

/* Approach 2 (Hashing):
TC: O(n)
SC: O(1)
*/
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        iterate(num, nums) {
            int nxtIdx = abs(num) - 1;
            if (nums[nxtIdx] > 0)
                nums[nxtIdx] *= -1;
        }

        vi res;
        loop(i, 0, sz(nums))
            if (nums[i] > 0) res.pb(i + 1);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {4, 3, 2, 7, 8, 2, 3, 1};
    auto res = obj.findDisappearedNumbers(v);
    print(res);
    v = {1, 1};
    res = obj.findDisappearedNumbers(v);
    print(res);
    return 0;
}

/*
Problem: Find All Numbers Disappeared in an Array
*/