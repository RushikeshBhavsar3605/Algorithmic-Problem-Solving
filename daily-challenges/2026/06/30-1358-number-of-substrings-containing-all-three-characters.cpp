#include "template.hpp"

/* Approach (Sliding Window): */
class Solution {
  public:
    int numberOfSubstrings(string s) {
        int n = sz(s);
        int left = 0, right = 0;

        vi freq(3, 0);
        int total = 0;

        while (right < n) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                total += n - right;

                freq[s[left++] - 'a']--;
            }

            right++;
        }

        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.numberOfSubstrings("abcabc");
    print(res);
    res = obj.numberOfSubstrings("aaacb");
    print(res);
    res = obj.numberOfSubstrings("abc");
    print(res);
    return 0;
}

/*
Problem: Number of Substrings Containing All Three Characters
*/