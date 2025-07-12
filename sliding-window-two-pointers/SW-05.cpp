#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class Solution {
  private:
    // Returns count of subarrays with sum <= goal
    int helper(vi &nums, int goal) {
        if (goal < 0)
            return 0; // no valid subarray if goal is negative

        int result = 0;
        int low = 0, sum = 0;

        // sliding window over nums
        loop(high, 0, nums.size()) {
            sum += nums[high]; // include current element

            // shrink window until sum <= goal
            while (sum > goal)
                sum -= nums[low++]; // remove leftmost

            // all subarrays ending at high with sum <= goal
            result += (high - low + 1);
        }

        return result;
    }

  public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        // use inclusion-exclusion: <= goal minus <= goal-1
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};

int main() {
    Solution obj;
    vi v = {1, 0, 1, 0, 1};
    cout << obj.numSubarraysWithSum(v, 2) << endl;
    v = {0, 0, 0, 0, 0};
    cout << obj.numSubarraysWithSum(v, 0) << endl;
    return 0;
}

/*
Problem: Binary Subarrays With Sum
*/