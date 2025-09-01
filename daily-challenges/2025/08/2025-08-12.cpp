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

/* Approach 1 (Recursion + Memoization):
class Solution {
  private:
    int MOD = 1e9 + 7;
    int solve(int num, int target, int power, vvi &memo, int sum = 0) {
        if (memo[num][sum] != -1)
            return memo[num][sum];

        if (sum == target)
            return 1;

        if (num <= 0)
            return 0;

        int total = 0;
        revloop(i, num, 1)
            if (sum + pow(i, power) <= target)
                total = (total + solve(i - 1, target, power, memo, sum + pow(i, power))) % MOD;

        return memo[num][sum] = total;
    }

  public:
    int numberOfWays(int n, int x) {
        vvi memo(n + 1, vi(n + 1, -1));
        return solve(n, n, x, memo);
    }
};
*/

/* Approach 2 (Precompute power):
class Solution {
  private:
    int MOD = 1e9 + 7;
    vector<ll> pows;

    void precompute(int n, int power) {
        pows.resize(n + 1);
        loop(i, 1, n + 1)
            pows[i] = pow(i, power);
    }

    int solve(int num, int target, int power, vvi &memo, int sum = 0) {
        if (memo[num][sum] != -1)
            return memo[num][sum];

        if (sum == target)
            return 1;

        if (num <= 0)
            return 0;

        int total = 0;
        revloop(i, num, 1)
            if (sum + pows[i] <= target)
                total = (total + solve(i - 1, target, power, memo, sum + pows[i])) % MOD;

        return memo[num][sum] = total;
    }

  public:
    int numberOfWays(int n, int x) {
        vvi memo(n + 1, vi(n + 1, -1));
        precompute(n, x);

        return solve(n, n, x, memo);
    }
};
*/

/* Approach 3 (Optimized via discarding not needed loop): */
class Solution {
  private:
    int MOD = 1e9 + 7;
    vector<ll> pows;

    void precompute(int n, int power) {
        pows.resize(n + 1);
        loop(i, 1, n + 1)
            pows[i] = pow(i, power);
    }

    int solve(int num, int target, int power, vvi &memo, int sum = 0) {
        if (memo[num][sum] != -1)
            return memo[num][sum];

        if (sum == target)
            return 1;

        if (num <= 0)
            return 0;

        int take = 0;
        if (sum + pows[num] <= target)
            take = solve(num - 1, target, power, memo, sum + pows[num]) % MOD;

        int skip = solve(num - 1, target, power, memo, sum);

        return memo[num][sum] = (take + skip) % MOD;
    }

  public:
    int numberOfWays(int n, int x) {
        vvi memo(n + 1, vi(n + 1, -1));
        precompute(n, x);

        return solve(n, n, x, memo);
    }
};

int main() {
    Solution obj;
    cout << obj.numberOfWays(10, 2) << endl;
    return 0;
}

/*
Problem: Ways to Express an Integer as Sum of Powers
*/