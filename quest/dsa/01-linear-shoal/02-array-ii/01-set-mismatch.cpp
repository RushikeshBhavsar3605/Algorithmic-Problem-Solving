#include "template.hpp"

/* Approach 1 (Hashing):
TC: O(n)
SC: O(n)

class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = sz(nums);
        vi mp(n + 1, 0);
        iterate(num, nums)
            mp[num]++;

        int missing = -1;
        int duplicate = -1;
        loop(i, 1, n + 1) {
            if (mp[i] == 0)
                missing = i;
            if (mp[i] == 2)
                duplicate = i;
        }

        return {duplicate, missing};
    }
};
*/

/* Approach 2 (Optimal):
TC: O(n)
SC: O(1)
*/
class Solution {
  public:
    vector<int> findErrorNums(vector<int> &nums) {
        int duplicate = -1;
        loop(i, 0, sz(nums)) {
            int nxtIdx = abs(nums[i]) - 1;

            if (nums[nxtIdx] < 0)
                duplicate = abs(nums[i]);
            else
                nums[nxtIdx] *= -1;
        }

        int missing = -1;
        loop(i, 0, sz(nums))
            if (nums[i] >= 0) {
                missing = i + 1;
                break;
            }

        return {duplicate, missing};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 2, 4};
    auto res = obj.findErrorNums(v);
    print(res);
    v = {2, 2};
    res = obj.findErrorNums(v);
    print(res);
    return 0;
}

/*
Problem: Set Mismatch
*/