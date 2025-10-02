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

/* Approach 1 (Sliding Window): */
class Solution {
  public:
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
        int n = sz(prices);

        // base = profit from applying given strategy
        ll base = 0;
        loop(i, 0, n)
            base += prices[i] * strategy[i];
        ll result = base;

        // remove first k strategy values from base
        ll slide = 0;
        loop(i, 0, k)
            base -= prices[i] * strategy[i];

        // slide = sum of last k/2 prices in the first window
        loop(i, k / 2, k)
            slide += prices[i];

        updateMax(result, base + slide);

        // sliding window over [k..n)
        loop(i, k, n) {
            // shift window: remove current, add dropped element back
            base -= prices[i] * strategy[i];
            base += prices[i - k] * strategy[i - k];

            // maintain sliding sum of last k/2 prices in window
            slide -= prices[i - k / 2];
            slide += prices[i];

            updateMax(result, base + slide);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v1 = {4, 2, 8};
    vi v2 = {-1, 0, 1};
    cout << obj.maxProfit(v1, v2, 2) << endl;
}

/*
Problem: Best Time to Buy and Sell Stock using Strategy
*/