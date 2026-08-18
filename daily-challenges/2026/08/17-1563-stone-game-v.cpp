#include "template.hpp"

/* Approach 1 (Recursion):
class Solution {
  private:
    int helper(vi &prefix, int st, int en) {
        if (st >= en)
            return 0;

        int score = 0;
        loop(mid, st + 1, en + 1) {
            int leftSum = prefix[mid] - prefix[st];
            int rightSum = prefix[en + 1] - prefix[mid];

            if (leftSum < rightSum)
                updateMax(score, leftSum + helper(prefix, st, mid - 1));
            else if (leftSum > rightSum)
                updateMax(score, rightSum + helper(prefix, mid, en));
            else
                updateMax(score, max(
                    leftSum + helper(prefix, st, mid - 1),
                    rightSum + helper(prefix, mid, en)
                ));
        }

        return score;
    }

  public:
    int stoneGameV(vector<int> &stoneValue) {
        int n = sz(stoneValue);
        vi prefix(n + 1, 0);
        loop(i, 0, n)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        return helper(prefix, 0, n - 1);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int helper(vi &prefix, int st, int en, vvi &memo) {
        if (st >= en)
            return 0;

        if (memo[st][en] != -1)
            return memo[st][en];

        int score = 0;
        loop(mid, st + 1, en + 1) {
            int leftSum = prefix[mid] - prefix[st];
            int rightSum = prefix[en + 1] - prefix[mid];

            if (leftSum < rightSum)
                updateMax(score, leftSum + helper(prefix, st, mid - 1, memo));
            else if (leftSum > rightSum)
                updateMax(score, rightSum + helper(prefix, mid, en, memo));
            else
                updateMax(score, max(
                    leftSum + helper(prefix, st, mid - 1, memo),
                    rightSum + helper(prefix, mid, en, memo)
                ));
        }

        return memo[st][en] = score;
    }

  public:
    int stoneGameV(vector<int> &stoneValue) {
        int n = sz(stoneValue);
        vi prefix(n + 1, 0);
        loop(i, 0, n)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vvi memo(n, vi(n, -1));
        return helper(prefix, 0, n - 1, memo);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    int stoneGameV(vector<int> &stoneValue) {
        int n = sz(stoneValue);
        vvi dp(n, vi(n, 0));

        vi prefix(n + 1, 0);
        loop(i, 0, n)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        revloop(st, n - 1, 0) {
            loop(en, st + 1, n) {
                int score = 0;

                loop(mid, st + 1, en + 1) {
                    int leftSum = prefix[mid] - prefix[st];
                    int rightSum = prefix[en + 1] - prefix[mid];

                    if (leftSum < rightSum)
                        updateMax(score, leftSum + dp[st][mid - 1]);
                    else if (leftSum > rightSum)
                        updateMax(score, rightSum + dp[mid][en]);
                    else
                        updateMax(score, max(
                            leftSum + dp[st][mid - 1],
                            rightSum + dp[mid][en]
                        ));
                }

                dp[st][en] = score;
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {6, 2, 3, 4, 5, 5};
    auto res = obj.stoneGameV(v);
    print(res);
    v = {7, 7, 7, 7, 7, 7, 7};
    res = obj.stoneGameV(v);
    print(res);
    v = {4};
    res = obj.stoneGameV(v);
    print(res);
    return 0;
}

/*
Problem: Stone Game V
*/