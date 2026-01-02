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

/* Approach 1 (Hashing):
class Solution {
  public:
    int repeatedNTimes(vector<int> &nums) {
        int n = sz(nums) >> 1;
        umap<int, int> mp;

        iterate(it, nums)
            if (++mp[it] == n)
                return it;

        return -1;
    }
};
*/

/* Approach 2 (Worst-Case Spacing): */
class Solution {
  public:
    int repeatedNTimes(vector<int> &nums) {
        loop(k, 1, 4)
            loop(i, 0, sz(nums) - k)
                if (nums[i] == nums[i + k])
                    return nums[i];

        return -1;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 3};
    println(obj.repeatedNTimes(v));
    v = {2, 1, 2, 5, 3, 2};
    println(obj.repeatedNTimes(v));
    v = {5, 1, 5, 2, 5, 3, 5, 4};
    println(obj.repeatedNTimes(v));
}

/*
Problem: N-Repeated Element in Size 2N Array
*/