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

/* Approach 1 (Sliding Window + Greedy): */
class Solution {
  public:
    int minRemoval(vector<int> &nums, int k) {
        // init: size of array
        int n = sz(nums);
        // sort: required for sliding window on min/max
        sort(all(nums));

        // init: current window min and max
        int maxi = nums[0];
        int mini = nums[0];

        // init: track maximum valid subarray length
        int maxSub = 1;
        // init: left pointer of sliding window
        int left = 0;

        // loop: expand window using right pointer
        loop(right, 0, n) {
            // update: window boundaries
            mini = nums[left];
            maxi = nums[right];

            // shrink: ensure condition mini * k >= maxi
            while (left < right && (ll)mini * k < maxi) {
                left++;
                mini = nums[left];
            }

            // update: maximum valid window size
            maxSub = max(maxSub, right - left + 1);
        }

        // result: removals = total elements - largest valid subarray
        return n - maxSub;
    }
};

int main() {
    Solution obj;
    vec<int> v = {2, 1, 5};
    cout << obj.minRemoval(v, 2) << endl;
    v = {1, 6, 2, 9};
    cout << obj.minRemoval(v, 3) << endl;
    v = {4, 6};
    cout << obj.minRemoval(v, 2) << endl;
    return 0;
}

/*
Problem: Minimum Removals to Balance Array
*/