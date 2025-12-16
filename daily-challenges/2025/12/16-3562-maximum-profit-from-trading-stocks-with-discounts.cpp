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

/* Approach 1 (Dynamic Programming): */
class Solution {
  public:
    int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget) {
        vvi g(n);
        iterate(e, hierarchy)
            g[e[0] - 1].pb(e[1] - 1);

        auto dfs = [&](auto &&self, int u) -> tuple<vi, vi, int> {
            int cost = present[u];
            int dCost = present[u] / 2;

            auto dp0 = vector(budget + 1, 0);
            auto dp1 = vector(budget + 1, 0);

            auto subProfit0 = vector(budget + 1, 0);
            auto subProfit1 = vector(budget + 1, 0);

            int uSize = cost;

            iterate(it, g[u]) {
                auto [subDp0, subDp1, vSize] = self(self, it);
                uSize += vSize;
                revloop(i, budget, 0)
                    loop(sub, 0, min(vSize, i) + 1) {
                        updateMax(subProfit0[i], subProfit0[i - sub] + subDp0[sub]);
                        updateMax(subProfit1[i], subProfit1[i - sub] + subDp1[sub]);
                    }
            }

            loop(i, 0, budget + 1) {
                dp0[i] = dp1[i] = subProfit0[i];

                if (i >= dCost)
                    dp1[i] = max(subProfit0[i], subProfit1[i - dCost] + future[u] - dCost);

                if (i >= cost)
                    dp0[i] = max(subProfit0[i], subProfit1[i - cost] + future[u] - cost);
            }

            return {dp0, dp1, uSize};
        };

        return get<0>(dfs(dfs, 0))[budget];
    }
};

int main() {
    Solution obj;
    vi present = {1, 2};
    vi future = {4, 3};
    vvi hierarchy = {{1, 2}};
    println(obj.maxProfit(2, present, future, hierarchy, 3));
    present = {3, 4};
    future = {5, 8};
    hierarchy = {{1, 2}};
    println(obj.maxProfit(2, present, future, hierarchy, 4));
    present = {4, 6, 8};
    future = {7, 9, 11};
    hierarchy = {{1, 2}, {1, 3}};
    println(obj.maxProfit(3, present, future, hierarchy, 10));
    present = {5, 2, 3};
    future = {8, 5, 6};
    hierarchy = {{1, 2}, {2, 3}};
    println(obj.maxProfit(3, present, future, hierarchy, 7));
}

/*
Problem: Maximum Profit from Trading Stocks with Discounts
*/