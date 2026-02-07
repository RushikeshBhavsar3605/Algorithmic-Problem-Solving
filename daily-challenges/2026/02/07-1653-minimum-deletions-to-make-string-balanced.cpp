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

/* Approach 1 (Greedy Prefix-Suffix Counting): */
class Solution {
  public:
    int minimumDeletions(string s) {
        // init: count total 'a's (to the right initially)
        int aCount = count(all(s), 'a');
        // init: count of 'b's seen so far (to the left)
        int bCount = 0;

        // init: worst-case answer (delete all 'a's to the right)
        int res = aCount;

        // loop: traverse string, treating each index as a split point
        loop(i, 0, sz(s)) {
            // update: move current character from right side to left side
            if (s[i] == 'a')
                aCount--; // one less 'a' on the right
            else
                bCount++; // one more 'b' on the left

            // update: minimize deletions needed at this split
            updateMin(res, aCount + bCount);
        }

        // result: minimum deletions to make string balanced
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.minimumDeletions("aababbab") << endl;
    cout << obj.minimumDeletions("bbaaaaabb") << endl;
    return 0;
}

/*
Problem: Minimum Deletions to Make String Balanced
*/