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

class Solution {
  public:
    int minSubarray(vector<int> &nums, int p) {
        int targetElimination = 0;
        iterate(it, nums) targetElimination = (targetElimination + it) % p;

        if (targetElimination == 0)
            return 0;

        int prefixSum = 0;
        int result = INT_MAX;
        umap<int, int> mp;
        mp[0] = -1;

        loop(i, 0, sz(nums)) {
            prefixSum = (prefixSum + nums[i]) % p;

            int target = (prefixSum - targetElimination + p) % p;

            if (mp.count(target))
                updateMin(result, i - mp[target]);

            mp[prefixSum] = i;
        }

        return (result != INT_MAX && result != sz(nums)) ? result : -1;
    }
};

int main() {
    Solution obj;
    vi v = {3, 1, 4, 2};
    println(obj.minSubarray(v, 6));
    v = {6, 3, 5, 2};
    println(obj.minSubarray(v, 9));
    v = {1, 2, 3};
    println(obj.minSubarray(v, 3));
    v = {4, 4, 2};
    println(obj.minSubarray(v, 7));
}

/*
Problem: Make Sum Divisible by P
*/