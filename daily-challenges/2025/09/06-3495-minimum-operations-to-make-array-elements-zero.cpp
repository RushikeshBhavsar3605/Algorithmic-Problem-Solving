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

/* Approach 1 (Math): */
class Solution {
  private:
    ll solve(int left, int right) {
        ll currLeft = 1;
        ll power = 1;
        ll steps = 0;

        while (currLeft <= right) {
            ll currRight = 4 * currLeft - 1;

            ll start = max(currLeft, (ll)left);
            ll end = min(currRight, (ll)right);

            if (start <= end)
                steps += (end - start + 1) * power;

            power++;
            currLeft = currLeft * 4;
        }

        return steps;
    }

  public:
    long long minOperations(vector<vector<int>> &queries) {
        ll result = 0;
        iterate(query, queries) {
            int left = query[0];
            int right = query[1];

            ll steps = solve(left, right);

            result += (steps + 1) / 2;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2}, {2, 4}};
    cout << obj.minOperations(v) << endl;
    v = {{2, 6}};
    cout << obj.minOperations(v) << endl;
}

/*
Problem: Minimum Operations to Make Array Elements Zero
*/