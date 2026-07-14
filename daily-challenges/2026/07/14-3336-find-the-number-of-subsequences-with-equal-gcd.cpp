#include "template.hpp"

/* Approach 1 (Memoization):
class Solution {
  private:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    int helper(int idx, int seq1, int seq2, vi &nums, nvec_t<int, 3> &memo) {
        if (idx == sz(nums)) {
            if (seq1 != seq2 || (seq1 == 0 && seq2 == 0))
                return 0;

            return 1;
        }

        if (memo[idx][seq1][seq2] != -1)
            return memo[idx][seq1][seq2];

        ll take1 = helper(idx + 1, gcd(nums[idx], seq1), seq2, nums, memo) % MOD;
        ll take2 = helper(idx + 1, seq1, gcd(nums[idx], seq2), nums, memo) % MOD;
        ll skip = helper(idx + 1, seq1, seq2, nums, memo) % MOD;

        return memo[idx][seq1][seq2] = (take1 + take2 + skip) % MOD;
    }

  public:
    int subsequencePairCount(vector<int> &nums) {
        int n = sz(nums);
        int maxEle = *max_element(all(nums));

        nvec_t<int, 3> memo(n, vvi(maxEle + 1, vi(maxEle + 1, -1)));

        return helper(0, 0, 0, nums, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  private:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

  public:
    int subsequencePairCount(vector<int> &nums) {
        int n = sz(nums);
        int maxEle = *max_element(all(nums));

        nvec_t<int, 3> dp(n + 1, vvi(maxEle + 1, vi(maxEle + 1, 0)));
        loop(i, 1, maxEle + 1)
            dp[n][i][i] = 1;

        revloop(idx, n - 1, 0) {
            revloop(seq1, maxEle, 0) {
                revloop(seq2, maxEle, 0) {
                    ll take1 = dp[idx + 1][gcd(nums[idx], seq1)][seq2];
                    ll take2 = dp[idx + 1][seq1][gcd(nums[idx], seq2)];
                    ll skip = dp[idx + 1][seq1][seq2];

                    dp[idx][seq1][seq2] = (take1 + take2 + skip) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  private:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

  public:
    int subsequencePairCount(vector<int> &nums) {
        int n = sz(nums);
        int maxEle = *max_element(all(nums));

        vvi curr(maxEle + 1, vi(maxEle + 1, 0));
        vvi next(maxEle + 1, vi(maxEle + 1, 0));
        loop(i, 1, maxEle + 1)
            next[i][i] = 1;

        revloop(idx, n - 1, 0) {
            revloop(seq1, maxEle, 0) {
                revloop(seq2, maxEle, 0) {
                    ll take1 = next[gcd(nums[idx], seq1)][seq2];
                    ll take2 = next[seq1][gcd(nums[idx], seq2)];
                    ll skip = next[seq1][seq2];

                    curr[seq1][seq2] = (take1 + take2 + skip) % MOD;
                }
            }

            swap(curr, next);
        }

        return next[0][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4};
    auto res = obj.subsequencePairCount(v);
    print(res);
    v = {10, 20, 30};
    res = obj.subsequencePairCount(v);
    print(res);
    v = {1, 1, 1, 1};
    res = obj.subsequencePairCount(v);
    print(res);
    return 0;
}

/*
Problem: Find the Number of Subsequences With Equal GCD
*/