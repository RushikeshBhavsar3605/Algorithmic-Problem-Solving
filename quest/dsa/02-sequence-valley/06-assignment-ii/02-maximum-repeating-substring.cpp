#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    int maxRepeating(string sequence, string word) {
        string pattern = word;
        int k = 0;

        while (sequence.find(pattern) != string::npos) {
            k++;
            pattern += word;
        }

        return k;
    }
};
*/

/* Approach 2 (KMP + LPS): */
class Solution {
  private:
    vi buildLPS(string word) {
        int m = sz(word);
        vi lps(m, 0);

        int pre = 0;
        loop(suf, 1, m) {
            while (pre > 0 && word[pre] != word[suf])
                pre = lps[pre - 1];

            if (word[pre] == word[suf])
                pre++;

            lps[suf] = pre;
        }

        return lps;
    }

  public:
    int maxRepeating(string sequence, string word) {
        int n = sz(sequence), m = sz(word);
        vi lps = buildLPS(word);
        vi occurs(n);

        int pre = 0;
        loop(suf, 0, n) {
            while (pre > 0 && word[pre] != sequence[suf])
                pre = lps[pre - 1];

            if (word[pre] == sequence[suf])
                pre++;

            if (pre == m) {
                occurs[suf - m + 1] = 1;
                pre = lps[pre - 1];
            }
        }

        vi dp(n + 1, 0);
        int res = 0;

        revloop(i, n - 1, 0) {
            if (occurs[i]) {
                dp[i] = 1;
                if (i + m < n)
                    dp[i] += dp[i + m];

                updateMax(res, dp[i]);
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maxRepeating("ababc", "ab");
    print(res);
    res = obj.maxRepeating("aababc", "ab");
    print(res);
    res = obj.maxRepeating("ababc", "ba");
    print(res);
    res = obj.maxRepeating("ababc", "ac");
    print(res);
    return 0;
}

/*
Problem: Maximum Repeating Substring
*/