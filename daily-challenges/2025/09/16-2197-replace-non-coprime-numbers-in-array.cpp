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

/* Approach 1 (Naive): */
class Solution {
  private:
    ll gcd(ll x, ll y) {
        if (y == 0)
            return x;

        return gcd(y, x % y);
    }

  public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        vi result;
        result.pb(nums[0]);

        loop(i, 1, sz(nums)) {
            ll y = nums[i];
            // Merge current element with previous non-coprime elements
            while (sz(result) && gcd(y, result.back()) > 1) {
                ll x = result.back();
                result.pop_back();
                y = (x * y) / gcd(x, y); // Replace with LCM
            }

            result.pb(y);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {6, 4, 3, 2, 7, 6, 2};
    dump(obj.replaceNonCoprimes(v));
    v = {2, 2, 1, 1, 3, 3, 3};
    dump(obj.replaceNonCoprimes(v));
}

/*
Problem: Replace Non-Coprime Numbers in Array
*/