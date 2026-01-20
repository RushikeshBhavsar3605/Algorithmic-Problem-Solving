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

class Solution {
  public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars) {
        sort(all(hBars));
        sort(all(vBars));
        int hmax = 1, vmax = 1;
        int hcurr = 1, vcurr = 1;

        loop(i, 1, sz(hBars)) {
            if (hBars[i] == hBars[i - 1] + 1)
                hcurr++;
            else
                hcurr = 1;
            updateMax(hmax, hcurr);
        }

        loop(i, 1, sz(vBars)) {
            if (vBars[i] == vBars[i - 1] + 1)
                vcurr++;
            else
                vcurr = 1;
            updateMax(vmax, vcurr);
        }

        int side = min(hmax, vmax) + 1;
        return side * side;
    }
};

int main() {
    Solution obj;
    vi v1 = {2, 3};
    vi v2 = {2};
    println(obj.maximizeSquareHoleArea(2, 1, v1, v2));
    v1 = {2};
    v2 = {2};
    println(obj.maximizeSquareHoleArea(1, 1, v1, v2));
    v1 = {2, 3};
    v2 = {2, 4};
    println(obj.maximizeSquareHoleArea(2, 3, v1, v2));
}

/*
Problem: Maximize Area of Square Hole in Grid
*/