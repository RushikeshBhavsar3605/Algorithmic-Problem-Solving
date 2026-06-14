#include "template.hpp"

/* Approach (Monotonic Stack + Hashing): */
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        int n = sz(s);
        vi lastIdx(26);
        loop(i, 0, n)
            lastIdx[s[i] - 'a'] = i;

        string res;
        vi take(26, 0);

        loop(i, 0, n) {
            if (take[s[i] - 'a'])
                continue;

            while (!res.empty() && res.back() > s[i] && lastIdx[res.back() - 'a'] > i) {
                take[res.back() - 'a'] = 0;
                res.pop_back();
            }

            res.pb(s[i]);
            take[s[i] - 'a'] = 1;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.removeDuplicateLetters("bcabc");
    print(res);
    res = obj.removeDuplicateLetters("cbacdcbc");
    print(res);
    return 0;
}

/*
Problem: Remove Duplicate Letters
*/