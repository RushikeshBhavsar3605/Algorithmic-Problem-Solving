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
  public:
    int countHillValley(vector<int> &nums) {
        int n = nums.size();
        int hills = 0;
        int valleys = 0;

        loop(i, 1, n - 1) {
            if (nums[i] == nums[i + 1])
                continue;

            int prev = i - 1;
            while (prev > 0 && nums[i] == nums[prev])
                prev--;

            int next = i + 1;
            while (next < n - 1 && nums[i] == nums[next])
                next++;

            if (nums[prev] < nums[i] && nums[i] > nums[next])
                hills++;
            else if (nums[prev] > nums[i] && nums[i] < nums[next])
                valleys++;
        }

        return hills + valleys;
    }
};

int main() {
    Solution obj;
    vi v = {57, 57, 57, 57, 57, 90, 90, 90, 90, 90, 90, 90, 90, 90,
            90, 90, 90, 90, 90, 90, 90, 90, 85, 85, 85, 86, 86, 86};
    cout << obj.countHillValley(v);
    return 0;
}

/*
Problem: Count Hills and Valleys in an Array
*/