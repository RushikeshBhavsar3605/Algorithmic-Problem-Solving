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

/* Approach 1 (Brute Force):
class Solution {
  public:
    char findKthBit(int n, int k) {
        string str = "0";
        while (n--) {
            str += "1";
            int strSize = sz(str);
            revloop(i, strSize - 2, 0)
                str += str[i] == '1' ? "0" : "1";

            if (sz(str) > k - 1)
                return str[k - 1];
        }

        return -1;
    }
};
*/

/* Approach 2 (Greedy + Recursion): */
class Solution {
  public:
    char findKthBit(int n, int k) {
        int length = (1 << n) - 1;
        bool invert = false;

        while (length > 1) {
            int mid = (length >> 1);

            if (k <= mid)
                length = mid;
            else if (k > mid + 1) {
                k = 1 + length - k;
                length = mid;
                invert = !invert;
            } else
                return invert ? '0' : '1';
        }

        return invert ? '1' : '0';
    }
};

int main() {
    Solution obj;
    auto res = obj.findKthBit(3, 1);
    print(res);
    res = obj.findKthBit(4, 11);
    print(res);
    return 0;
}

/*
Problem: Find Kth Bit in Nth Binary String
*/