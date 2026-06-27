#include "template.hpp"

/* Approach 1 (Brute Force):
class Solution {
  public:
    bool rotateString(string s, string goal) {
        loop(i, 0, sz(s)) {
            if (s == goal)
                return true;

            rotate(begin(s), begin(s) + 1, end(s));
        }

        return false;
    }
};
*/

/* Approach 2 (String Trick (s + s)):
class Solution {
  public:
    bool rotateString(string s, string goal) {
        if (sz(s) != sz(goal))
            return false;

        return (s + s).find(goal) != string::npos;
    }
};
*/

/* Approach 3 (KMP LPS): */
class Solution {
  public:
    bool rotateString(string s, string goal) {
        if (sz(s) != sz(goal))
            return false;

        int m = sz(s);
        string text = s + s;

        vi lps(m, 0);

        int pre = 0;
        loop(suf, 1, m) {
            while (pre > 0 && goal[pre] != goal[suf])
                pre = lps[pre - 1];

            if (goal[pre] == goal[suf])
                pre++;

            lps[suf] = pre;
        }

        pre = 0;
        loop(suf, 0, sz(text)) {
            while (pre > 0 && goal[pre] != text[suf])
                pre = lps[pre - 1];

            if (goal[pre] == text[suf])
                pre++;

            if (pre == m)
                return true;
        }

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.rotateString("abcde", "cdeab");
    print(res);
    res = obj.rotateString("abcde", "abced");
    print(res);
    return 0;
}

/*
Problem: Rotate String
*/