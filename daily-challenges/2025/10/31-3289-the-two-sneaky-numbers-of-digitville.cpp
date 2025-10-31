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
  public:
    vector<int> getSneakyNumbers(vector<int> &nums) {
        umap<int, int> mp;
        iterate(it, nums)
            mp[it]++;

        vi result;
        iterate(it, mp)
            if (it.ss == 2)
                result.pb(it.ff);

        return result;
    }
};
*/

/* Approach 2 (Bit Manipulation): */
class Solution {
  public:
    vector<int> getSneakyNumbers(vector<int> &nums) {
        int XOR = 0;
        int n = sz(nums) - 2;

        iterate(num, nums) XOR ^= num;
        loop(i, 0, n) XOR ^= i;

        int diffBit = XOR & -XOR;

        int a = 0, b = 0;
        iterate(num, nums) {
            if ((num & diffBit) == 0)
                a ^= num;
            else
                b ^= num;
        }
        loop(i, 0, n) {
            if ((i & diffBit) == 0)
                a ^= i;
            else
                b ^= i;
        }

        return {a, b};
    }
};

int main() {
    Solution obj;
    vi v = {0, 1, 1, 0};
    dump(obj.getSneakyNumbers(v));
    v = {0, 3, 2, 1, 3, 2};
    dump(obj.getSneakyNumbers(v));
    v = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    dump(obj.getSneakyNumbers(v));
}

/*
Problem: The Two Sneaky Numbers of Digitville
*/