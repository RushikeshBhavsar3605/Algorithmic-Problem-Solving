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

/* Approach 1 (Breadth First Search): */
class Solution {
  public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        if (grid[0][0] == 1)
            return -1;

        int n = sz(grid);

        vvi vis(n, vi(n, 0));
        vi directRow = {-1, -1, 0, 1, 1, 1, 0, -1};
        vi directCol = {0, 1, 1, 1, 0, -1, -1, -1};

        queue<pii> q;
        q.push({0, 0});

        int count = 0;
        while (!q.empty()) {
            count++;

            int lengthQueue = sz(q);

            while (lengthQueue--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row == n - 1 && col == n - 1)
                    return count;

                loop(i, 0, 8) {
                    int newRow = row + directRow[i];
                    int newCol = col + directCol[i];

                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n)
                        continue;

                    if (!vis[newRow][newCol] && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        vis[newRow][newCol] = 1;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1}, {1, 0}};
    cout << obj.shortestPathBinaryMatrix(v) << endl;
    v = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << obj.shortestPathBinaryMatrix(v) << endl;
    v = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << obj.shortestPathBinaryMatrix(v) << endl;
}

/*
Problem: Shortest Path in Binary Matrix
*/