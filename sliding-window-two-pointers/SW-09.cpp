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
    int helper(vi &nums, int k) {
        if (k <= 0)
            return 0;

        unordered_map<int, int> mp; // counts in window
        int result = 0;
        int low = 0;

        loop(high, 0, nums.size()) {
            mp[nums[high]]++;     // expand window

            while (mp.size() > k) // shrink if unique elements exceeds
                if (mp[nums[low]] == 1)
                    mp.erase(nums[low++]); // drop and move low
                else
                    mp[nums[low++]]--;     // decrement count

            result += (high - low + 1); // all subarrays ending at high
        }

        return result;
    }

  public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        // use inclusion-exclusion: <= k minus <= k - 1
        return helper(nums, k) - helper(nums, k - 1);
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 1, 2, 3};
    cout << obj.subarraysWithKDistinct(v, 2) << endl;
    v = {1, 2, 1, 3, 4};
    cout << obj.subarraysWithKDistinct(v, 3) << endl;
    return 0;
}

/*
Problem: Subarrays with K Different Integers
*/