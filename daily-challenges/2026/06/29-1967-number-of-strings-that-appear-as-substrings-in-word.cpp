#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int numOfStrings(vector<string> &patterns, string word) {
        int cnt = 0;
        iterate(pattern, patterns) {
            if (word.find(pattern) != string::npos)
                cnt++;
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vector<string> v = {"a", "abc", "bc", "d"};
    auto res = obj.numOfStrings(v, "abc");
    print(res);
    v = {"a", "b", "c"};
    res = obj.numOfStrings(v, "aaaaabbbbb");
    print(res);
    v = {"a", "a", "a"};
    res = obj.numOfStrings(v, "ab");
    print(res);
    return 0;
}

/*
Problem: Number of Strings That Appear as Substrings in Word
*/