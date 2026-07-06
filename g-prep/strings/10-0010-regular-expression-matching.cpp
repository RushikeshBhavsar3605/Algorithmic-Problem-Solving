#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  private:
    bool dfs(int it1, int it2, const string &s, const string &p) {
        if (it2 == sz(p))
            return it1 == sz(s);

        bool match = it1 < sz(s) &&
                        (s[it1] == p[it2] || p[it2] == '.');

        if (it2 + 1 < sz(p) && p[it2 + 1] == '*')
            return dfs(it1, it2 + 2, s, p) ||
                    (match && dfs(it1 + 1, it2, s, p));

        return match && dfs(it1 + 1, it2 + 1, s, p);
    }

  public:
    bool isMatch(string s, string p) {
        return dfs(0, 0, s, p);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    bool dfs(int it1, int it2, const string &s, const string &p, vvi &memo) {
        if (memo[it1][it2] != -1)
            return memo[it1][it2];

        if (it2 == sz(p))
            return memo[it1][it2] = (it1 == sz(s));

        bool match = it1 < sz(s) &&
                        (s[it1] == p[it2] || p[it2] == '.');

        if (it2 + 1 < sz(p) && p[it2 + 1] == '*')
            return memo[it1][it2] =
                        dfs(it1, it2 + 2, s, p, memo) ||
                        (match && dfs(it1 + 1, it2, s, p, memo));

        return memo[it1][it2] = match && dfs(it1 + 1, it2 + 1, s, p, memo);
    }

  public:
    bool isMatch(string s, string p) {
        vvi memo(sz(s) + 1, vi(sz(p) + 1, -1));
        return dfs(0, 0, s, p, memo);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = sz(s), m = sz(p);
        vvi dp(n + 1, vi(m + 2, 0));

        dp[n][m] = 1;
        revloop(it2, m - 2, 0)
            if (p[it2 + 1] == '*')
                dp[n][it2] = dp[n][it2 + 2];

        revloop(it1, n, 0) {
            revloop(it2, m - 1, 0) {
                bool match = it1 < n &&
                            (s[it1] == p[it2] || p[it2] == '.');

                if (it2 != m - 1 && p[it2 + 1] == '*')
                    dp[it1][it2] = dp[it1][it2 + 2] ||
                                    (match && dp[it1 + 1][it2]);
                else
                    dp[it1][it2] = (match && dp[it1 + 1][it2 + 1]);
            }
        }

        return dp[0][0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.isMatch("aa", "a");
    print(res);
    res = obj.isMatch("aa", "a*");
    print(res);
    res = obj.isMatch("aa", ".*");
    print(res);
    res = obj.isMatch("aab", "c*a*b");
    print(res);
    return 0;
}

/*
Problem: Regular Expression Matching
*/