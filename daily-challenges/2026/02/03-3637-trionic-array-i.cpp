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

/* Approach 1 (Segment Count + Greedy): */
class Solution {
  public:
    bool isTrionic(vector<int> &nums) {
        // init: array size, phase counter, initial trend
        int n = sz(nums);
        int count = 1;                         // number of monotonic segments
        bool isIncreasing = nums[0] < nums[1]; // current trend

        // loop: traverse from index 2 to end
        loop(i, 2, n) {
            // transition: decreasing -> increasing
            if (nums[i - 1] < nums[i] && !isIncreasing) {
                isIncreasing = true;
                count++;
            }

            // transition: increasing -> decreasing
            if (nums[i - 1] > nums[i] && isIncreasing) {
                isIncreasing = false;
                count++;
            }

            // invalid: equal adjacent elements
            if (nums[i - 1] == nums[i])
                return false;
        }

        // check: exactly 3 segments and ends with increasing
        return count == 3 && isIncreasing;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 3, 5, 4, 2, 6};
    cout << obj.isTrionic(v) << endl;
    v = {2, 1, 3};
    cout << obj.isTrionic(v) << endl;
    return 0;
}

/*
Problem: Trionic Array I
*/