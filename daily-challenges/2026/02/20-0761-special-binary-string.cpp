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

/* Approach 1 (Recursive Partitioning and Greedy Sorting): */
class Solution {
  public:
    string makeLargestSpecial(string s) {
        // init:
        // specials → stores all top-level special substrings
        // start → starting index of current special substring
        // sum → balance counter (1 for '1', -1 for '0')
        vec<string> specials;

        int start = 0;
        int sum = 0;

        // loop: traverse entire string
        loop(i, 0, sz(s)) {
            // update:
            // increment balance for '1'
            // decrement balance for '0'
            sum += s[i] == '1' ? 1 : -1;

            // condition:
            // when balance becomes 0 → we found a valid special substring
            if (sum == 0) {
                // extract inner substring (excluding outer 1 and 0)
                string inner = s.substr(start + 1, i - start - 1);
                // recursively make inner largest
                // then wrap it again with '1' and '0'
                specials.pb("1" + makeLargestSpecial(inner) + "0");
                // move start to next position
                start = i + 1;
            }
        }

        // sort all top-level special substrings in descending order
        // to form lexicographically largest result
        sort(all(specials), greater<string>());

        // build final result by concatenating sorted substrings
        string res;
        iterate(str, specials)
            res += str;

        // return largest special string
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.makeLargestSpecial("11011000") << endl;
    cout << obj.makeLargestSpecial("10") << endl;
    return 0;
}

/*
Problem: Special Binary String
*/