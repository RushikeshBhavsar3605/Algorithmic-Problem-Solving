#include "template.hpp"

/* Approach (Sliding Window): */
class Solution {
  public:
    int maximumLengthSubstring(string s) {
        int n = sz(s);
        int res = 0;
        umap<int, int> mp;

        int left = 0;
        loop(right, 0, n) {
            mp[s[right]]++;

            while (mp[s[right]] > 2)
                mp[s[left++]]--;

            updateMax(res, right - left + 1);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maximumLengthSubstring("bcbbbcba");
    print(res);
    res = obj.maximumLengthSubstring("aaaa");
    print(res);
    return 0;
}

/*
Problem: Maximum Length Substring With Two Occurrences
*/