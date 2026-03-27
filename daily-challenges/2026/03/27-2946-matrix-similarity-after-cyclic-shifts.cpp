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

/* Approach 1 (Naive):
class Solution {
  public:
    bool areSimilar(vector<vector<int>> &mat, int k) {
        vec<vec<int>> copy = mat;
        int n = sz(mat);
        int m = sz(mat[0]);

        k %= m;
        if (k == 0)
            return true;

        loop(i, 0, n) {
            if (i & 1)
                rotate(rbegin(copy[i]), rbegin(copy[i]) + k, rend(copy[i]));
            else
                rotate(begin(copy[i]), begin(copy[i]) + k, end(copy[i]));
        }

        return copy == mat;
    }
};
*/

/* Approach 2 (Hashing): */
class Solution {
  public:
    bool areSimilar(vector<vector<int>> &mat, int k) {
        int n = sz(mat);
        int m = sz(mat[0]);

        k %= m;
        if (k == 0)
            return true;

        loop(i, 0, n) {
            loop(j, 0, m) {
                int currIdx = j;
                int finalIdx;

                if (i & 1)
                    finalIdx = (currIdx + k) % m;
                else
                    finalIdx = (currIdx - k + m) % m;

                if (mat[i][currIdx] != mat[i][finalIdx])
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = obj.areSimilar(v, 4);
    print(res);
    v = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
    res = obj.areSimilar(v, 2);
    print(res);
    v = {{2, 2}, {2, 2}};
    res = obj.areSimilar(v, 3);
    print(res);
    return 0;
}

/*
Problem: Matrix Similarity After Cyclic Shifts
*/