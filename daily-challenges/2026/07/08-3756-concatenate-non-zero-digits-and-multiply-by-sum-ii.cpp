#include "template.hpp"

/* Approach (Prefix): */
class Solution {
  public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
        int n = sz(s);
        int MOD = 1e9 + 7;

        vi prefCnt(n + 1), prefSum(n + 1);
        vector<ll> prefNum(n + 1), pow10(n + 1, 1);

        loop(i, 1, n + 1)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        loop(i, 0, n) {
            int d = s[i] - '0';

            prefCnt[i + 1] = prefCnt[i];
            prefSum[i + 1] = prefSum[i];
            prefNum[i + 1] = prefNum[i];

            if (d) {
                prefCnt[i + 1]++;
                prefSum[i + 1] += d;
                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }

        vi res;

        iterate(q, queries) {
            int l = q[0], r = q[1];

            int cnt = prefCnt[r + 1] - prefCnt[l];
            int sum = prefSum[r + 1] - prefSum[l];

            ll x = (prefNum[r + 1] - prefNum[l] * pow10[cnt] % MOD + MOD) % MOD;

            res.pb(x * sum % MOD);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{0, 7}, {1, 3}, {4, 6}};
    auto res = obj.sumAndMultiply("10203004", v);
    print(res);
    return 0;
}

/*
Problem: Concatenate Non-Zero Digits and Multiply by Sum II
*/