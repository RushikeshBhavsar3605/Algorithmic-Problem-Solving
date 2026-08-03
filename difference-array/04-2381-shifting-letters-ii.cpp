#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = sz(s);
        vi diff(n, 0);

        iterate(shift, shifts) {
            int left = shift[0];
            int right = shift[1] + 1;
            int dir = shift[2];

            diff[left] += (dir == 1) ? 1 : -1;
            if (right < n)
                diff[right] -= (dir == 1) ? 1 : -1;
        }

        loop(i, 1, n) diff[i] += diff[i - 1];

        string res;
        loop(i, 0, n) {
            int id = s[i] - 'a';
            int shift = (id + diff[i]) % 26;
            shift = (shift + 26) % 26;

            res.pb(shift + 'a');
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v{{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    auto res = obj.shiftingLetters("abc", v);
    print(res);
    v = {{0, 0, 0}, {1, 1, 1}};
    res = obj.shiftingLetters("dztz", v);
    print(res);
    return 0;
}

/*
Problem: Shifting Letters II
*/