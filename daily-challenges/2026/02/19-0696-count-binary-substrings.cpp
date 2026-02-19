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

/* Approach 1 (Greedy): */
class Solution {
  public:
    int countBinarySubstrings(string s) {
        // init:
        // res → stores total valid substrings
        // prevCount → length of previous consecutive group
        // currCount → length of current consecutive group (start with 1)
        int res = 0;
        int prevCount = 0;
        int currCount = 1;

        // loop: traverse string from index 1 to n-1
        loop(i, 1, sz(s)) {
            // condition:
            // if current char equals previous → extend current group
            if (s[i - 1] == s[i])
                currCount++;

            else {
                // group changed:
                // add valid substrings formed by previous & current groups
                res += min(prevCount, currCount);

                // update:
                // current group becomes previous
                prevCount = currCount;
                // reset current group count
                currCount = 1;
            }
        }

        // final addition:
        // account for last pair of groups
        return res + min(prevCount, currCount);
    }
};

int main() {
    Solution obj;
    cout << obj.countBinarySubstrings("00110011") << endl;
    cout << obj.countBinarySubstrings("10101") << endl;
    return 0;
}

/*
Problem: Count Binary Substrings
*/