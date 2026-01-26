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

/* Approach 1 (Sorting + Single Pass): */
class Solution {
  public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        sort(all(arr));
        int mini = INT_MAX;
        vvi result;

        loop(i, 1, sz(arr)) {
            if (abs(arr[i] - arr[i - 1]) < mini) {
                result.clear();
                mini = abs(arr[i] - arr[i - 1]);
            }

            if (abs(arr[i] - arr[i - 1]) == mini)
                result.pb({arr[i - 1], arr[i]});
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {4, 2, 1, 3};
    dump2D(obj.minimumAbsDifference(v));
    v = {1, 3, 6, 10, 15};
    dump2D(obj.minimumAbsDifference(v));
    v = {3, 8, -10, 23, 19, -4, -14, 27};
    dump2D(obj.minimumAbsDifference(v));
}

/*
Problem: Minimum Absolute Difference
*/