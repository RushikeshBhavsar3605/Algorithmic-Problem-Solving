#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int temp = n;

        while (temp) {
            int digit = temp % 10;
            sum += digit;
            prod *= digit;
            temp /= 10;
        }

        return n % (sum + prod) == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.checkDivisibility(99);
    print(res);
    res = obj.checkDivisibility(23);
    print(res);
    return 0;
}

/*
Problem: Check Divisibility by Digit Sum and Product
*/