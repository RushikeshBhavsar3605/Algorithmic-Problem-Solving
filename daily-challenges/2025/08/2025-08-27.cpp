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

/* Approach 1 (Recursion): */
class Solution {
  private:
    vvi direction = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n;
    int m;

    int solve(int row, int col, int d, bool canTurn, int val, vvi &grid) {
        int newRow = row + direction[d][0];
        int newCol = col + direction[d][1];

        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != val)
            return 0;

        int keepMoving = solve(newRow, newCol, d, canTurn, val == 2 ? 0 : 2, grid) + 1;

        int turnAndMove = 0;
        if (canTurn)
            turnAndMove = solve(newRow, newCol, (d + 1) % 4, false, val == 2 ? 0 : 2, grid) + 1;

        return max(keepMoving, turnAndMove);
    }

  public:
    int lenOfVDiagonal(vector<vector<int>> &grid) {
        n = sz(grid);
        m = sz(grid[0]);

        int result = 0;

        loop(i, 0, n)
            loop(j, 0, m)
                if (grid[i][j] == 1)
                    loop(d, 0, 4)
                        updateMax(result, solve(i, j, d, true, 2, grid) + 1);

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    cout << obj.lenOfVDiagonal(v) << endl;
    v = {{2, 2, 2, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}};
    cout << obj.lenOfVDiagonal(v) << endl;
}

/*
Problem: Length of Longest V-Shaped Diagonal Segment
*/