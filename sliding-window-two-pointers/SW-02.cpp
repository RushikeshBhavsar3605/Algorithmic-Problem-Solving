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
    int longestOnes(vector<int> &nums, int k) {
        int best = 0;
        int low = 0;

        loop(high, 0, nums.size()) {
            // If current is 0 and no flips left, move 'low' to free up a flip
            while (nums[high] == 0 && k == 0)
                if (nums[low] == 0)
                    low++, k++; // Reclaim a flip
                else
                    low++; // Skip 1s

            if (nums[high] == 0)
                k--; // Use a flip for current 0

            best = max(best, high - low + 1); // Update max length
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << obj.longestOnes(v, 2) << endl;
    v = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    cout << obj.longestOnes(v, 3) << endl;
    return 0;
}

/*
Problem: Max Consecutive Ones III
*/