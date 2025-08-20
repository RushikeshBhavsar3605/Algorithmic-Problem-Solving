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

/* Approach 1 (Summation): */
class Solution {
  public:
    int countSquares(vector<vector<int>> &matrix) {
        int maxRow = sz(matrix);
        int maxCol = sz(matrix[0]);

        revloop(row, maxRow - 2, 0)
            revloop(col, maxCol - 2, 0) {
                if (matrix[row][col] == 0)
                    continue;

                int right = matrix[row][col + 1];
                int diagonal = matrix[row + 1][col + 1];
                int bottom = matrix[row + 1][col];

                matrix[row][col] = min({right, diagonal, bottom}) + 1;
            }

        int count = 0;
        iterate(it, matrix)
            iterate(i, it)
                count += i;

        return count;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << obj.countSquares(v) << endl;
    return 0;
}

/*
Problem: Count Square Submatrices with All Ones
*/

/*
0 1 1 1
1 1 1 1
0 1 1 1

0 3 2 1
1 2 2 1
0 1 1 1
*/