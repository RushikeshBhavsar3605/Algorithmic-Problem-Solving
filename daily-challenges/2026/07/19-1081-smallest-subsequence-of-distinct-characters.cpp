#include "template.hpp"

/* Approach (Monotonic Stack): */
class Solution {
  public:
    string smallestSubsequence(string s) {
        vi lastIndex(26, 0);
        loop(i, 0, sz(s)) lastIndex[s[i] - 'a'] = i;

        vi vis(26, 0);
        string res;

        loop(i, 0, sz(s)) {
            if (vis[s[i] - 'a'])
                continue;

            while (!res.empty() && res.back() > s[i] && i < lastIndex[res.back() - 'a']) {
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }

            vis[s[i] - 'a'] = true;
            res.push_back(s[i]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.smallestSubsequence("bcabc");
    print(res);
    res = obj.smallestSubsequence("cbacdcbc");
    print(res);
    return 0;
}

/*
Problem: Smallest Subsequence of Distinct Characters
*/