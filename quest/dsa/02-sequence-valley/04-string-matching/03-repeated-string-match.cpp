#include "template.hpp"

/* Approach (KMP LPS): */
class Solution {
  private:
    vi buildLPS(string &s) {
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

        return lps;
    }

    bool kmpSearch(string &text, string &b) {
        vi lps = buildLPS(b);

        int n = sz(text);
        int m = sz(b);

        int pre = 0;
        loop(suf, 0, n) {
            while (pre > 0 && b[pre] != text[suf])
                pre = lps[pre - 1];

            if (b[pre] == text[suf])
                pre++;

            if (pre == m)
                return true;
        }

        return false;
    }

  public:
    int repeatedStringMatch(string a, string b) {
        int repeats = (sz(a) + sz(b) - 1) / sz(a);

        string text;
        loop(i, 0, repeats) text += a;

        if (kmpSearch(text, b))
            return repeats;

        text += a;

        if (kmpSearch(text, b))
            return repeats + 1;

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.repeatedStringMatch("abcd", "cdabcdab");
    print(res);
    res = obj.repeatedStringMatch("a", "aa");
    print(res);
    return 0;
}

/*
Problem: Repeated String Match
*/