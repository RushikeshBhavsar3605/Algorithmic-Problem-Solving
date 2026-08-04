#include "template.hpp"

/* Approach 1 (Recursion):
class Solution {
  private:
    int n;

    int solve(int id, vi &stones, vi &memo) {
        if (id >= n)
            return 0;

        if (memo[id] != INT_MIN)
            return memo[id];

        int diff = stones[id] - solve(id + 1, stones, memo);

        if (id + 1 < n)
            updateMax(diff, stones[id] + stones[id + 1] - solve(id + 2, stones, memo));

        if (id + 2 < n)
            updateMax(diff, stones[id] + stones[id + 1] + stones[id + 2] - solve(id + 3, stones, memo));

        return memo[id] = diff;
    }

  public:
    string stoneGameIII(vector<int> &stoneValue) {
        n = sz(stoneValue);

        vi memo(n, INT_MIN);
        int diff = solve(0, stoneValue, memo);

        if (diff < 0)
            return "Bob";
        else if (diff > 0)
            return "Alice";
        else
            return "Tie";
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    string stoneGameIII(vector<int> &stoneValue) {
        int n = sz(stoneValue);

        vi dp(n + 1, 0);

        revloop(id, n - 1, 0) {
            int diff = stoneValue[id] - dp[id + 1];

            if (id + 1 < n)
                updateMax(diff, stoneValue[id] + stoneValue[id + 1] - dp[id + 2]);

            if (id + 2 < n)
                updateMax(diff, stoneValue[id] + stoneValue[id + 1] + stoneValue[id + 2] - dp[id + 3]);

            dp[id] = diff;
        }

        if (dp[0] < 0)
            return "Bob";
        else if (dp[0] > 0)
            return "Alice";
        else
            return "Tie";
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    string stoneGameIII(vector<int> &stoneValue) {
        int n = sz(stoneValue);

        int a = 0, b = 0, c = 0;

        revloop(id, n - 1, 0) {
            int diff = stoneValue[id] - a;

            if (id + 1 < n)
                updateMax(diff, stoneValue[id] + stoneValue[id + 1] - b);

            if (id + 2 < n)
                updateMax(diff, stoneValue[id] + stoneValue[id + 1] + stoneValue[id + 2] - c);

            c = b;
            b = a;
            a = diff;
        }

        if (a < 0)
            return "Bob";
        else if (a > 0)
            return "Alice";
        else
            return "Tie";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 7};
    auto res = obj.stoneGameIII(v);
    print(res);
    v = {1, 2, 3, -9};
    res = obj.stoneGameIII(v);
    print(res);
    v = {1, 2, 3, 6};
    res = obj.stoneGameIII(v);
    print(res);
    return 0;
}

/*
Problem: Stone Game III
*/