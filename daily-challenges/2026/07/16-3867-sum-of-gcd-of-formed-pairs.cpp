#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    long long gcdSum(vector<int> &nums) {
        int n = sz(nums);
        vi prefixGcd;

        int mx = 0;
        loop(i, 0, n) {
            updateMax(mx, nums[i]);
            prefixGcd.pb(gcd(nums[i], mx));
        }

        sort(all(prefixGcd));

        ll sum = 0;
        loop(i, 0, n >> 1)
            sum += gcd(prefixGcd[i], prefixGcd[n - i - 1]);

        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 6, 4};
    auto res = obj.gcdSum(v);
    print(res);
    v = {3, 6, 2, 8};
    res = obj.gcdSum(v);
    print(res);
    return 0;
}

/*
Problem: Sum of GCD of Formed Pairs
*/