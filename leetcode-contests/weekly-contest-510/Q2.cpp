#include "template.hpp"

/* Approach (Math):
Note: In the need calculation it calculates it's all need without considering existing k value, so if there's no remainder then we decrease need value by 1.
k = 5;
need = 10 / 5 = 2
But here we only need 1 extra so we decrease k value.
*/
class Solution {
  public:
    int minimumCost(vector<int> &nums, int k) {
        const int MOD = 1e9 + 7;
        ll sum = accumulate(all(nums), 0LL);

        ll need = sum / k;
        if (sum % k == 0)
            need--;

        ll a = need % MOD;
        ll b = (need + 1) % MOD;
        ll res = ((a * b) >> 1) % MOD;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4};
    auto res = obj.minimumCost(v, 4);
    print(res);
    v = {1, 1, 7, 14};
    res = obj.minimumCost(v, 4);
    print(res);
    v = {1, 2, 3, 4};
    res = obj.minimumCost(v, 10);
    print(res);
    return 0;
}

/*
Problem: Minimum Total Cost to Process All Elements
*/