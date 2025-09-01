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

/* Approach 1 (Sorting):
class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(all(nums), greater<int>());

        int sum = nums[0];
        loop(i, 1, nums.size())
            if (nums[i] != nums[i - 1] && nums[i] > 0)
                sum += nums[i];

        return sum;
    }
};
*/

/* Approach 2 (Set): */
class Solution {
  public:
    int maxSum(vector<int> &nums) {
        unordered_set<int> positiveNums;
        iterate(num, nums)
            if (num > 0)
                positiveNums.insert(num);

        if (positiveNums.empty())
            return *max_element(all(nums));

        return accumulate(all(positiveNums), 0);
    }
};

int main() {
    Solution obj;
    vi nums = {1, 2, 3, 4, 5};
    cout << obj.maxSum(nums);
    return 0;
}

/*
Problem: Maximum Unique Subarray Sum After Deletion
*/