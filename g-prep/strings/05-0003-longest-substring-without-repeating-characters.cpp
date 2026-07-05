#include "template.hpp"

/* Approach 1 (Two Pointer):
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        vi lastSeen(128, 0);

        int maxi = 0;
        int left = 0;

        loop(right, 0, sz(s)) {
            lastSeen[s[right]]++;

            while (lastSeen[s[right]] > 1)
                lastSeen[s[left++]]--;

            updateMax(maxi, right - left + 1);
        }

        return maxi;
    }
};
*/

/* Approach 2 (Two Pointer): */
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        vi lastSeen(128, -1);

        int left = 0;
        int longest = 0;

        loop(right, 0, sz(s)) {
            updateMax(left, lastSeen[s[right]] + 1);
            lastSeen[s[right]] = right;
            updateMax(longest, right - left + 1);
        }

        return longest;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.lengthOfLongestSubstring("abcabcbb");
    print(res);
    res = obj.lengthOfLongestSubstring("bbbbb");
    print(res);
    res = obj.lengthOfLongestSubstring("pwwkew");
    print(res);
    return 0;
}

/*
Problem: Longest Substring Without Repeating Characters
*/