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
    int findFinalValue(vector<int> &nums, int original) {
        while (true) {
            bool isFound = false;
            iterate(it, nums) if (it == original) {
                original *= 2;
                isFound = true;
            }

            if (!isFound)
                return original;
        }

        return -1;
    }
};
*/

/* Approach 2 (Sorting):
class Solution {
  public:
    int findFinalValue(vector<int> &nums, int original) {
        sort(all(nums));
        iterate(it, nums)
            if (it == original)
                original *= 2;

        return original;
    }
};
*/

/* Approach 3 (Hashing): */
class Solution {
  public:
    int findFinalValue(vector<int> &nums, int original) {
        uset<int> st(all(nums));
        while (st.count(original))
            original *= 2;

        return original;
    }
};

int main() {
    Solution obj;
    vi v = {5, 3, 6, 1, 12};
    println(obj.findFinalValue(v, 3));
    v = {2, 7, 9};
    println(obj.findFinalValue(v, 4));
}

/*
Problem: Keep Multiplying Found Values by Two
*/