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

/* Approach 1 (Greedy + Two Pointer): */
class Solution {
  public:
    long long minMoves(vector<int> &balance) {
        int n = sz(balance);
        ll totalSum = 0;
        int culpritIndex = -1;

        loop(i, 0, sz(balance)) {
            if (balance[i] < 0)
                culpritIndex = i;
            totalSum += balance[i];
        }
        if (totalSum < 0)
            return -1;
        if (culpritIndex == -1)
            return 0;

        ll moves = 0;
        int distance = 1;
        int culprit = balance[culpritIndex];

        while (culprit != 0) {
            int leftIndex = (culpritIndex - distance + n) % n;
            int rightIndex = (culpritIndex + distance) % n;

            ll totalBalance = balance[leftIndex] + balance[rightIndex];
            if (leftIndex == rightIndex)
                totalBalance -= balance[rightIndex];

            ll needed = -culprit;
            ll taken = min(needed, totalBalance);

            moves += taken * distance;
            culprit += taken;

            distance++;
        }

        return moves;
    }
};

int main() {
    Solution obj;
    vi v = {5, 1, -4};
    println(obj.minMoves(v));
    v = {1, 2, -5, 2};
    println(obj.minMoves(v));
    v = {-3, 2};
    println(obj.minMoves(v));
    v = {-2, 4};
    println(obj.minMoves(v));
}

/*
Problem: Minimum Moves to Balance Circular Array
*/