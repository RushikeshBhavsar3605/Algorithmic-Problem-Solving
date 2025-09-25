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

/* Approach 1 (Naive) (TLE):
class Solution {
  private:
    void solve(int row, int col, vvi &triangle, int &mini, int curr = 0) {
        if (row == sz(triangle)) {
            updateMin(mini, curr);
            return;
        }

        curr += triangle[row][col];

        solve(row + 1, col, triangle, mini, curr);
        solve(row + 1, col + 1, triangle, mini, curr);
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int mini = INT_MAX;
        int n = sz(triangle);
        solve(0, 0, triangle, mini);

        return mini;
    }
};
*/

/* Approach 2 (Naive) (TLE):
class Solution {
  private:
    int solve(int row, int col, vvi &triangle) {
        if (row == sz(triangle) - 1)
            return triangle[row][col];

        int bottom = triangle[row][col] + solve(row + 1, col, triangle);
        int diagonal = triangle[row][col] + solve(row + 1, col + 1, triangle);

        return min(bottom, diagonal);
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = sz(triangle);
        return solve(0, 0, triangle);
    }
};
*/

/* Approach 3 (Memoization): */
class Solution {
  private:
    int solve(int row, int col, vvi &triangle, vvi &memo) {
        if (row == sz(triangle) - 1)
            return triangle[row][col];

        if (memo[row][col] != INT_MAX)
            return memo[row][col];

        int bottom = triangle[row][col] + solve(row + 1, col, triangle, memo);
        int diagonal = triangle[row][col] + solve(row + 1, col + 1, triangle, memo);

        return memo[row][col] = min(bottom, diagonal);
    }

  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = sz(triangle);
        vvi memo(n, vi(n, INT_MAX));

        return solve(0, 0, triangle, memo);
    }
};

int main() {
    Solution obj;
    vvi v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << obj.minimumTotal(v) << endl;
    v = {{-10}};
    cout << obj.minimumTotal(v) << endl;
}

/*
Problem: Triangle
*/