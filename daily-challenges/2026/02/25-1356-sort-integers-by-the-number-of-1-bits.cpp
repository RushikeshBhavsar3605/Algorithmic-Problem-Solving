#include <bits/stdc++.h>
using namespace std;

// Type Aliases
using ll = long long;
template <typename T> using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// STL Helpers
#define pb push_back
#define all(x) begin(x), end(x)
template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// Unordered Containers
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T> using uset = unordered_set<T>;

// Loop Macros
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// Min / Max Updaters
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Unique (sort + dedup)
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// Debug Utilities (OJ-safe)
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

// Universal Printers
template <typename T> void print(T x) { cout << x << endl; }
template <typename T> void print(vec<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}
template <typename T> void print(vec<vec<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Naive): */
class Solution {
  public:
    vector<int> sortByBits(vector<int> &arr) {
        map<int, vec<int>> mp;
        iterate(it, arr)
            mp[__popcount(it)].pb(it);

        iterate(it, mp)
            sort(all(it.second));

        vec<int> res;
        iterate(it, mp)
            iterate(i, it.second)
                res.pb(i);

        return res;
    }
};

int main() {
    Solution obj;
    vec<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    auto res = obj.sortByBits(v);
    print(res);
    v = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    res = obj.sortByBits(v);
    print(res);
    return 0;
}

/*
Problem: Sort Integers by The Number of 1 Bits
*/