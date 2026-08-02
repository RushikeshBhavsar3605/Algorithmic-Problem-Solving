#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    long long maxPairStrength(vector<int> &nums) {
        int n = sz(nums);
        ll res = 0;

        loop(i, 0, n) {
            loop(j, 0, n) {
                if (i == j)
                    continue;

                ll g = __gcd(nums[i], nums[j]);
                ll val = (1LL * nums[i] * nums[j]) / (g * g);

                updateMax(res, val);
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 3, 5};
    auto res = obj.maxPairStrength(v);
    print(res);
    v = {4, 6, 8};
    res = obj.maxPairStrength(v);
    print(res);
    v = {3, 3};
    res = obj.maxPairStrength(v);
    print(res);
    return 0;
}

/*
Problem: Maximize Pair Strength Using GCD
*/