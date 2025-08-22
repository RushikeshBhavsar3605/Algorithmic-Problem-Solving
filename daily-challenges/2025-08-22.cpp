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

/* Approach 1 (Naive): */
class Solution {
  public:
    int minimumArea(vector<vector<int>> &grid) {
        int n = sz(grid);
        int m = sz(grid[0]);

        int left = m, right = 0;
        int top = n, bottom = 0;

        loop(row, 0, sz(grid))
            loop(col, 0, sz(grid[0]))
                if (grid[row][col]) {
                    updateMin(left, col);
                    updateMax(right, col);

                    updateMin(top, row);
                    updateMax(bottom, row);
                }

        return (right - left + 1) * (bottom - top + 1);
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, 0}, {1, 0, 1}};
    cout << obj.minimumArea(v) << endl;
    return 0;
}

/*
Problem: Find the Minimum Area to Cover All Ones I
*/