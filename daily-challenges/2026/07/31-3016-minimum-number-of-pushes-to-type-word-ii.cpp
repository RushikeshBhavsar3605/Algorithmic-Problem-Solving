#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    int minimumPushes(string word) {
        vi freq(26, 0);
        iterate(it, word) freq[it - 'a']++;

        sort(all(freq), greater<int>());
        int pushes = 0;

        loop(i, 0, 26) {
            if (freq[i] == 0)
                break;

            pushes += (i / 8 + 1) * freq[i];
        }

        return pushes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.minimumPushes("abcde");
    print(res);
    res = obj.minimumPushes("xyzxyzxyzxyz");
    print(res);
    res = obj.minimumPushes("aabbccddeeffgghhiiiiii");
    print(res);
    return 0;
}

/*
Problem: Minimum Number of Pushes to Type Word II
*/