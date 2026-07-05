#include "template.hpp"

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (sz(s) != sz(t))
            return false;

        vi freq(26, 0);

        iterate(ch, s)
            freq[ch - 'a']++;

        iterate(ch, t)
            if (--freq[ch - 'a'] < 0)
                return false;

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    string s = "anagram", t = "nagaram";
    auto res = obj.isAnagram(s, t);
    print(res);
    s = "rat", t = "car";
    res = obj.isAnagram(s, t);
    print(res);
    return 0;
}

/*
Problem: Valid Anagram
*/