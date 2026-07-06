#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  private:
    nvec_t<string, 1> dfs(int index, const string &s, uset<string> &words) {
        if (index == sz(s))
            return {""};

        nvec_t<string, 1> sentences;
        loop(i, index, sz(s)) {
            string word = s.substr(index, i - index + 1);
            if (!words.count(word))
                continue;

            iterate(suffix, dfs(i + 1, s, words))
                sentences.pb(
                    suffix.empty()
                        ? word
                        : word + " " + suffix
                );
        }

        return sentences;
    }

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        uset<string> words(all(wordDict));
        return dfs(0, s, words);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    nvec_t<string, 1> dfs(int index, const string &s, uset<string> &words, umap<int, nvec_t<string, 1>> &memo) {
        if (index == sz(s))
            return {""};

        if (memo.count(index))
            return memo[index];

        nvec_t<string, 1> sentences;
        loop(i, index, sz(s)) {
            string word = s.substr(index, i - index + 1);
            if (!words.count(word))
                continue;

            iterate(suffix, dfs(i + 1, s, words, memo))
                sentences.pb(
                    suffix.empty()
                        ? word
                        : word + " " + suffix
                );
        }

        return memo[index] = sentences;
    }

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        uset<string> words(all(wordDict));
        umap<int, nvec_t<string, 1>> memo;

        return dfs(0, s, words, memo);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        int n = sz(s);
        uset<string> words(all(wordDict));
        umap<int, nvec_t<string, 1>> dp;
        dp[n] = {""};

        revloop(index, n - 1, 0) {
            nvec_t<string, 1> sentences;

            loop(i, index, n) {
                string word = s.substr(index, i - index + 1);
                if (!words.count(word))
                    continue;

                iterate(suffix, dp[i + 1])
                    sentences.pb(
                        suffix.empty()
                            ? word
                            : word + " " + suffix
                    );
            }

            dp[index] = sentences;
        }

        return dp[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> v = {"cat", "cats", "and", "sand", "dog"};
    auto res = obj.wordBreak("catsanddog", v);
    print(res);
    v = {"apple", "pen", "applepen", "pine", "pineapple"};
    res = obj.wordBreak("pineapplepenapple", v);
    print(res);
    v = {"cats", "dog", "sand", "and", "cat"};
    res = obj.wordBreak("catsandog", v);
    print(res);
    return 0;
}

/*
Problem: Word Break II
*/