#include "template.hpp"

/* Approach (Prefix Sum): */
class Solution {
  public:
    string shiftingLetters(string s, vector<int> &shifts) {
        revloop(i, sz(shifts) - 2, 0)
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;

        string res;
        loop(i, 0, sz(s)) {
            int id = s[i] - 'a';
            int shift = (id + shifts[i]) % 26;

            res.pb(shift + 'a');
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 5, 9};
    auto res = obj.shiftingLetters("abc", v);
    print(res);
    v = {1, 2, 3};
    res = obj.shiftingLetters("aaa", v);
    print(res);
    return 0;
}

/*
Problem: Shifting Letters
*/