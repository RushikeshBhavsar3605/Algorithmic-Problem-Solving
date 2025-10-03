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
    int trapRainWater(vector<vector<int>> &heightMap) {
        int n = sz(heightMap);
        int m = sz(heightMap[0]);

        int result = 0;
        loop(row, 0, n) {
            loop(col, 0, m) {
                int left = 0, right = 0, top = 0, bottom = 0;

                revloop(i, col - 1, 0)
                    updateMax(left, heightMap[row][i]);

                loop(i, col + 1, m)
                    updateMax(right, heightMap[row][i]);

                revloop(i, row - 1, 0)
                    updateMax(top, heightMap[i][col]);

                loop(i, row + 1, n)
                    updateMax(bottom, heightMap[i][col]);

                int minBound = min({left, right, top, bottom});

                if (minBound < heightMap[row][col])
                    continue;

                result += minBound - heightMap[row][col];
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    // vvi v = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    // println(obj.trapRainWater(v));
    // v = {{3, 3, 3, 3, 3}, {3, 2, 2, 2, 3}, {3, 2, 1, 2, 3}, {3, 2, 2, 2, 3}, {3, 3, 3, 3, 3}};
    // println(obj.trapRainWater(v));
    vvi v={{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    println(obj.trapRainWater(v));
}

/*
Problem: Trapping Rain Water II
*/
/*
12 13 01 12
13 04 13 12
13 08 10 12
12 13 12 12
13 13 13 13
*/