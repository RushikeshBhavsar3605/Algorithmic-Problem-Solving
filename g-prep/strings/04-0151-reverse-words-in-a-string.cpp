#include "template.hpp"

class Solution {
  public:
    string reverseWords(string s) {
        reverse(all(s));

        int write = 0;
        int i = 0;
        int n = sz(s);

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            if (i == n)
                break;

            if (write > 0)
                s[write++] = ' ';

            int start = write;
            while (i < n && s[i] != ' ')
                s[write++] = s[i++];

            reverse(begin(s) + start, begin(s) + write);
        }

        s.resize(write);
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.reverseWords("the sky is blue");
    print(res);
    res = obj.reverseWords("  hello world  ");
    print(res);
    res = obj.reverseWords("a good   example");
    print(res);
    return 0;
}

/*
Problem: Reverse Words in a String
*/