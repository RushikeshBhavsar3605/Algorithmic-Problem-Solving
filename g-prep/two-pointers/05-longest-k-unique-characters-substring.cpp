#include "template.hpp"

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        vi freq(26, 0);
        int maxLen = -1;
        int distinctCnt = 0;

        int left = 0;
        loop(right, 0, sz(s)) {
            if (++freq[s[right] - 'a'] == 1)
                distinctCnt++;

            while (distinctCnt > k)
                if (--freq[s[left++] - 'a'] == 0)
                    distinctCnt--;

            if (distinctCnt == k)
                updateMax(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    string s = "aabacbebebe";
    auto res = obj.longestKSubstr(s, 3);
    print(res);
    s = "aaaa";
    res = obj.longestKSubstr(s, 2);
    print(res);
    s = "aabaaab";
    res = obj.longestKSubstr(s, 2);
    print(res);
    return 0;
}

/*
Problem: Longest Substring with K Uniques
*/