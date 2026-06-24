#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    bool detectCapitalUse(string word) {
        int upCnt = 0;
        int downCnt = 0;

        iterate(it, word) {
            if ('a' <= it && it <= 'z')
                downCnt++;
            if ('A' <= it && it <= 'Z')
                upCnt++;
        }

        if (upCnt == 0 || downCnt == 0)
            return true;

        if (upCnt == 1 && 'A' <= word[0] && word[0] <= 'Z')
            return true;

        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.detectCapitalUse("USA");
    print(res);
    res = obj.detectCapitalUse("FlaG");
    print(res);
    return 0;
}

/*
Problem: Detect Capital
*/