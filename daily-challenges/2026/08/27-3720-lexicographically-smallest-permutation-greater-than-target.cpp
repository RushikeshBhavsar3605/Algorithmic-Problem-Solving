#include "template.hpp"

/* Approach (Greedy): */
class Solution {
  public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            int t = target[i] - 'a';

            if (cnt[t]) {
                ans += target[i];
                cnt[t]--;
                continue;
            }

            int greater = -1;
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c]) {
                    greater = c;
                    break;
                }
            }

            if (greater == -1) {
                while (!ans.empty()) {
                    int prev = ans.back() - 'a';
                    ans.pop_back();
                    cnt[prev]++;

                    int need = target[ans.size()] - 'a';

                    for (int c = need + 1; c < 26; c++) {
                        if (cnt[c]) {
                            ans += char('a' + c);
                            cnt[c]--;

                            for (int x = 0; x < 26; x++)
                                ans.append(cnt[x], 'a' + x);

                            return ans;
                        }
                    }
                }

                return "";
            }

            ans += char('a' + greater);
            cnt[greater]--;

            for (int c = 0; c < 26; c++)
                ans.append(cnt[c], 'a' + c);

            return ans;
        }

        while (!ans.empty()) {
            int prev = ans.back() - 'a';
            ans.pop_back();
            cnt[prev]++;

            int need = target[ans.size()] - 'a';

            for (int c = need + 1; c < 26; c++) {
                if (cnt[c]) {
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int x = 0; x < 26; x++)
                        ans.append(cnt[x], 'a' + x);

                    return ans;
                }
            }
        }

        return "";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.lexGreaterPermutation("abc", "bba");
    print(res);
    res = obj.lexGreaterPermutation("leet", "code");
    print(res);
    res = obj.lexGreaterPermutation("baba", "bbaa");
    print(res);
    return 0;
}

/*
Problem: Lexicographically Smallest Permutation Greater Than Target
*/