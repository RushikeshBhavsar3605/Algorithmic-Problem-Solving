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
    int helper(vi &nums, int k) {
        if (k < 0)
            return 0; // no valid subarray if k is negative

        int result = 0;
        int low = 0, cnt = 0;

        // sliding window over nums
        loop(high, 0, nums.size()) {
            if (nums[high] & 1) // include current element
                cnt++;

            // shrink window until cnt <= k
            while (cnt > k) {
                if (nums[low] & 1)
                    cnt--;
                nums[low++]; // remove leftmost
            }

            // all subarrays ending at high with cnt <= k
            result += (high - low + 1);
        }

        return result;
    }

  public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        // use inclusion-exclusion: <= goal minus <= goal-1
        return helper(nums, k) - helper(nums, k - 1);
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 2, 1, 1};
    cout << obj.numberOfSubarrays(v, 3) << endl;
    v = {2, 4, 6};
    cout << obj.numberOfSubarrays(v, 1) << endl;
    v = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << obj.numberOfSubarrays(v, 2) << endl;
    return 0;
}

/*
Problem: Count Number of Nice Subarrays
*/