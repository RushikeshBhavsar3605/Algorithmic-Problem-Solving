#include "template.hpp"

/* Approach 1 (Brute Force) (TLE):
class Solution {
  private:
    int n, l, r;
    int helper(int prev, int idx, bool isNextLarger) {
        if (idx == n)
            return 1;

        int cnt = 0;
        if (isNextLarger) {
            loop(i, prev + 1, r + 1) {
                cnt += helper(i, idx + 1, false);
            }
        } else {
            loop(i, l, prev) {
                cnt += helper(i, idx + 1, true);
            }
        }

        return cnt;
    }

  public:
    int zigZagArrays(int n, int l, int r) {
        this->n = n;
        this->l = l;
        this->r = r;

        int cnt = 0;
        loop(i, l, r + 1) {
            cnt += helper(i, 1, true);
            cnt += helper(i, 1, false);
        }

        return cnt;
    }
};
*/

/* Approach 2 (DP Optimization) (TLE):
class Solution {
  public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;

        nvec_t<ll, 3> dp(n, vvl(r + 1, vl(2, 0)));
        loop(prev, l, r + 1) {
            dp[n - 1][prev][0] = 1;
            dp[n - 1][prev][1] = 1;
        }

        revloop(idx, n - 2, 0) {
            loop(prev, l, r + 1) {
                loop(x, prev + 1, r + 1)
                    dp[idx][prev][1] = (dp[idx][prev][1] + dp[idx + 1][x][0]) % MOD;

                loop(x, l, prev)
                    dp[idx][prev][0] = (dp[idx][prev][0] + dp[idx + 1][x][1]) % MOD;
            }
        }

        ll cnt = 0;
        loop(x, l, r + 1) {
            cnt = (cnt + dp[0][x][0]) % MOD;
            cnt = (cnt + dp[0][x][1]) % MOD;
        }

        return cnt;
    }
};
*/

/* Approach 3 (Optimal DP): */
class Solution {
  public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        vl up(m, 1), down(m, 1);

        loop(i, 2, n + 1) {
            vl prefixDown(m);
            loop(j, 0, m) {
                prefixDown[j] = down[j];
                if (j != 0)
                    prefixDown[j] = (prefixDown[j] + prefixDown[j - 1]) % MOD;
            }

            vl suffixUp(m);
            revloop(j, m - 1, 0) {
                suffixUp[j] = up[j];
                if (j != m - 1)
                    suffixUp[j] = (suffixUp[j] + suffixUp[j + 1]) % MOD;
            }

            loop(j, 0, m) {
                up[j] = (j > 0) ? prefixDown[j - 1] : 0;
                down[j] = (j < m - 1) ? suffixUp[j + 1] : 0;
            }
        }

        ll res = 0;
        loop(i, 0, m)
            res = (res + up[i] + down[i]) % MOD;

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.zigZagArrays(3, 4, 5);
    print(res);
    res = obj.zigZagArrays(3, 1, 3);
    print(res);
    return 0;
}

/*
Problem: Number of ZigZag Arrays I
*/