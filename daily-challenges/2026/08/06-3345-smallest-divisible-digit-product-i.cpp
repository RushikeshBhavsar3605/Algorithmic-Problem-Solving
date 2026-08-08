#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int smallestNumber(int n, int t) {
        auto isValid = [&](int num) {
            int prod = 1;

            while (num) {
                int d = num % 10;
                prod *= d;
                num /= 10;
            }

            return prod % t == 0;
        };

        loop(i, n, 101)
            if (isValid(i))
                return i;

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.smallestNumber(10, 2);
    print(res);
    res = obj.smallestNumber(15, 3);
    print(res);
    return 0;
}

/*
Problem: Smallest Divisible Digit Product I
*/