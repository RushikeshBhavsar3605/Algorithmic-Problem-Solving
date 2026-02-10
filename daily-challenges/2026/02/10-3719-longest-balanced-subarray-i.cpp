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

/* Approach 1 (Set): */
class Solution {
  public:
    int longestBalanced(vector<int> &nums) {
        int n = sz(nums);
        int res = 0;

        loop(i, 0, n) {
            uset<int> even;
            uset<int> odd;
            loop(j, i, n) {
                if (nums[j] & 1)
                    odd.insert(nums[j]);
                else
                    even.insert(nums[j]);

                if (sz(even) == sz(odd))
                    updateMax(res, j - i + 1);
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    vec<int> v = {2, 5, 4, 3};
    cout << obj.longestBalanced(v) << endl;
    v = {3, 2, 2, 5, 4};
    cout << obj.longestBalanced(v) << endl;
    v = {1, 2, 3, 2};
    cout << obj.longestBalanced(v) << endl;
    return 0;
}

/*
Problem: Longest Balanced Subarray I
*/