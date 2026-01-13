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

/* Approach 1 (Binary Search): */
class Solution {
  public:
    double separateSquares(vector<vector<int>> &squares) {
        double maxY = 0, totalArea = 0;
        iterate(sq, squares) {
            int y = sq[1], l = sq[2];
            totalArea += (double)l * l;
            updateMax(maxY, (double)(y + l));
        }

        auto check = [&](double limitY) -> bool {
            double area = 0;
            iterate(sq, squares) {
                int y = sq[1], l = sq[2];
                if (y < limitY)
                    area += l * min(limitY - y, (double)l);
            }

            return area >= totalArea / 2;
        };

        double low = 0, high = maxY;
        double eps = 1e-5;
        while (abs(high - low) > eps) {
            double mid = low + (high - low) / 2.0;
            if (check(mid))
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 0, 1}, {2, 2, 1}};
    println(obj.separateSquares(v));
    v = {{0, 0, 2}, {1, 1, 1}};
    println(obj.separateSquares(v));
}

/*
Problem: Separate Squares I
*/