#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

/* Approach 1 (Counting): */
class Solution {
  public:
    int longestSubarray(vector<int> &nums) {
        int maxi = 0;
        int count = 0;
        int change = -1;

        loop(i, 0, sz(nums)) {
            if (nums[i] == 1)
                count++;
            else if (change) {
                count = i - change - 1;
                change = i;
            } else
                change = i;

            updateMax(maxi, count);
        }

        return change != -1 ? maxi : maxi - 1;
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 0, 1};
    cout << obj.longestSubarray(v) << endl;
    v = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << obj.longestSubarray(v) << endl;
    v = {1, 1, 1};
    cout << obj.longestSubarray(v) << endl;
    return 0;
}

/*
Problem: Longest Subarray of 1's After Deleting One Element
*/