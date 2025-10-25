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
    int totalMoney(int n) {
        int result = 0;
        int monday = 1;

        while (n > 0) {
            loop(day, 0, min(n, 7))
                result += monday + day;

            n -= 7;
            monday++;
        }

        return result;
    }
};
*/

/* Approach 2 (Math): */
class Solution {
  public:
    int totalMoney(int n) {
        int result = 0;
        int addOns = 0;

        if (n > 7) {
            addOns = n / 7;
            result = 28 * addOns;
            result += 7 * (((addOns - 1) * addOns) >> 1);
        } else
            addOns = 0;

        loop(i, 1, (n % 7) + 1)
            result += i + addOns;

        return result;
    }
};

int main() {
    Solution obj;
    println(obj.totalMoney(4));
    println(obj.totalMoney(10));
    println(obj.totalMoney(20));
    println(obj.totalMoney(26));
}

/*
Problem: Calculate Money in Leetcode Bank
*/