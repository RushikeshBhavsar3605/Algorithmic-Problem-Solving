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

class Solution {
  public:
    string generateString(string str1, string str2) {
        int n = sz(str1), m = sz(str2);
        string s(n + m - 1, 'a');
        vec<int> fixed(n + m - 1, 0);

        loop(i, 0, n) {
            if (str1[i] == 'T') {
                loop(j, i, i + m) {
                    if (fixed[j] && s[j] != str2[j - i])
                        return "";
                    else {
                        s[j] = str2[j - i];
                        fixed[j] = 1;
                    }
                }
            }
        }

        loop(i, 0, n) {
            if (str1[i] == 'F') {
                bool flag = false;
                int idx = -1;
                revloop(j, i + m - 1, i) {
                    if (str2[j - i] != s[j])
                        flag = true;
                    if (idx == -1 && !fixed[j])
                        idx = j;
                }
                if (flag)
                    continue;
                else if (idx != -1)
                    s[idx] = 'b';
                else
                    return "";
            }
        }

        return s;
    }
};

int main() {
    Solution obj;
    auto res = obj.generateString("TFTF", "ab");
    print(res);
    res = obj.generateString("TFTF", "abc");
    print(res);
    res = obj.generateString("F", "d");
    print(res);
    return 0;
}

/*
Problem: Lexicographically Smallest Generated String
*/