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
    int maximumUniqueSubarray(vector<int> &nums) {
        unordered_map<int, int> mp; // Tracks frequency of elements in current window
        int best = 0;
        int low = 0, sum = 0;

        loop(high, 0, nums.size()) {
            mp[nums[high]]++;
            sum += nums[high];

            // Shrink window if duplicate found
            while (mp[nums[high]] == 2) {
                int removed = nums[low++];
                sum -= removed;
                if (--mp[removed] == 0)
                    mp.erase(removed); // Clean up to keep map size minimal
            }

            best = max(best, sum); // Update max sum of unique subarray
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {4, 2, 4, 5, 6};
    cout << obj.maximumUniqueSubarray(v);
    cout << endl;
    v = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    cout << obj.maximumUniqueSubarray(v);
    return 0;
}

/*
Problem: Maximum Erasure Value
*/