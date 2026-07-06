#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string convertToTitle(int columnNumber) {
        string title;

        while (columnNumber) {
            columnNumber--;
            title += char('A' + columnNumber % 26);
            columnNumber /= 26;
        }

        reverse(all(title));
        return title;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.convertToTitle(1);
    print(res);
    res = obj.convertToTitle(28);
    print(res);
    res = obj.convertToTitle(701);
    print(res);
    return 0;
}

/*
Problem: Excel Sheet Column Title
*/