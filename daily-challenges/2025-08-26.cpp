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
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
        int area = -1;
        double maxi = -1;

        iterate(it, dimensions) {
            double curr = sqrt((it[0] * it[0]) + (it[1] * it[1]));

            if (curr > maxi) {
                area = it[0] * it[1];
                maxi = curr;
            } else if (curr == maxi)
                updateMax(area, it[0] * it[1]);
        }

        return area;
    }
};

int main() {
    Solution obj;
    vvi v = {{9, 3}, {8, 6}};
    cout << obj.areaOfMaxDiagonal(v) << endl;
    v = {{3, 4}, {4, 3}};
    cout << obj.areaOfMaxDiagonal(v) << endl;
    v = {{10, 3}, {5, 9}, {8, 3}};
    cout << obj.areaOfMaxDiagonal(v) << endl;
}

/*
Problem: Maximum Area of Longest Diagonal Rectangle
*/