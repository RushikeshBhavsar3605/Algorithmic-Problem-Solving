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

/* Approach 1 (2D Difference + Prefix Sum):
class Solution {
  public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vvi diff(n, vi(n, 0));

        // Mark range boundaries in difference array
        iterate(query, queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];

            loop(row, row1, row2 + 1) {
                diff[row][col1] += 1; // Mark range start
                if (col2 < n - 1)
                    diff[row][col2 + 1] -= 1; // Mark range end
            }
        }

        // Convert difference array to actual values via prefix sum
        loop(row, 0, n)
            loop(col, 1, n)
                diff[row][col] += diff[row][col - 1];

        return diff;
    }
};
*/

/* Approach 2 (Optimized 2D Difference): */
class Solution {
  public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries) {
        vvi diff(n + 1, vi(n + 1, 0)); // Extra row/col for boundary handling

        // Mark rectangle corners in 2D difference array
        iterate(query, queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];

            diff[row1][col1] += 1;         // Top-left: start both dimensions
            diff[row1][col2 + 1] -= 1;     // Top-right: end column
            diff[row2 + 1][col1] -= 1;     // Bottom-left: end row
            diff[row2 + 1][col2 + 1] += 1; // Bottom-right: end both dimensions
        }

        vvi mat(n, vi(n, 0));
        // Apply 2D prefix sum to materialize final values
        loop(row, 0, n) {
            loop(col, 0, n) {
                int x1 = (row == 0) ? 0 : mat[row - 1][col]; // Top cell
                int x2 = (col == 0) ? 0 : mat[row][col - 1]; // Left cell
                int x3 =
                    (row == 0 || col == 0) ? 0 : mat[row - 1][col - 1]; // Diagonal (subtract to avoid double-counting)

                mat[row][col] = diff[row][col] + x1 + x2 - x3;
            }
        }

        return mat;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    dump2D(obj.rangeAddQueries(3, v));
    v = {{
        0,
        0,
        1,
        1,
    }};
    dump2D(obj.rangeAddQueries(2, v));
}

/*
Problem: Increment Submatrices by One
*/