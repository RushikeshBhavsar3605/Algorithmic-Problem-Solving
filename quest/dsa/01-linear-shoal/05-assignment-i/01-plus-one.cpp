#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int n = sz(digits);
        int carry = 1;
        vi res;

        revloop(i, n - 1, 0) {
            if (digits[i] + carry == 10)
                res.pb(0);
            else {
                res.pb(digits[i] + carry);
                carry = 0;
            }
        }

        if (carry)
            res.pb(carry);

        reverse(all(res));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3};
    auto res = obj.plusOne(v);
    print(res);
    v = {4, 3, 2, 1};
    res = obj.plusOne(v);
    print(res);
    v = {9};
    res = obj.plusOne(v);
    print(res);
    return 0;
}

/*
Problem: Plus One
*/