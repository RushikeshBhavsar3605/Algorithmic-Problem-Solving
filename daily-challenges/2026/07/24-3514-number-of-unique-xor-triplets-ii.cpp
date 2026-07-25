#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    int uniqueXorTriplets(vector<int> &nums) {
        int n = sz(nums);

        uset<int> s1;
        loop(i, 0, n)
            loop(j, i, n)
                s1.insert(nums[i] ^ nums[j]);

        uset<int> s2;
        iterate(pairXor, s1)
            iterate(num, nums)
                s2.insert(pairXor ^ num);

        return sz(s2);
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    int uniqueXorTriplets(vector<int> &nums) {
        int n = sz(nums);
        int maxEle = *max_element(all(nums));

        int T = 1;
        while (T <= maxEle)
            T <<= 1;

        vector<bool> s1(T, false);
        loop(i, 0, n)
            loop(j, i, n)
                s1[nums[i] ^ nums[j]] = true;

        vector<bool> s2(T, false);
        loop(i, 0, T)
            if (s1[i])
                iterate(num, nums) s2[i ^ num] = true;

        int cnt = 0;
        loop(i, 0, T)
            if (s2[i])
                cnt++;

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3};
    auto res = obj.uniqueXorTriplets(v);
    print(res);
    v = {6, 7, 8, 9};
    res = obj.uniqueXorTriplets(v);
    print(res);
    return 0;
}

/*
Problem: Number of Unique XOR Triplets II
*/