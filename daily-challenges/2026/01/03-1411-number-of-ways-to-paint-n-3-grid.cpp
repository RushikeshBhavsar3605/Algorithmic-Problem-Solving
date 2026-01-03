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
    int numOfWays(int n) {
        vvi colors = {{1, 2, 3}, {1, 2, 1}, {1, 3, 2}, {1, 3, 1}, {2, 1, 3}, {2, 1, 2},
                      {2, 3, 1}, {2, 3, 2}, {3, 2, 1}, {3, 1, 2}, {3, 2, 3}, {3, 1, 3}};
        int MOD = 1e9 + 7;
        vvi memo(n, vi(12, -1));

        function<int(int, int)> solve = [&](int n, int prev) -> int {
            if (n == 0)
                return 1;

            if (memo[n][prev] != -1)
                return memo[n][prev];

            int result = 0;
            vi lastColor = colors[prev];
            loop(curr, 0, 12) {
                if (curr == prev)
                    continue;
                bool conflict = false;
                loop(i, 0, 3) if (colors[curr][i] == lastColor[i]) conflict = true;

                if (!conflict)
                    result = (result + solve(n - 1, curr)) % MOD;
            }

            return memo[n][prev] = result;
        };

        int result = 0;
        loop(i, 0, 12)
            result = (result + solve(n - 1, i)) % MOD;

        return result;
    }
};

int main() {
    Solution obj;
    println(obj.numOfWays(1));
    println(obj.numOfWays(2));
}

/*
Problem: Number of Ways to Paint N × 3 Grid
*/