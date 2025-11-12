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

/* Approach 1 (Math): */
class Solution {
  public:
    int minOperations(vector<int> &nums) {
        int oneCount = count(all(nums), 1);
        if (oneCount > 0)
            return sz(nums) - oneCount;

        auto gcd = [&](int a, int b) -> int {
            while (a && b) {
                a = a % b;
                swap(a, b);
            }

            return max(a, b);
        };

        int minSubLen = INT_MAX;

        loop(left, 0, sz(nums)) {
            int curr_gcd = 0;

            loop(right, left, sz(nums)) {
                if (right - left + 1 >= minSubLen)
                    break;

                curr_gcd = gcd(curr_gcd, nums[right]);
                if (curr_gcd == 1) {
                    updateMin(minSubLen, right - left + 1);
                    break;
                }
            }
        }

        if (minSubLen == INT_MAX)
            return -1;

        return (minSubLen - 1) + sz(nums) - 1;
    }
};

int main() {
    Solution obj;
    vi v = {2, 6, 3, 4};
    println(obj.minOperations(v));
    v = {2, 10, 6, 14};
    println(obj.minOperations(v));
}

/*
Problem: Minimum Number of Operations to Make All Array Elements Equal to 1
*/