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
    int solve(int st, int en, vi &values) {
        if (en - st < 2)
            return 0;

        int minScore = INT_MAX;

        loop(mid, st + 1, en) {
            int score = values[st] * values[mid] * values[en] + solve(st, mid, values) + solve(mid, en, values);

            updateMin(minScore, score);
        }

        return minScore;
    }

  public:
    int minScoreTriangulation(vector<int> &values) { return solve(0, sz(values) - 1, values); }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int st, int en, vi &values, vvi &memo) {
        if (en - st < 2)
            return 0;

        if (memo[st][en] != -1)
            return memo[st][en];

        int minScore = INT_MAX;

        loop(mid, st + 1, en) {
            int score = values[st] * values[mid] * values[en] +
                        solve(st, mid, values, memo) +
                        solve(mid, en, values, memo);

            updateMin(minScore, score);
        }

        return memo[st][en] = minScore;
    }

  public:
    int minScoreTriangulation(vector<int> &values) {
        vvi memo(sz(values), vi(sz(values), -1));
        return solve(0, sz(values) - 1, values, memo);
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    int minScoreTriangulation(vector<int> &values) {
        int n = sz(values);
        vvi dp(n, vi(n, 0));

        revloop(i, n - 1, 0)
            loop(j, i + 2, n) {
                int minScore = INT_MAX;
                loop(k, i + 1, j) {
                    int score = values[i] * values[j] * values[k] + dp[i][k] + dp[k][j];
                    updateMin(minScore, score);
                }

                dp[i][j] = minScore;
            }

        return dp[0][n - 1];
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3};
    cout << obj.minScoreTriangulation(v) << endl;
    v = {3, 7, 4, 5};
    cout << obj.minScoreTriangulation(v) << endl;
}

/*
Problem: Minimum Score Triangulation of Polygon
*/