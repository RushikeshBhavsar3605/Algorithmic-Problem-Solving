#include "template.hpp"

/* Approach 1 (Arithmetic Progression):
class Solution {
  public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = (2 * n * n) / 2;
        int sumEven = (2 * n * n) / 2 + n;

        return gcd(sumOdd, sumEven);
    }
};
*/

/* Approach 2 (Simplified Arithmetic Progression):
class Solution {
  public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n + 1);

        return gcd(sumOdd, sumEven);
    }
};
*/

/* Approach 3 (Simplification):
gcd(n * n, n * (n + 1))
n * gcd(n, n + 1)
*/
class Solution {
  public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.gcdOfOddEvenSums(4);
    print(res);
    res = obj.gcdOfOddEvenSums(5);
    print(res);
    return 0;
}

/*
Problem: GCD of Odd and Even Sums
*/