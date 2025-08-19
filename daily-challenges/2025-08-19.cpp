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

/* Approach 1 (Two Pointer): */
class Solution {
  public:
    long long zeroFilledSubarray(vector<int> &nums) {
        int n = sz(nums);
        long long result = 0;
        int high = 0, low = 0;

        while (low < n) {
            while (high < n && nums[high] == 0)
                high++;

            ll count = high - low;
            result += (ll)(count * (count + 1) >> 1);

            low = high = high + 1;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 3, 0, 0, 2, 0, 0, 4};
    cout << obj.zeroFilledSubarray(v) << endl;
    v = {0, 1, 0, 0, 1, 0, 0, 0};
    cout << obj.zeroFilledSubarray(v) << endl;
    return 0;
}

/*
Problem: Number of Zero-Filled Subarrays
*/