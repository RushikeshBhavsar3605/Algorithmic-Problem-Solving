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

/* Approach 1 (Enumeration + Counting): */
class Solution {
  public:
    int specialTriplets(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        umap<int, int> numCnt;
        umap<int, int> numPartialCnt;

        numCnt.reserve(sz(nums) * 2);
        numPartialCnt.reserve(sz(nums) * 2);

        iterate(num, nums)
            numCnt[num]++;

        int result = 0;
        iterate(num, nums) {
            int target = num * 2;
            int lCnt = numPartialCnt[target];
            numPartialCnt[num]++;
            int rCnt = numCnt[target] - numPartialCnt[target];
            result = (result + (lCnt * 1LL * rCnt % MOD)) % MOD;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> v = {6, 3, 6};
    println(obj.specialTriplets(v));
    v = {0, 1, 0, 0};
    println(obj.specialTriplets(v));
    v = {8, 4, 2, 8, 4};
    println(obj.specialTriplets(v));
}

/*
Problem: Count Special Triplets
*/