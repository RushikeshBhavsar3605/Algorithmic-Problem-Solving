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

/* Approach 1 (Dynamic Programming): */
class Solution {
  private:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = sz(text1);
        int m = sz(text2);
        vec<int> curr(m + 1, 0);
        vec<int> next(m + 1, 0);

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (text1[i] == text2[j])
                    curr[j] = next[j + 1] + 1;
                else
                    curr[j] = max(curr[j + 1], next[j]);
            }

            swap(curr, next);
        }

        return next[0];
    }

  public:
    int minInsertions(string s) {
        string t = s;
        reverse(all(t));
        int maxLength = longestCommonSubsequence(s, t);

        return sz(s) - maxLength;
    }
};

int main() {
    Solution obj;
    auto res = obj.minInsertions("zzazz");
    print(res);
    res = obj.minInsertions("mbadm");
    print(res);
    res = obj.minInsertions("leetcode");
    print(res);
    return 0;
}

/*
Problem: Minimum Insertion Steps to Make a String Palindrome
*/