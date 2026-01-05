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
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        ll sum = 0;
        int mini = INT_MAX;
        int negCount = 0;

        iterate(it, matrix)
            iterate(i, it) {
                sum += abs(i);
                updateMin(mini, abs(i));
                if (i <= 0)
                    negCount++;
            }

        if (negCount & 1)
            return sum - (2 * mini);
        else
            return sum;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, -1}, {-1, 1}};
    println(obj.maxMatrixSum(v));
    v = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    println(obj.maxMatrixSum(v));
    v = {{-1, 0, -1}, {-2, 1, 3}, {3, 2, 2}};
    println(obj.maxMatrixSum(v));
    v = {{2, 9, 3}, {5, 4, -4}, {1, 7, 1}};
    println(obj.maxMatrixSum(v));
}

/*
Problem: Maximum Matrix Sum
*/