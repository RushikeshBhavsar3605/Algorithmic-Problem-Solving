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
    int solve(int idx, vi &energy, int k) {
        if (idx < 0)
            return 0;

        return max(energy[idx], energy[idx] + solve(idx - k, energy, k));
    }

  public:
    int maximumEnergy(vector<int> &energy, int k) {
        int n = sz(energy);
        int result = INT_MIN;

        loop(i, n - k, n)
            updateMax(result, solve(i, energy, k));

        return result;
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, vi &energy, int k, vi &memo) {
        if (idx < 0)
            return 0;

        if (memo[idx] != INT_MIN)
            return memo[idx];

        int result = max(energy[idx], energy[idx] + solve(idx - k, energy, k, memo));

        return memo[idx] = result;
    }

  public:
    int maximumEnergy(vector<int> &energy, int k) {
        int n = sz(energy);
        vi memo(n, INT_MIN);

        int result = INT_MIN;
        loop(i, n - k, n)
            updateMax(result, solve(i, energy, k, memo));

        return result;
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int maximumEnergy(vector<int> &energy, int k) {
        int n = sz(energy);

        vi dp(n);
        loop(i, 0, n) {
            dp[i] = energy[i];
            if (i >= k)
                updateMax(dp[i], dp[i] + dp[i - k]);
        }

        int result = INT_MIN;
        loop(i, n - k, n)
            updateMax(result, dp[i]);

        return result;
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int maximumEnergy(vector<int> &energy, int k) {
        int n = sz(energy);

        vi dp(k);
        loop(i, 0, n) {
            int idx = i % k;

            if (i >= k)
                dp[idx] = max(energy[i], energy[i] + dp[idx]);
            else
                dp[idx] = energy[i];
        }

        int result = INT_MIN;
        iterate(it, dp)
            updateMax(result, it);

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {5, 2, -10, -5, 1};
    println(obj.maximumEnergy(v, 3));
    v = {-2, -3, -1};
    println(obj.maximumEnergy(v, 2));
    v = {1, -3, 10, 7};
    println(obj.maximumEnergy(v, 1));
}

/*
Problem: Taking Maximum Energy From the Mystic Dungeon
*/