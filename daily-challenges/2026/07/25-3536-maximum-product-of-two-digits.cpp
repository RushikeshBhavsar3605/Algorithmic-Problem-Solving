#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int maxProduct(int n) {
        int maxi1 = 0;
        int maxi2 = 0;

        while (n) {
            int digit = n % 10;
            n /= 10;

            if (maxi1 < digit) {
                maxi2 = maxi1;
                maxi1 = digit;
            } else if (maxi2 < digit)
                maxi2 = digit;
        }

        return maxi1 * maxi2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maxProduct(31);
    print(res);
    res = obj.maxProduct(22);
    print(res);
    res = obj.maxProduct(124);
    print(res);
    return 0;
}

/*
Problem: Maximum Product of Two Digits
*/