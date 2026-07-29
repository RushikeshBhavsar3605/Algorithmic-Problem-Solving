#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string smallestPalindrome(string s) {
        vi freq(26, 0);
        iterate(it, s) freq[it - 'a']++;

        string left;
        char mid = 0;

        loop(i, 0, 26) {
            left.append(freq[i] / 2, i + 'a');

            if (freq[i] & 1)
                mid = i + 'a';
        }

        string right = left;
        reverse(all(right));

        return left + (mid ? string(1, mid) : "") + right;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.smallestPalindrome("z");
    print(res);
    res = obj.smallestPalindrome("babab");
    print(res);
    res = obj.smallestPalindrome("daccad");
    print(res);
    return 0;
}

/*
Problem: Smallest Palindromic Rearrangement I
*/