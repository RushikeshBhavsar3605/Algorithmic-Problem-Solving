#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int countValidSubarrays(vector<int> &nums, int x) {
        int n = sz(nums);
        int cnt = 0;

        function<bool(ll)> isValid = [&](ll sum) -> bool {
            ll firstDigit = sum;
            while (firstDigit >= 10)
                firstDigit /= 10;

            return firstDigit == x && sum % 10 == x;
        };

        loop(i, 0, n) {
            ll sum = 0;
            loop(j, i, n) {
                sum += nums[j];
                if (isValid(sum))
                    cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 100, 1};
    auto res = obj.countValidSubarrays(v, 1);
    print(res);
    v = {1};
    res = obj.countValidSubarrays(v, 2);
    print(res);
    v = {1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000};
    res = obj.countValidSubarrays(v, 3);
    print(res);
    return 0;
}

/*
Problem: Valid Subarrays With Matching Sum Digits I
*/