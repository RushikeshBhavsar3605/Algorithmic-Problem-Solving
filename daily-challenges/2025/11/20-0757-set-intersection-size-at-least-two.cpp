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

/* Approach 1 (Sorting): */
class Solution {
  public:
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        int result = 0;
        int p1 = -1, p2 = -1;

        sort(all(intervals), [](const vi &a, const vi &b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        iterate(it, intervals) {
            int left = it[0];
            int right = it[1];

            if (p2 < left) {
                result += 2;
                p1 = right - 1;
                p2 = right;
            } else if (p1 < left) {
                result += 1;
                p1 = p2;
                p2 = right;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 3}, {3, 7}, {8, 9}};
    println(obj.intersectionSizeTwo(v));
    v = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    println(obj.intersectionSizeTwo(v));
    v = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
    println(obj.intersectionSizeTwo(v));
}

/*
Problem: Set Intersection Size At Least Two
*/