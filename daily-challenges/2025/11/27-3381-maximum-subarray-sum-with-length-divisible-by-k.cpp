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

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Prefix Sum + Math): */
class Solution {
  public:
    long long maxSubarraySum(vector<int> &nums, int k) {
        // Tracks the minimal prefix sum for each mod k residue
        vector<ll> prefix(k, LLONG_MAX / 2);
        // No elements: prefix sum is 0 for mod 0
        prefix[0] = 0;

        // Max found so far (initialize ultra-low)
        ll res = LLONG_MIN;
        // Running prefix sum
        ll total = 0;

        loop(i, 0, sz(nums)) {
            total += nums[i]; // Advance prefix sum

            int length = i + 1;
            int prefixLen = length % k; // Current subarray length mod k

            // Potential new max: total-minimal prior prefix at same mod k
            updateMax(res, total - prefix[prefixLen]);
            // Keep minimal prefix value for this mod k residue
            updateMin(prefix[prefixLen], total);
        }

        return res; // Return maximal subarray sum found
    }
};

int main() {
    Solution obj;
    vi v = {1, 2};
    println(obj.maxSubarraySum(v, 1));
    v = {-1, -2, -3, -4, -5};
    println(obj.maxSubarraySum(v, 4));
    v = {-5, 1, 2, -3, 4};
    println(obj.maxSubarraySum(v, 2));
}

/*
Problem: Maximum Subarray Sum With Length Divisible by K
*/