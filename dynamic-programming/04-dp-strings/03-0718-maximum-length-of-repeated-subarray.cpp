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

/* Approach 1 (Tabulation):
class Solution {
  public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = sz(nums1);
        int m = sz(nums2);
        vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));

        int maxi = 0;
        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (nums1[i] == nums2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;

                updateMax(maxi, dp[i][j]);
            }
        }

        return maxi;
    }
};
*/

/* Approach 2 (Space Optimization): */
class Solution {
  public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        int n = sz(nums1);
        int m = sz(nums2);
        vec<int> curr(m + 1, 0);
        vec<int> next(m + 1, 0);

        int maxi = 0;
        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                if (nums1[i] == nums2[j])
                    curr[j] = next[j + 1] + 1;
                else
                    curr[j] = 0;

                updateMax(maxi, curr[j]);
            }

            swap(curr, next);
        }

        return maxi;
    }
};

int main() {
    Solution obj;
    vec<int> v1 = {1, 2, 3, 2, 1};
    vec<int> v2 = {3, 2, 1, 4, 7};
    auto res = obj.findLength(v1, v2);
    print(res);
    v1 = {0, 0, 0, 0, 0};
    v2 = {0, 0, 0, 0, 0};
    res = obj.findLength(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Longest Common Substring

  3 2 1 4 7 
1 0 0 1 0 0 0 
2 0 1 0 0 0 0 
3 3 0 0 0 0 0 
2 0 2 0 0 0 0 
1 0 0 1 0 0 0 
  0 0 0 0 0 0 

3

  0 0 0 0 0 
0 5 4 3 2 1 0 
0 4 4 3 2 1 0 
0 3 3 3 2 1 0 
0 2 2 2 2 1 0 
0 1 1 1 1 1 0 
  0 0 0 0 0 0 

5
*/