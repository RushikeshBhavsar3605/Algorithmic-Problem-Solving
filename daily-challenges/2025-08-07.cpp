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

class Solution {
  private:
    int n;
    vvi dp1;
    vvi dp2;

    int solveBottomLeft(int row, int col, vvi &fruits) {
        if (row == n - 1 && col == n - 1)
            return 0;
        if (col >= row)
            return 0;
        if (dp1[row][col] != -1)
            return dp1[row][col];

        int maxFruits = 0;
        int collectedFruits = fruits[row][col];

        if (row - 1 >= 0)
            updateMax(maxFruits, collectedFruits + solveBottomLeft(row - 1, col + 1, fruits));
        if (col + 1 < n)
            updateMax(maxFruits, collectedFruits + solveBottomLeft(row, col + 1, fruits));
        if (row + 1 < n)
            updateMax(maxFruits, collectedFruits + solveBottomLeft(row + 1, col + 1, fruits));

        return dp1[row][col] = maxFruits;
    }

    int solveTopRight(int row, int col, vvi &fruits) {
        if (row == n - 1 && col == n - 1)
            return 0;
        if (row >= col)
            return 0;
        if (dp2[row][col] != -1)
            return dp2[row][col];

        int maxFruits = 0;
        int collectedFruits = fruits[row][col];

        if (col - 1 >= 0)
            updateMax(maxFruits, collectedFruits + solveTopRight(row + 1, col - 1, fruits));
        if (row + 1 < n)
            updateMax(maxFruits, collectedFruits + solveTopRight(row + 1, col, fruits));
        if (col + 1 < n)
            updateMax(maxFruits, collectedFruits + solveTopRight(row + 1, col + 1, fruits));

        return dp2[row][col] = maxFruits;
    }

  public:
    int maxCollectedFruits(vector<vector<int>> &fruits) {
        n = sz(fruits);
        dp1.resize(n, vi(n, -1));
        dp2.resize(n, vi(n, -1));

        int totalFruits = 0;
        loop(i, 0, n)
            totalFruits += fruits[i][i];

        totalFruits += solveBottomLeft(n - 1, 0, fruits);
        totalFruits += solveTopRight(0, n - 1, fruits);

        return totalFruits;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    cout << obj.maxCollectedFruits(v);
    return 0;
}

/*
Problem: Find the Maximum Number of Fruits Collected
*/