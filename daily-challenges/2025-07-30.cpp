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
    int longestSubarray(vector<int> &nums) {
        pair<int, int> maxi = {-1, 1};
        pair<int, int> curr = {-1, 1};

        iterate(num, nums) {
            if (num == curr.first)
                curr.second++;
            else
                curr = {num, 1};

            if (curr.first > maxi.first)
                maxi = curr;
            else if (curr.first == maxi.first && curr.second > maxi.second)
                maxi = curr;
        }

        return maxi.second;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 3, 2, 2};
    cout << obj.longestSubarray(v) << endl;
    v = {1, 2, 3, 4};
    cout << obj.longestSubarray(v) << endl;
    return 0;
}

/*
Problem: Longest Subarray With Maximum Bitwise AND
*/