#include "template.hpp"

/* Approach 1 (Memoization):
class Solution {
  private:
    int helper(int n, vi &memo) {
        if (n == 0)
            return false;

        if (memo[n] != -1)
            return memo[n];

        for (int i = 1; i * i <= n; i++) {
            int square = i * i;

            if (!helper(n - square, memo))
                return memo[n] = true;
        }

        return memo[n] = false;
    }

  public:
    bool winnerSquareGame(int n) {
        vi memo(n + 1, -1);
        return helper(n, memo);
    }
};
*/

/* Approach 2 (Tabulation): */
class Solution {
  public:
    bool winnerSquareGame(int n) {
        vi dp(n + 1, 0);

        loop(i, 1, n + 1) {
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;

                if (!dp[i - square]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.winnerSquareGame(1);
    print(res);
    res = obj.winnerSquareGame(2);
    print(res);
    res = obj.winnerSquareGame(4);
    print(res);
    return 0;
}

/*
Problem: Stone Game IV
*/