#include <bits/stdc++.h>
using namespace std;
int specialTriplets(vector<int> &nums) {
    const int MOD = 1e9 + 7;
    int maxi = *max_element(begin(nums), end(nums));
    int maxValue = maxi * 2;
    auto solve = [&](int maxi, vector<int> &nums, const int MOD) -> int {
        int result = 0;
        vector<int> lCnt(maxi + 1, 0), rCnt(maxi + 1, 0);
        for (int &it : nums)
            rCnt[it]++;
        for (int i = 0; i < nums.size(); i++) {
            int mid = nums[i];
            int into2 = mid * 2;
            rCnt[mid]--;

            int left = lCnt[into2];
            int right = rCnt[into2];
            result = (result + left * right) % MOD;

            lCnt[mid]++;
        }
        return result;
    };
    return solve(maxi, nums, MOD);
}
int main() {
    vector<int> nums = {0, 1, 0, 0};
    cout << specialTriplets(nums);
    return 0;
}

/*
Problem:
*/