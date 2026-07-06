#include "template.hpp"

/* Approach 1 (Naive) (TLE):
class Solution {
  private:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--])
                return false;

        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        int n = sz(words);
        vvi res;

        loop(i, 0, n) {
            loop(j, 0, n) {
                if (i == j)
                    continue;

                string s = words[i] + words[j];
                if (isPalindrome(s, 0, sz(s) - 1))
                    res.pb({i, j});
            }
        }

        return res;
    }
};
*/

/* Approach 2 (Split Hashing): */
class Solution {
  private:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--])
                return false;

        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        umap<string, int> index;
        loop(i, 0, sz(words))
            index[words[i]] = i;

        vvi res;

        loop(i, 0, sz(words)) {
            const string &word = words[i];

            loop(cut, 0, sz(word) + 1) {
                string prefix = word.substr(0, cut);
                string suffix = word.substr(cut);

                if (isPalindrome(prefix, 0, sz(prefix) - 1)) {
                    string rev = suffix;
                    reverse(all(rev));

                    if (index.count(rev) && index[rev] != i)
                        res.pb({index[rev], i});
                }

                if (cut != sz(word) && isPalindrome(suffix, 0, sz(suffix) - 1)) {
                    string rev = prefix;
                    reverse(all(rev));

                    if (index.count(rev) && index[rev] != i)
                        res.pb({i, index[rev]});
                }
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> v = {"abcd", "dcba", "lls", "s", "sssll"};
    auto res = obj.palindromePairs(v);
    print(res);
    v = {"bat", "tab", "cat"};
    res = obj.palindromePairs(v);
    print(res);
    v = {"a", ""};
    res = obj.palindromePairs(v);
    print(res);
    return 0;
}

/*
Problem: Palindrome Pairs
*/