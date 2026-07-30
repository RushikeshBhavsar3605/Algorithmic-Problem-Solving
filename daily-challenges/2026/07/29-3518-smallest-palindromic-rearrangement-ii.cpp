#include "template.hpp"

/* Approach (Combinatorics): */
class Solution {
  private:
    int k;

    ll nCr(int n, int r) {
        updateMin(r, n - r);
        ll res = 1;

        loop(i, 1, r + 1) {
            res = res * (n - r + i) / i;

            if (res >= k)
                return k;
        }

        return res;
    }

    int permutations(vi &freq, int remaining) {
        ll ways = 1;

        iterate(it, freq) {
            if (it == 0)
                continue;

            ways *= nCr(remaining, it);

            if (ways >= k)
                return k;

            remaining -= it;
        }

        return ways;
    }

  public:
    string smallestPalindrome(string s, int k) {
        this->k = k;
        int n = sz(s);
        int half = n / 2;

        vi freq(26, 0);
        loop(i, 0, half) freq[s[i] - 'a']++;

        string left;

        loop(pos, 0, half) {
            loop(ch, 0, 26) {
                if (freq[ch] == 0)
                    continue;

                freq[ch]--;
                int remaining = half - pos - 1;
                int ways = permutations(freq, remaining);

                if (ways >= k) {
                    left.pb('a' + ch);
                    break;
                }

                k -= ways;
                freq[ch]++;
            }

            if (sz(left) == pos)
                return "";
        }

        string right = left;
        reverse(all(right));

        return left + (n & 1 ? string(1, s[half]) : "") + right;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.smallestPalindrome("abba", 2);
    print(res);
    res = obj.smallestPalindrome("aa", 2);
    print(res);
    res = obj.smallestPalindrome("bacab", 1);
    print(res);
    return 0;
}

/*
Problem: Smallest Palindromic Rearrangement II
*/