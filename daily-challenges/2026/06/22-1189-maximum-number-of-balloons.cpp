#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int maxNumberOfBalloons(string text) {
        vi freq(26, 0);
        iterate(it, text)
            freq[it - 'a']++;

        int cnt = INT_MAX;
        iterate(it, string("balloon")) {
            if (it == 'l' || it == 'o')
                updateMin(cnt, freq[it - 'a'] >> 1);
            else
                updateMin(cnt, freq[it - 'a']);
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maxNumberOfBalloons("nlaebolko");
    print(res);
    res = obj.maxNumberOfBalloons("loonbalxballpoon");
    print(res);
    res = obj.maxNumberOfBalloons("leetcode");
    print(res);
    return 0;
}

/*
Problem: Maximum Number of Balloons
*/