#include "template.hpp"

/* Approach (Greedy): */
class Solution {
  public:
    int maxActiveSectionsAfterTrade(string s) {
        int gain = 0;
        int totalOnes = 0;

        int leftZeroRun = -1;
        int rightZeroRun = 0;

        iterate(it, s) {
            if (it == '1') {
                if (rightZeroRun)
                    leftZeroRun = rightZeroRun;

                rightZeroRun = 0;
                totalOnes++;
            } else {
                rightZeroRun++;
                if (leftZeroRun != -1)
                    updateMax(gain, leftZeroRun + rightZeroRun);
            }
        }

        return gain + totalOnes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maxActiveSectionsAfterTrade("01");
    print(res);
    res = obj.maxActiveSectionsAfterTrade("0100");
    print(res);
    res = obj.maxActiveSectionsAfterTrade("1000100");
    print(res);
    res = obj.maxActiveSectionsAfterTrade("01010");
    print(res);
    return 0;
}

/*
Problem: Maximize Active Section with Trade I
*/