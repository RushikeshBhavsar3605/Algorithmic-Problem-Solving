#include "template.hpp"

/* Approach (LPS): */
class Solution {
  public:
    string longestPrefix(string s) {
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

        return s.substr(0, lps[n - 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.longestPrefix("level");
    print(res);
    res = obj.longestPrefix("ababab");
    print(res);
    return 0;
}

/*
Problem: Longest Happy Prefix
*/