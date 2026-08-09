#include "template.hpp"

/* Approach 1 (Memoization):
class Solution {
  private:
    int helper(int i, int M, vi &piles, vvi &memo) {
        int n = sz(piles);

        if (i >= n)
            return 0;

        if (memo[i][M] != -1)
            return memo[i][M];

        int mx = INT_MIN;
        int sum = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            sum += piles[i + X - 1];

            updateMax(mx, sum - helper(i + X, max(X, M), piles, memo));
        }

        return memo[i][M] = mx;
    }

  public:
    int stoneGameII(vector<int> &piles) {
        int n = sz(piles);
        vvi memo(n, vi(n + 1, -1));

        int total = accumulate(all(piles), 0);
        int diff = helper(0, 1, piles, memo);

        return (total + diff) / 2;
    }
};
*/

/* Approach 2 (Tabulation): */
class Solution {
  public:
    int stoneGameII(vector<int> &piles) {
        int n = sz(piles);
        vvi dp(n + 1, vi(n + 1, 0));

        revloop(i, n - 1, 0) {
            revloop(M, n, 1) {
                int mx = INT_MIN;
                int sum = 0;

                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    sum += piles[i + X - 1];

                    updateMax(mx, sum - dp[i + X][max(X, M)]);
                }

                dp[i][M] = mx;
            }
        }

        int total = accumulate(all(piles), 0);
        int diff = dp[0][1];

        return (total + diff) / 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 7, 9, 4, 4};
    auto res = obj.stoneGameII(v);
    print(res);
    v = {1, 2, 3, 4, 5, 100};
    res = obj.stoneGameII(v);
    print(res);
    return 0;
}

/*
Problem: Stone Game II
*/