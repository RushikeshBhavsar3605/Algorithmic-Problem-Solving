#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    int firstUniqChar(string s) {
        vi freq(26, 0);

        iterate(c, s)
            freq[c - 'a']++;

        loop(i, 0, sz(s))
            if (freq[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.firstUniqChar("leetcode");
    print(res);
    res = obj.firstUniqChar("loveleetcode");
    print(res);
    res = obj.firstUniqChar("aabb");
    print(res);
    return 0;
}

/*
Problem: First Unique Character in a String
*/