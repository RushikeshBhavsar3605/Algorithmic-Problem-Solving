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

/* Approach 1 (Mapping of Remainder):
class Solution {
  public:
    long long minArraySum(vector<int> &nums, int k) {
        int n = sz(nums);

        vector<ll> best(k, LLONG_MIN); // maximum value of dp[j] - pref[j] for each pref[j] mod k
        best[0] = 0;
        vector<ll> dp(n, 0), prefix(n, 0); // dp -> max removable sum for [0, i]

        loop(i, 0, n) {
            prefix[i] += nums[i];
            if (i)
                dp[i] = dp[i - 1], prefix[i] += prefix[i - 1];

            int remainder = prefix[i] % k;

            if (best[remainder] != LLONG_MIN)
                updateMax(dp[i], prefix[i] + best[remainder]); // pref[i] + max(dp[j] - pref[j]) over all valid j

            // keep track of the strongest (dp[j] - prefix[j]) for this remainder
            updateMax(best[remainder], dp[i] - prefix[i]);
        }

        ll sum = 0;
        iterate(it, nums)
            sum += it;

        return sum - dp[n - 1];
    }
};
*/

/* Approach 2 (Optimization based on observation): */
class Solution {
  public:
    long long minArraySum(vector<int> &nums, int k) {
        int n = sz(nums);

        // best[r] = best value of (removableSum - prefixSum)
        // for any prefix with remainder r
        vector<ll> best(k, LLONG_MIN);
        best[0] = 0;

        ll maxRemovable = 0; // max total sum we can delete so far
        ll prefixSum = 0;    // running prefix sum (ends as total sum)

        loop(i, 0, n) {
            prefixSum += nums[i];

            int remainder = prefixSum % k;

            // try deleting a subarray ending here
            if (best[remainder] != LLONG_MIN)
                updateMax(maxRemovable, prefixSum + best[remainder]);

            // update state for future subarrays
            updateMax(best[remainder], maxRemovable - prefixSum);
        }

        // final sum = totalSum - maxRemovable
        return prefixSum - maxRemovable;
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 1};
    cout << obj.minArraySum(v, 2) << endl;
    return 0;
}

/*
Problem: Minimum Sum After Divisible Sum Deletions
*/