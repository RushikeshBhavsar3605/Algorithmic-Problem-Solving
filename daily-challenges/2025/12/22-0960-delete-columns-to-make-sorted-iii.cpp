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

/* Approach 1 (Memoization):
    Goal: keep maximum number of columns such that rows stay non-decreasing.
    Answer = total columns - max kept columns.
class Solution {
  private:
    // Checks if column `curr` can come after column `prev`
    // i.e., for every row: strs[row][prev] <= strs[row][curr]
    bool compare(vector<string> &strs, int prev, int curr, int n) {
        iterate(s, strs)
            if (s[prev] > s[curr])
                return false;

        return true;
    }

    // solve(prev, curr):
    // max columns we can keep from [curr .. m-1]
    // given last chosen column is `prev`
    // prev = -1 means no column chosen yet
    int solve(vector<string> &strs, int n, int m, int prev, int curr, vvi &memo) {
        if (curr == m)
            return 0; // no columns left
        if (memo[prev + 1][curr] != -1)
            return memo[prev + 1][curr];

        int include = 0;
        // include curr if it's valid w.r.t previous column
        if (prev == -1 || compare(strs, prev, curr, n))
            include = solve(strs, n, m, curr, curr + 1, memo) + 1;

        // skip curr
        int exclude = solve(strs, n, m, prev, curr + 1, memo);

        return memo[prev + 1][curr] = max(include, exclude);
    }

  public:
    int minDeletionSize(vector<string> &strs) {
        int n = sz(strs);
        int m = sz(strs[0]);

        // prev ∈ [-1..m-1] mapped to [0..m]
        vvi memo(m, vi(m, -1));

        int maxKeep = solve(strs, n, m, -1, 0, memo);
        return m - maxKeep;
    }
};
*/

/* Approach 2 (Tabulation):
    Same DP as memoization, but filled bottom-up.

    dp[prev][curr]:
    max columns we can keep from [curr .. m-1]
    where `prev` is the last chosen column.

    prev == m is a sentinel meaning:
   "no column chosen yet"
*/
class Solution {
  private:
    // Same column comparison as memo version
    bool compare(vector<string> &strs, int prev, int curr) {
        iterate(s, strs)
            if (s[prev] > s[curr])
                return false;

        return true;
    }

  public:
    int minDeletionSize(vector<string> &strs) {
        int n = sz(strs);
        int m = sz(strs[0]);

        // prev ∈ [0..m], curr ∈ [0..m]
        // prev == m → no previous column chosen
        vvi dp(m + 1, vi(m + 1, 0));

        // curr depends on curr+1 → fill backwards
        revloop(curr, m - 1, 0) {
            loop(prev, 0, m + 1) {
                int include = 0;

                // include curr if:
                // - no previous column (prev == m), or
                // - curr is valid after prev
                if (compare(strs, prev, curr))
                    include = dp[curr][curr + 1] + 1;

                // skip curr
                int exclude = dp[prev][curr + 1];

                dp[prev][curr] = max(include, exclude);
            }
        }

        // start with no previous column
        int maxKeep = dp[m][0];
        return m - maxKeep;
    }
};

int main() {
    Solution obj;
    vector<string> v = {"babca", "bbazb"};
    println(obj.minDeletionSize(v));
    v = {"edcba"};
    println(obj.minDeletionSize(v));
    v = {"ghi", "def", "abc"};
    println(obj.minDeletionSize(v));
}

/*
Problem: Delete Columns to Make Sorted III
*/