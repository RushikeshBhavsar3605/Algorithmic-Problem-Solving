class Solution {
public:
    int reverseBits(int n) {
        // init: result to store reversed bits
        int res = 0;

        // loop: process all 32 bits of integer
        for (int i = 0; i < 32; i++) {
            // update:
            // 1) left shift result to make space for next bit
            // 2) add current LSB of n to result
            res = (res << 1) + (n & 1);

            // shift n right to process next bit
            n >>= 1;
        }

        // return: reversed 32-bit integer
        return res;
    }
};