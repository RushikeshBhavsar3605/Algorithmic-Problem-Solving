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

/* Approach 1 (Memoization): */
class Solution {
  public:
    long long maximumProfit(vector<int> &prices, int k) {
        int n = sz(prices);
        vector<vector<vector<ll>>> memo(n, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));

        function<ll(int, int, int)> dfs = [&](int i, int j, int state) -> ll {
            if (j == 0)
                return 0;
            if (i == 0)
                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);

            if (memo[i][j][state] != -1)
                return memo[i][j][state];

            int p = prices[i];
            ll res;
            if (state == 0)
                res = max(dfs(i - 1, j, 0), max(dfs(i - 1, j, 1) + p, dfs(i - 1, j, 2) - p));
            else if (state == 1)
                res = max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - p);
            else
                res = max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + p);

            return memo[i][j][state] = res;
        };

        return dfs(n - 1, k, 0);
    }
};

int main() {
    Solution obj;
    vi v = {1, 7, 9, 8, 2};
    println(obj.maximumProfit(v, 2));
    v = {12, 16, 19, 19, 8, 1, 19, 13, 9};
    println(obj.maximumProfit(v, 3));
}

/*
Problem: Best Time to Buy and Sell Stock V
*/