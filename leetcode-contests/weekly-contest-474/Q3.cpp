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

class Solution {
    private:
    ll lcm (ll a,ll b){
        ll g =a/gcd(a,b)*b;
        return g;
    }

    bool feasible(ll T)
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        auto lcm_ll = [](long long a, long long b) -> long long {
        return a / std::gcd(a, b) * b;
    };

    auto feasible = [&](long long T) -> bool {
        if (T < 0) return false;
        long long L = lcm_ll(r1, r2);
        long long both_charge = T / L;                // multiples of lcm -> unusable
        long long only2 = T / r1 - both_charge;       // only drone 2 available
        long long only1 = T / r2 - both_charge;       // only drone 1 available
        long long both_avail = T - (T / r1 + T / r2 - both_charge); // both available

        long long need1 = d1 - min(d1, only1);
        long long need2 = d2 - min(d2, only2);
        return need1 + need2 <= both_avail;
    };

    // Exponential search to find an upper bound, then binary search
    long long lo = 0, hi = 1;
    while (!feasible(hi)) {
        // prevent runaway overflow; hi grows until feasibility holds
        hi <<= 1;
        if (hi > (long long)4e18) break;
    }
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
    return 0;
    }
};

int main () {
    Solution obj;
    obj.solve();
}

/*
Problem:
*/