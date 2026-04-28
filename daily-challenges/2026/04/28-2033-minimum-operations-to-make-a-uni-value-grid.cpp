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
    int minOperations(vector<vector<int>> &grid, int x) {
        vi nums;
        int res = 0;
        loop(row, 0, sz(grid)) {
            loop(col, 0, sz(grid[0])) {
                if (grid[row][col] % x != grid[0][0] % x)
                    return -1;
                nums.pb(grid[row][col]);
            }
        }

        sort(all(nums));

        int length = sz(nums);
        int prefixIdx = 0;
        int suffixIdx = length - 1;

        while (prefixIdx < suffixIdx) {
            if (prefixIdx < length - suffixIdx - 1) {
                int prefixOps = (prefixIdx + 1) * (nums[prefixIdx + 1] - nums[prefixIdx]) / x;

                res += prefixOps;
                prefixIdx++;
            } else {
                int suffixOps = (length - suffixIdx) * (nums[suffixIdx] - nums[suffixIdx - 1]) / x;

                res += suffixOps;
                suffixIdx--;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{2, 4}, {6, 8}};
    auto res = obj.minOperations(v, 2);
    print(res);
    v = {{1, 5}, {2, 3}};
    res = obj.minOperations(v, 1);
    print(res);
    v = {{1, 2}, {3, 4}};
    res = obj.minOperations(v, 2);
    print(res);
    return 0;
}

/*
Problem: Minimum Operations to Make a Uni-Value Grid
*/