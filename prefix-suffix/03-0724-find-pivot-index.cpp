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

/* Approach 1 (Naive):
class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int n = sz(nums);

        loop(idx, 0, n) {
            int leftSum = 0;
            loop(i, 0, idx)
                leftSum += nums[i];

            int rightSum = 0;
            loop(i, idx + 1, n)
                rightSum += nums[i];

            if (leftSum == rightSum)
                return idx;
        }

        return -1;
    }
};
*/

/* Approach 2 (Prefix Sum):
class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int n = sz(nums);
        vi prefixSum(n);

        loop(i, 0, n)
            if (i == 0)
                prefixSum[i] = nums[i];
            else
                prefixSum[i] += prefixSum[i - 1] + nums[i];

        loop(idx, 0, n) {
            int leftSum = 0;
            if (idx != 0)
                leftSum = prefixSum[idx - 1];

            int rightSum = 0;
            if (idx != n - 1)
                rightSum = prefixSum[n - 1] - prefixSum[idx];

            if (leftSum == rightSum)
                return idx;
        }

        return -1;
    }
};
*/

/* Approach 3 (Optimized Prefix Sum): */
class Solution {
  public:
    int pivotIndex(vector<int> &nums) {
        int n = sz(nums);

        int leftSum = 0;
        int rightSum = accumulate(all(nums), 0);

        loop(idx, 0, n) {
            rightSum -= nums[idx];

            if (leftSum == rightSum)
                return idx;

            leftSum += nums[idx];
        }

        return -1;
    }
};

int main() {
    Solution obj;
    vi v = {1, 7, 3, 6, 5, 6};
    cout << obj.pivotIndex(v) << endl;
    v = {1, 2, 3};
    cout << obj.pivotIndex(v) << endl;
    v = {2, 1, -1};
    cout << obj.pivotIndex(v) << endl;
}

/*
Problem: Find Pivot Index
*/