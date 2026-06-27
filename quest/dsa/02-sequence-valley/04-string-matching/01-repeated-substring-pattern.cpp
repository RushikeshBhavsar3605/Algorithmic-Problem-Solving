#include "template.hpp"

/* Approach 1 (Brute Force):
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int n = sz(s);

        loop(len, 1, (n >> 1) + 1) {
            if (n % len != 0)
                continue;

            string pattern = s.substr(0, len);
            string built = "";

            loop(i, 0, n / len) built += pattern;

            if (built == s)
                return true;
        }

        return false;
    }
};
*/

/* Approach 2 (String Trick (s + s)):
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        return doubled.substr(1, sz(doubled) - 2).find(s) != string::npos;
    }
};
*/

/* Approach 3 (KMP LPS): */
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int n = sz(s);

        vi lps(n, 0);

        int pre = 0;
        loop(suf, 1, n) {
            while (pre > 0 && s[pre] != s[suf])
                pre = lps[pre - 1];

            if (s[pre] == s[suf])
                pre++;

            lps[suf] = pre;
        }

        int longestPrefixSuffix = lps[n - 1];
        int remaining = n - longestPrefixSuffix;
        return longestPrefixSuffix > 0 && n % remaining == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.repeatedSubstringPattern("abab");
    print(res);
    res = obj.repeatedSubstringPattern("aba");
    print(res);
    res = obj.repeatedSubstringPattern("abcabcabcabc");
    print(res);
    return 0;
}

/*
Problem: Repeated Substring Pattern
*/