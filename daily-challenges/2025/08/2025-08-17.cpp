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

/* Approach 1 (Time Limit Exceeded):
class Solution {
  public:
    double new21Game(int n, int k, int maxPts) {
        umap<int, double> cache;
        function<double(int)> dfs = [&](int score) -> double {
            if (score >= k)
                return score <= n ? 1 : 0;

            if (cache.find(score) != cache.end())
                return cache[score];

            double prob = 0;
            loop(i, 1, maxPts + 1)
                prob += dfs(score + i);

            return cache[score] = prob / (double)maxPts;
        };

        return dfs(0);
    }
};
*/

/* Approach 2 (Dynamic Programming): */
class Solution {
  public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0)
            return 1;

        double windowSum = 0;
        loop(i, k, k + maxPts)
            windowSum += (i <= n ? 1 : 0);

        umap<int, double> dp;
        revloop(i, k - 1, 0) {
            dp[i] = windowSum / maxPts;
            double remove = 0;
            if (i + maxPts <= n)
                remove = dp.count(i + maxPts) ? dp[i + maxPts] : 1;

            windowSum += dp[i] - remove;
        }

        return dp[0];
    }
};

int main() {
    Solution obj;
    cout << obj.new21Game(10, 1, 10) << endl;
    return 0;
}

/*
Problem: New 21 Game
*/