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

/* Approach 1 (Naive):
class Solution {
  private:
    bool isValid(int idx, int k, vi &nums) {
        loop(i, idx + 1, idx + k)
            if (nums[i - 1] >= nums[i])
                return false;

        loop(i, idx + k + 1, idx + 2 * k)
            if (nums[i - 1] >= nums[i])
                return false;

        return true;
    }

  public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k) {
        int n = sz(nums);
        loop(i, 0, n - 2 * k + 1)
            if (isValid(i, k, nums))
                return true;

        return false;
    }
};
*/

/* Approach 2 (Counting): */
class Solution {
  public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k) {
        int n = sz(nums);
        int cnt = 1, prevCnt = 0;

        loop(i, 1, n) {
            if (nums[i] > nums[i - 1])
                cnt++;
            else {
                prevCnt = cnt;
                cnt = 1;
            }

            if (cnt >= k && prevCnt >= k || (cnt >> 1) >= k)
                return true;
        }

        return false;
    }
};

int main() {
    Solution obj;
    vi v = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    println(obj.hasIncreasingSubarrays(v, 3));
    v = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    println(obj.hasIncreasingSubarrays(v, 5));
    v = {-15, 19};
    println(obj.hasIncreasingSubarrays(v, 1));
}

/*
Problem: Adjacent Increasing Subarrays Detection I
*/