#include "template.hpp"

/* Approach 1 (Recursion):
class Solution {
  private:
    bool helper(int left, int right, int player1, int player2, bool turn, vi &nums) {
        if (left > right)
            return player1 >= player2;

        if (turn) {
            bool leftChoice = helper(left + 1, right, player1 + nums[left], player2, false, nums);

            bool rightChoice = helper(left, right - 1, player1 + nums[right], player2, false, nums);

            return leftChoice || rightChoice;
        } else {
            bool leftChoice = helper(left + 1, right, player1, player2 + nums[left], true, nums);

            bool rightChoice = helper(left, right - 1, player1, player2 + nums[right], true, nums);

            return leftChoice && rightChoice;
        }

        return false;
    }

  public:
    bool predictTheWinner(vector<int> &nums) {
        return helper(0, sz(nums) - 1, 0, 0, true, nums);
    }
};
*/

/* Approach 2 (Optimized Recursion):
class Solution {
  private:
    int helper(int left, int right, vi &nums) {
        if (left == right)
            return nums[left];

        int takeLeft = nums[left] - helper(left + 1, right, nums);
        int takeRight = nums[right] - helper(left, right - 1, nums);

        return max(takeLeft, takeRight);
    }

  public:
    bool predictTheWinner(vector<int> &nums) {
        return helper(0, sz(nums) - 1, nums) >= 0;
    }
};
*/

/* Approach 3 (Memoization):
class Solution {
  private:
    int helper(int left, int right, vi &nums, vvi &memo) {
        if (left == right)
            return nums[left];

        if (memo[left][right] != INT_MIN)
            return memo[left][right];

        int takeLeft = nums[left] - helper(left + 1, right, nums, memo);
        int takeRight = nums[right] - helper(left, right - 1, nums, memo);

        return memo[left][right] = max(takeLeft, takeRight);
    }

  public:
    bool predictTheWinner(vector<int> &nums) {
        int n = sz(nums);
        vvi memo(n, vi(n, INT_MIN));

        return helper(0, n - 1, nums, memo) >= 0;
    }
};
*/

/* Approach 4 (Tabulation):
class Solution {
  public:
    bool predictTheWinner(vector<int> &nums) {
        int n = sz(nums);
        vvi dp(n, vi(n, 0));

        loop(i, 0, n) dp[i][i] = nums[i];

        revloop(left, n - 2, 0) {
            loop(right, left + 1, n) {
                int takeLeft = nums[left] - dp[left + 1][right];
                int takeRight = nums[right] - dp[left][right - 1];

                dp[left][right] = max(takeLeft, takeRight);
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
*/

/* Approach 5 (Space Optimization): */
class Solution {
  public:
    bool predictTheWinner(vector<int> &nums) {
        int n = sz(nums);
        vi curr(n, 0);
        vi next(n, 0);

        loop(i, 0, n) next[i] = nums[i];

        revloop(left, n - 2, 0) {
            loop(right, left + 1, n) {
                int takeLeft = nums[left] - next[right];
                int takeRight = nums[right] - curr[right - 1];

                curr[right] = max(takeLeft, takeRight);
            }

            swap(curr, next);
        }

        return next[n - 1] >= 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 5, 2};
    auto res = obj.predictTheWinner(v);
    print(res);
    v = {1, 5, 233, 7};
    res = obj.predictTheWinner(v);
    print(res);
    return 0;
}

/*
Problem: Predict the Winner
*/