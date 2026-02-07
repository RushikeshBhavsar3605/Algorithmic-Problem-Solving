#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

/* Approach 1 (Combinatorics): */
class Solution {
  public:
    long long nthSmallest(long long n, int k) {
        // init: precompute combinations C(n, r) up to 50
        ll comb[51][51] = {0};
        loop_le(i, 0, 50) {
            comb[i][0] = 1; // base case: C(i, 0) = 1
            loop_le(j, 1, i)
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }

        // init: result number and helper for combinations count
        ll res = 0, c = 0;

        // loop: iterate bits from MSB (49) to LSB (0)
        revloop(i, 49, 0) {
            // count: numbers possible if current bit is 0
            c = comb[i][k];

            // condition: skip all numbers with this bit = 0
            if (n > c) {
                // update: set current bit to 1
                res |= 1LL << i;
                // update: reduce rank and remaining set bits
                n -= c;
                k -= 1;
            }
        }

        // result: nth smallest number with exactly original k bits set
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.nthSmallest(4, 2) << endl;
    cout << obj.nthSmallest(3, 1) << endl;
    return 0;
}

/*
Problem: Find Nth Smallest Integer With K One Bits
*/