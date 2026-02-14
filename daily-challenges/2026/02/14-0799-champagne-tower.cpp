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

/* Approach 1 (Simulation by Dynamic Programming): */
class Solution {
  public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // init: first row with poured amount
        vec<double> currRow = {(double)poured};

        // loop: simulate row by row until reaching query_row
        while (query_row--) {
            // init: next row with size +1 glasses, all zero
            vec<double> nextRow(sz(currRow) + 1, 0.0);

            // loop: process overflow for each glass in current row
            loop(i, 0, sz(currRow)) {
                // condition: calculate overflow beyond capacity (1.0)
                double overflow = max(0.0, currRow[i] - 1.0);

                // update: split overflow equally to next row glasses
                nextRow[i] += overflow / 2.0;
                nextRow[i + 1] += overflow / 2.0;
            }

            // update: move to next row
            swap(currRow, nextRow);
        }

        // return: glass can hold at most 1.0
        return min(1.0, currRow[query_glass]);
    }
};

int main() {
    Solution obj;
    cout << obj.champagneTower(1, 1, 1) << endl;
    cout << obj.champagneTower(2, 1, 1) << endl;
    cout << obj.champagneTower(100000009, 33, 17) << endl;
    return 0;
}

/*
Problem: Champagne Tower
*/