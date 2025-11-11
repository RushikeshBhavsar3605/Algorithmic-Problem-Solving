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

/* Approach 1 (Recursion):
class Solution {
  private:
    pii compute(string &s) {
        int zeros = 0, ones = 0;
        iterate(it, s) {
            if (it == '0')
                zeros++;
            else
                ones++;
        }

        return {zeros, ones};
    }
    int solve(int idx, vector<string> &strs, int m, int n) {
        if (idx == sz(strs))
            return 0;

        pii count = compute(strs[idx]);
        int take = INT_MIN;
        if (m >= count.ff && n >= count.ss)
            take = solve(idx + 1, strs, m - count.ff, n - count.ss) + 1;
        int notTake = solve(idx + 1, strs, m, n);

        return max(take, notTake);
    }

  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        return solve(0, strs, m, n);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    pii compute(string &s) {
        int zeros = 0, ones = 0;
        iterate(it, s) {
            if (it == '0')
                zeros++;
            else
                ones++;
        }

        return {zeros, ones};
    }

    int solve(int idx, vector<string> &strs, int m, int n, vector<vvi> &memo) {
        if (idx == sz(strs))
            return 0;

        if (memo[idx][m][n] != -1)
            return memo[idx][m][n];

        pii count = compute(strs[idx]);
        int take = INT_MIN;
        if (m >= count.ff && n >= count.ss)
            take = solve(idx + 1, strs, m - count.ff, n - count.ss, memo) + 1;
        int notTake = solve(idx + 1, strs, m, n, memo);

        return memo[idx][m][n] = max(take, notTake);
    }

  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vvi> memo(sz(strs), vvi(m + 1, vi(n + 1, -1)));
        return solve(0, strs, m, n, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<pii> count(sz(strs));
        loop(i, 0, sz(strs)) {
            int zeros = 0, ones = 0;
            iterate(it, strs[i]) {
                if (it == '0')
                    zeros++;
                else
                    ones++;
            }
            count[i] = {zeros, ones};
        }

        vector<vvi> dp(sz(strs) + 1, vvi(m + 1, vi(n + 1, 0)));
        loop(i, 1, sz(strs) + 1) {
            int zeros = count[i - 1].ff, ones = count[i - 1].ss;
            loop(j, 0, m + 1) {
                loop(k, 0, n + 1) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones)
                        updateMax(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                }
            }
        }

        return dp[sz(strs)][m][n];
    }
};
*/

/* Approach 4 (Space Optimization):
class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<pii> count(sz(strs));
        loop(i, 0, sz(strs)) {
            int zeros = 0, ones = 0;
            iterate(it, strs[i]) {
                if (it == '0')
                    zeros++;
                else
                    ones++;
            }
            count[i] = {zeros, ones};
        }

        vvi prev(m + 1, vi(n + 1, 0));

        loop(i, 1, sz(strs) + 1) {
            vvi curr(m + 1, vi(n + 1, 0));
            int zeros = count[i - 1].ff, ones = count[i - 1].ss;

            loop(j, 0, m + 1) {
                loop(k, 0, n + 1) {
                    curr[j][k] = prev[j][k];
                    if (j >= zeros && k >= ones)
                        updateMax(curr[j][k], prev[j - zeros][k - ones] + 1);
                }
            }

            prev = curr;
        }

        return prev[m][n];
    }
};
*/

/* Approach 5 (Most Optimal): */
class Solution {
  public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vvi dp(m + 1, vi(n + 1, 0));

        iterate(it, strs) {
            int zeros = count(all(it), '0');
            int ones = sz(it) - zeros;

            revloop(j, m, zeros)
                revloop(k, n, ones)
                    updateMax(dp[j][k], dp[j - zeros][k - ones] + 1);
        }

        return dp[m][n];
    }
};

int main() {
    Solution obj;
    vector<string> v = {"10", "0001", "111001", "1", "0"};
    println(obj.findMaxForm(v, 5, 3));
    v = {"10", "0", "1"};
    println(obj.findMaxForm(v, 1, 1));
}

/*
Problem: Ones and Zeroes
*/