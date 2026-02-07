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

/* Approach 1 (Simulation + Greedy): */
class Solution {
  public:
    vector<int> rotateElements(vector<int> &nums, int k) {
        // init: collect all non-negative elements
        vec<int> positives;
        iterate(num, nums)
            if (num >= 0)
                positives.pb(num);

        // edge case: no non-negative elements, return original array
        if (sz(positives) == 0)
            return nums;

        // update: reduce k within bounds of positives count
        k %= sz(positives);
        // operation: rotate non-negative elements by k positions to the left
        rotate(positives.begin(), positives.begin() + k, positives.end());

        // init: build result array using rotated positives
        vec<int> res;
        int idx = 0;

        // loop: replace non-negative elements with rotated ones, keep negatives intact
        iterate(num, nums)
            if (num >= 0)
                res.pb(positives[idx++]);
            else
                res.pb(num);

        // return: final rotated array
        return res;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, -2, 3, -4};
    DUMP(obj.rotateElements(v, 3));
    v = {-3, -2, 7};
    DUMP(obj.rotateElements(v, 1));
    v = {5, 4, -9, 6};
    DUMP(obj.rotateElements(v, 2));
}

/*
Problem: Rotate Non Negative Elements
*/