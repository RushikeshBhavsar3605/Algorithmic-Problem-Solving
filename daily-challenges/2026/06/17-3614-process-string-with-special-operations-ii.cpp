#include "template.hpp"

class Solution {
  public:
    char processStr(string s, long long k) {
        ll len = 0;
        iterate(ch, s) {
            if (ch >= 'a' && ch <= 'z')
                len++;
            else if (ch == '#')
                len = len * 2;
            else if (ch == '*')
                if (len > 0)
                    len--;
        }

        if (k >= len)
            return '.';

        revloop(i, sz(s) - 1, 0) {
            char ch = s[i];

            if (ch == '*')
                len++;
            else if (ch == '#') {
                len = len / 2;
                if (k >= len)
                    k = k - len;
            } else if (ch == '%')
                k = len - 1 - k;
            else {
                len--;
                if (len == k)
                    return ch;
            }
        }

        return '.';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.processStr("a#b%*", 1);
    print(res);
    res = obj.processStr("cd%#*#", 3);
    print(res);
    res = obj.processStr("z*#", 0);
    print(res);
    return 0;
}

/*
Problem: Process String with Special Operations II
*/