#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string processStr(string s) {
        string res;
        iterate(it, s) {
            if ('a' <= it && it <= 'z')
                res.pb(it);

            if (res.empty())
                continue;

            if (it == '*')
                res.pop_back();
            else if (it == '#')
                res += res;
            else if (it == '%')
                reverse(all(res));
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.processStr("a#b%*");
    print(res);
    res = obj.processStr("z*#");
    print(res);
    return 0;
}

/*
Problem: Process String with Special Operations I
*/