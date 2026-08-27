#include "template.hpp"

/* Approach (Sliding Window): */
class Solution {
  public:
    string shortestBeautifulSubstring(string s, int k) {
        if (k == 0)
            return "";

        int minLen = INT_MAX, st = -1;
        int left = 0;

        loop(right, 0, sz(s)) {
            if (s[right] == '1')
                k--;

            while (k < 0 || s[left] == '0') {
                if (s[left] == '1')
                    k++;
                left++;
            }

            if (k == 0) {
                int len = right - left + 1;

                if (len < minLen || (len == minLen && s.compare(left, len, s, st, minLen) < 0)) {
                    minLen = len;
                    st = left;
                }
            }
        }

        return st != -1 ? s.substr(st, minLen) : "";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.shortestBeautifulSubstring("100011001", 3);
    print(res);
    res = obj.shortestBeautifulSubstring("1011", 2);
    print(res);
    res = obj.shortestBeautifulSubstring("000", 1);
    print(res);
    return 0;
}

/*
Problem: Shortest and Lexicographically Smallest Beautiful String
*/