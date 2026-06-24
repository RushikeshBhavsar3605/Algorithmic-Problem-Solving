#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string licenseKeyFormatting(string s, int k) {
        int size = 0;
        int id = sz(s) - 1;

        string res;

        while (id >= 0) {
            if (size == k) {
                res += '-';
                size = 0;
            }

            if (s[id] != '-') {
                res += toupper(s[id]);
                size++;
            }

            id--;
        }

        if (!res.empty() && res.back() == '-')
            res.pop_back();

        reverse(all(res));
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.licenseKeyFormatting("5F3Z-2e-9-w", 4);
    print(res);
    res = obj.licenseKeyFormatting("2-5g-3-J", 2);
    print(res);
    return 0;
}

/*
Problem: License Key Formatting
*/