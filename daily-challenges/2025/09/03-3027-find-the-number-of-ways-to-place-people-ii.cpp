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

class Solution {
  public:
    int numberOfPairs(vector<vector<int>> &points) {
        int result = 0;
        sort(all(points), [](const vi &a, const vi &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        loop(i, 0, sz(points) - 1) {
            const auto &pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = pointA[1] + 1;

            loop(j, i + 1, sz(points)) {
                const auto &pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin && pointB[1] < yMax) {
                    result++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1}, {2, 2}, {3, 3}};
    cout << obj.numberOfPairs(v) << endl;
    v = {{6, 2}, {4, 4}, {2, 6}};
    cout << obj.numberOfPairs(v) << endl;
    v = {{3, 1}, {1, 3}, {1, 1}};
    cout << obj.numberOfPairs(v) << endl;
}

/*
Problem: Find the Number of Ways to Place People II
*/