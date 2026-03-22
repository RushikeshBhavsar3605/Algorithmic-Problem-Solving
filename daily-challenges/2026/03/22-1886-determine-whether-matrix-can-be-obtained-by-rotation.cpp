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

// =====================
// Universal Printers
// =====================
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
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
        int n = sz(mat);

        function<void()> increment = [&]() {
            loop(i, 0, n)
                loop(j, i, n)
                    swap(mat[i][j], mat[j][i]);

            loop(i, 0, n)
                reverse(all(mat[i]));
        };

        function<bool()> isEqual = [&]() {
            loop(i, 0, n)
                loop(j, 0, n)
                    if (mat[i][j] != target[i][j])
                        return false;

            return true;
        };

        loop(i, 0, 4) {
            if (isEqual())
                return true;

            increment();
        }

        return false;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> m = {{0, 1}, {1, 0}};
    vec<vec<int>> t = {{1, 0}, {0, 1}};
    auto res = obj.findRotation(m, t);
    print(res);
    m = {{0, 1}, {1, 1}};
    t = {{1, 0}, {0, 1}};
    res = obj.findRotation(m, t);
    print(res);
    m = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    t = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    res = obj.findRotation(m, t);
    print(res);
    return 0;
}

/*
Problem: Determine Whether Matrix Can Be Obtained By Rotation
*/