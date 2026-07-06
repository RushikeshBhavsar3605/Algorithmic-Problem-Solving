#include "template.hpp"

class Solution {
  public:
    string minWindow(string s, string t) {
        vi freq(128, 0);
        iterate(ch, t)
            freq[ch]++;

        int left = 0;
        int start = 0;
        int minLength = INT_MAX;
        int required = sz(t);

        loop(right, 0, sz(s)) {
            if (freq[s[right]]-- > 0)
                required--;

            while (required == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                if (++freq[s[left++]] > 0)
                    required++;
            }
        }

        return minLength == INT_MAX ? "" : s.substr(start, minLength);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.minWindow("ADOBECODEBANC", "ABC");
    print(res);
    res = obj.minWindow("a", "a");
    print(res);
    res = obj.minWindow("a", "aa");
    print(res);
    return 0;
}

/*
Problem: Minimum Window Substring
*/