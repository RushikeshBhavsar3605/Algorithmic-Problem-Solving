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

/* Approach 1 (Naive): */
class Solution {
  public:
    int minimumPairRemoval(vector<int> &nums) {
        if (sz(nums) < 2)
            return 0;

        auto isSorted = [&](vi &nums) {
            loop(i, 0, sz(nums) - 1)
                if (nums[i] > nums[i + 1])
                    return false;

            return true;
        };

        int ops = 0;
        while (!isSorted(nums)) {
            pii mini = {INT_MAX, -1};

            loop(i, 0, sz(nums) - 1) {
                if (nums[i] + nums[i + 1] < mini.ff) {
                    mini.ff = nums[i] + nums[i + 1];
                    mini.ss = i;
                }
            }
            nums.erase(nums.begin() + mini.ss, nums.begin() + mini.ss + 2);
            nums.insert(nums.begin() + mini.ss, mini.ff);
            ops++;
        }

        return ops;
    }
};

int main() {
    Solution obj;
    vi v = {5, 2, 3, 1};
    println(obj.minimumPairRemoval(v));
    v = {1, 2, 2};
    println(obj.minimumPairRemoval(v));
}

/*
Problem: Minimum Pair Removal to Sort Array I
*/