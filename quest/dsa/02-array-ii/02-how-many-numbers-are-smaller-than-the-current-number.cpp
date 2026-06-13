#include "template.hpp"

/* Approach 1 (Naive):
TC: O(n * n)
SC: O(1)

class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        int n = sz(nums);
        vi res(n);

        loop(i, 0, n) {
            int cnt = 0;
            loop(j, 0, n) {
                if (j == i)
                    continue;

                if (nums[j] < nums[i])
                    cnt++;
            }

            res[i] = cnt;
        }

        return res;
    }
};
*/

/* Approach 2 (Sorting):
TC: O(n log n)
SC: O(n)

class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        int n = sz(nums);
        umap<int, int> mp;

        vi sorted = nums;
        sort(all(sorted));

        loop(i, 0, n)
            if (!mp.count(sorted[i]))
                mp[sorted[i]] = i;

        vi res(n);
        loop(i, 0, n)
            res[i] = mp[nums[i]];

        return res;
    }
};
*/

/* Approach 3 (Hashing):
TC: O(n)
SC: O(n)
*/
class Solution {
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        int maxEle = *max_element(all(nums));
        vi freq(maxEle + 1, 0);

        iterate(num, nums)
            freq[num]++;

        loop(i, 1, maxEle + 1)
            freq[i] += freq[i - 1];

        vi res;
        iterate(num, nums)
            if (num == 0)
                res.pb(0);
            else
                res.pb(freq[num - 1]);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {8, 1, 2, 2, 3};
    auto res = obj.smallerNumbersThanCurrent(v);
    print(res);
    v = {6, 5, 4, 8};
    res = obj.smallerNumbersThanCurrent(v);
    print(res);
    return 0;
}

/*
Problem: How Many Numbers Are Smaller Than the Current Number
*/