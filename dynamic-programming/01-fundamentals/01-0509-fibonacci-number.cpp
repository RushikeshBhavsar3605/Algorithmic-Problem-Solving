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

/* Approach 1 (Naive):
class Solution {
  public:
    int fib(int n) {
        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int n, vi &memo) {
        if (n <= 1)
            return n;

        if (memo[n] != -1)
            return memo[n];

        return memo[n] = fib(n - 1) + fib(n - 2);
    }

  public:
    int fib(int n) {
        vi memo(n + 1, -1);
        return solve(n, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int fib(int n) {
        if (n <= 1)
            return n;

        vi dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        loop(i, 2, n + 1)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int prev2 = 0;
        int prev1 = 1;

        loop(i, 2, n + 1) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    Solution obj;
    println(obj.fib(2));
    println(obj.fib(3));
    println(obj.fib(4));
}

/*
Problem: Fibonacci Number
*/