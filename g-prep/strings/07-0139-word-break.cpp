#include "template.hpp"

/* Approach 1 (Naive) (TLE):
class Solution {
  private:
    bool helper(int index, const string &s, umap<string, int> &mp) {
        if (index == sz(s))
            return true;

        string curr;
        loop(i, index, sz(s)) {
            curr += s[i];
            if (mp.count(curr) && helper(i + 1, s, mp))
                return true;
        }

        return false;
    }

  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        umap<string, int> mp;
        iterate(word, wordDict)
            mp[word] = 1;

        return helper(0, s, mp);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    bool helper(int index, const string &s, umap<string, int> &mp, vi &memo) {
        if (index == sz(s))
            return true;

        if (memo[index] != -1)
            return memo[index];

        string curr;
        loop(i, index, sz(s)) {
            curr += s[i];
            if (mp.count(curr) && helper(i + 1, s, mp, memo))
                return memo[index] = true;
        }

        return memo[index] = false;
    }

  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        umap<string, int> mp;
        iterate(word, wordDict)
            mp[word] = 1;

        vi memo(sz(s), -1);
        return helper(0, s, mp, memo);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        uset<string> words(all(wordDict));

        int n = sz(s);
        vi dp(n + 1, 0);
        dp[n] = 1;

        revloop(index, n - 1, 0) {
            loop(i, index, n) {
                if (dp[i + 1] && words.count(s.substr(index, i - index + 1))) {
                    dp[index] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> v = {"leet", "code"};
    auto res = obj.wordBreak("leetcode", v);
    print(res);
    v = {"apple", "pen"};
    res = obj.wordBreak("applepenapple", v);
    print(res);
    v = {"cats", "dog", "sand", "and", "cat"};
    res = obj.wordBreak("catsandog", v);
    print(res);
    return 0;
}

/*
Problem: Word Break
*/