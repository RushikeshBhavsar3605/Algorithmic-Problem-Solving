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
    int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
        int result = 0;
        vector<map<int, int>> maxx(n + 1), maxy(n + 1);
        loop(i, 0, sz(buildings)) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            maxx[x][y]++;
            maxy[y][x]++;
        }
        loop(i, 0, sz(buildings)) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            auto it1 = maxx[x].upper_bound(y);
            auto it2 = maxx[x].lower_bound(y);
            auto it3 = maxy[y].upper_bound(x);
            auto it4 = maxy[y].lower_bound(x);

            if (it1 != maxx[x].end() && it2 != maxx[x].begin() && it3 != maxy[y].end() && it4 != maxy[y].begin())
                result++;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
    println(obj.countCoveredBuildings(3, v));
    v = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    println(obj.countCoveredBuildings(3, v));
    v = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    println(obj.countCoveredBuildings(5, v));
}

/*
Problem: Count Covered Buildings
*/