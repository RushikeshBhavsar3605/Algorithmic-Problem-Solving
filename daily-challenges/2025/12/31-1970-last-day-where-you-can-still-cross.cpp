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

/* Approach 1 (Binary Search on Answers): */
class Solution {
  public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        vvi mat(row, vi(col, 0));
        vvi vis(row, vi(col, 0));

        function<bool(int, int)> dfs = [&](int currRow, int currCol) {
            if (currRow == row)
                return true;

            if (currRow < 0 || currCol < 0 || currCol == col || vis[currRow][currCol] || mat[currRow][currCol])
                return false;

            vis[currRow][currCol] = 1;
            bool up = dfs(currRow - 1, currCol);
            bool down = dfs(currRow + 1, currCol);
            bool left = dfs(currRow, currCol - 1);
            bool right = dfs(currRow, currCol + 1);

            return up || down || left || right;
        };

        function<bool(int)> isValid = [&](int threshold) -> bool {
            loop(i, 0, row)
                fill(all(mat[i]), 0);

            loop(i, 0, threshold) {
                int newRow = cells[i][0] - 1;
                int newCol = cells[i][1] - 1;
                mat[newRow][newCol] = 1;
            }

            loop(i, 0, row)
                fill(all(vis[i]), 0);

            loop(newCol, 0, col)
                if (dfs(0, newCol))
                    return true;

            return false;
        };

        int low = 0, high = sz(cells) - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (isValid(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
    println(obj.latestDayToCross(2, 2, v));
    v = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    println(obj.latestDayToCross(2, 2, v));
    v = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};
    println(obj.latestDayToCross(3, 3, v));
}

/*
Problem: Last Day Where You Can Still Cross
*/