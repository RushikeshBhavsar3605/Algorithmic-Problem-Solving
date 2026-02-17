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

/* Approach 1 (Bit Manipulation): */
class Solution {
  public:
    vector<string> readBinaryWatch(int turnedOn) {
        // init: result container to store valid time strings
        vec<string> res;

        // loop: iterate over all possible hours (0 to 11)
        loop(h, 0, 12)

            // loop: iterate over all possible minutes (0 to 59)
            loop(m, 0, 60)

            // condition:
            // total set bits in hour + minute must equal turnedOn
            if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)

                // update:
                // format as "H:MM"
                // - hour without leading zero
                // - minute with leading zero if < 10
                res.pb(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));

        // return: all valid times
        return res;
    }
};

int main() {
    Solution obj;
    DUMP(obj.readBinaryWatch(1));
    DUMP(obj.readBinaryWatch(9));
    return 0;
}

/*
Problem: Binary Watch
*/