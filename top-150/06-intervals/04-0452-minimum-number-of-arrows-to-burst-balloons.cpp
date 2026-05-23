#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach (Intervals): */
class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(all(points));
        int arrows = 0;

        int stMax = points[0][0];
        int enMin = points[0][1];

        loop(i, 1, sz(points)) {
            int st = points[i][0];
            int en = points[i][1];

            if (enMin < st) {
                arrows++;
                stMax = st;
                enMin = en;
            } else {
                updateMax(stMax, st);
                updateMin(enMin, en);
            }
        }

        return arrows + 1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    auto res = obj.findMinArrowShots(v);
    print(res);
    v = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    res = obj.findMinArrowShots(v);
    print(res);
    v = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    res = obj.findMinArrowShots(v);
    print(res);
    return 0;
}

/*
Problem: Minimum Number of Arrows to Burst Balloons
*/