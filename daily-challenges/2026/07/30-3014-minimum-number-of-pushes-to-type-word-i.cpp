#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    int minimumPushes(string word) {
        int n = sz(word);
        int pushes = 0;
        int ops = 1;

        while (n) {
            pushes += min(8, n) * ops;
            n -= min(8, n);
            ops++;
        }

        return pushes;
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    int minimumPushes(string word) {
        int pushes = 0;

        loop(i, 0, sz(word))
            pushes += i / 8 + 1;

        return pushes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.minimumPushes("abcde");
    print(res);
    res = obj.minimumPushes("xycdefghij");
    print(res);
    return 0;
}

/*
Problem: Minimum Number of Pushes to Type Word I
*/