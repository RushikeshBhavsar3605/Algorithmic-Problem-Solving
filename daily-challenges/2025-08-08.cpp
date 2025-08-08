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

class Solution {
  private:
    vector<vector<double>> memo;
    double solve(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        else if (a <= 0)
            return 1.0;
        else if (b <= 0)
            return 0;

        if (memo[a][b] != -1)
            return memo[a][b];

        double p1 = solve(a - 100, b);
        double p2 = solve(a - 75, b - 25);
        double p3 = solve(a - 50, b - 50);
        double p4 = solve(a - 25, b - 75);

        return memo[a][b] = 0.25 * (p1 + p2 + p3 + p4);
    }

  public:
    double soupServings(int n) {
        if (n >= 5000)
            return 1;

        memo.resize(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n);
    }
};

int main() {
    Solution obj;
    cout << obj.soupServings(50);
    return 0;
}

/*
Problem: Soup Servings
*/