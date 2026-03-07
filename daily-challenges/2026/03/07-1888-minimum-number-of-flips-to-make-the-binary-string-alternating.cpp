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

/* Approach 1 (Sliding Window):
class Solution {
  public:
    int minFlips(string s) {
        int n = sz(s);
        s = s + s;

        string s1, s2;
        loop(i, 0, 2 * n) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int res = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0, j = 0;

        while (j < 2 * n) {
            if (s[j] != s1[j])
                flip1++;
            if (s[j] != s2[j])
                flip2++;

            if (j - i + 1 > n) {
                if (s[i] != s1[i])
                    flip1--;
                if (s[i] != s2[i])
                    flip2--;

                i++;
            }

            if (j - i + 1 == n)
                res = min({res, flip1, flip2});
            j++;
        }

        return res;
    }
};
*/

/* Approach 2 (Space Optimization in Sliding Window): */
class Solution {
  public:
    int minFlips(string s) {
        int n = sz(s);

        int res = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;
        int i = 0, j = 0;

        while (j < 2 * n) {
            char expectedCharS1 = (j % 2) ? '0' : '1';
            char expectedCharS2 = (j % 2) ? '1' : '0';

            if (s[j % n] != expectedCharS1)
                flip1++;
            if (s[j % n] != expectedCharS2)
                flip2++;

            if (j - i + 1 > n) {
                expectedCharS1 = (i % 2) ? '0' : '1';
                expectedCharS2 = (i % 2) ? '1' : '0';

                if (s[i % n] != expectedCharS1)
                    flip1--;
                if (s[i % n] != expectedCharS2)
                    flip2--;

                i++;
            }

            if (j - i + 1 == n)
                res = min({res, flip1, flip2});
            j++;
        }

        return res;
    }
};

int main() {
    Solution obj;
    auto res = obj.minFlips("111000");
    print(res);
    res = obj.minFlips("010");
    print(res);
    res = obj.minFlips("1110");
    print(res);
    return 0;
}

/*
Problem: Minimum Number of Flips to Make the Binary String Alternating
*/