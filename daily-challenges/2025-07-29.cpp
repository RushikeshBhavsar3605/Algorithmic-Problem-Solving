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
    vector<int> smallestSubarrays(vector<int> &nums) {
        vi result(nums.size());
        vi setBitIndex(32, -1);

        revloop(i, nums.size() - 1, 0) {
            int endIndex = i;

            loop(j, 0, 32) {
                if (!(nums[i] & (1 << j))) {
                    if (setBitIndex[j] != -1)
                        endIndex = max(endIndex, setBitIndex[j]);
                } else
                    setBitIndex[j] = i;
            }

            result[i] = endIndex - i + 1;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 0, 2, 1, 3};
    vi result = obj.smallestSubarrays(v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Smallest Subarrays With Maximum Bitwise OR
*/