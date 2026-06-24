#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            string email = s;
            iterate(ch, email)
                ch = tolower(ch);

            int atPos = email.find('@');

            return string(1, email[0]) + "*****" + string(1, email[atPos - 1]) + email.substr(atPos);
        } else {
            string digits;
            iterate(ch, s)
                if (isdigit(ch))
                    digits += ch;

            int code = sz(digits) - 10;

            string res;
            if (code > 0)
                res += '+' + string(code, '*') + '-';

            res += "***-***-";
            res += digits.substr(sz(digits) - 4);

            return res;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maskPII("LeetCode@LeetCode.com");
    print(res);
    res = obj.maskPII("AB@qq.com");
    print(res);
    res = obj.maskPII("1(234)567-890");
    print(res);
    return 0;
}

/*
Problem: Masking Personal Information
*/