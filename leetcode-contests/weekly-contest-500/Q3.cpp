#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach (Prefix + Suffix): */
class Solution {
  public:
    vector<int> minCost(vector<int> &nums, vector<vector<int>> &queries) {
        int n = sz(nums);
        vi prefix(n, 0), suffix(n, 0);

        prefix[1] = 1;

        loop(i, 1, n - 1) {
            int leftIdx = abs(nums[i] - nums[i - 1]);
            int rightIdx = abs(nums[i] - nums[i + 1]);

            int step = (rightIdx < leftIdx) ? 1 : rightIdx;
            prefix[i + 1] += prefix[i] + step;
        }

        suffix[n - 2] = 1;

        revloop(i, n - 2, 1) {
            int leftIdx = abs(nums[i] - nums[i - 1]);
            int rightIdx = abs(nums[i] - nums[i + 1]);

            int step = (leftIdx <= rightIdx) ? 1 : leftIdx;
            suffix[i - 1] += suffix[i] + step;
        }

        vi res;
        iterate(query, queries) {
            int l = query[0];
            int r = query[1];

            if (l < r)
                res.pb(prefix[r] - prefix[l]);
            else
                res.pb(suffix[r] - suffix[l]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {-5, -2, 3};
    vvi q = {{0, 2}, {2, 0}, {1, 2}};
    auto res = obj.minCost(v, q);
    print(res);
    v = {0, 2, 3, 9};
    q = {{3, 0}, {1, 2}, {2, 0}};
    res = obj.minCost(v, q);
    print(res);
    return 0;
}

/*
Problem: Minimum Cost to Move Between Indices
*/