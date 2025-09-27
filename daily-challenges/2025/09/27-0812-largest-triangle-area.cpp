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

/* Approach 1 (Naive): */
class Solution {
  public:
    double largestTriangleArea(vector<vector<int>> &points) {
        int result = 0;
        int n = sz(points);

        loop(i, 0, n)
        loop(j, i + 1, n)
        loop(k, j + 1, n) {
            int x1 = points[i][0];
            int x2 = points[j][0];
            int x3 = points[k][0];

            int y1 = points[i][1];
            int y2 = points[j][1];
            int y3 = points[k][1];

            int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

            updateMax(result, abs(area));
        }

        return result * 1.0 / 2.0;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    cout << obj.largestTriangleArea(v) << endl;
    v = {{1, 0}, {0, 0}, {0, 1}};
    cout << obj.largestTriangleArea(v) << endl;
}

/*
Problem: Largest Triangle Area
*/