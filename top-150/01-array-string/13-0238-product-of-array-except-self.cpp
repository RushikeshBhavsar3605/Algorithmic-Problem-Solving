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

/* Approach 1 (Prefix + Suffix):
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = sz(nums);
        vi prefix(n);
        loop(i, 0, n) {
            prefix[i] = nums[i];
            if (i != 0)
                prefix[i] *= prefix[i - 1];
        }

        vi suffix(n);
        revloop(i, n - 1, 0) {
            suffix[i] = nums[i];
            if (i != n - 1)
                suffix[i] *= suffix[i + 1];
        }

        vi res(n);
        loop(i, 0, n) {
            int left = i != 0 ? prefix[i - 1] : 1;
            int right = i != n - 1 ? suffix[i + 1] : 1;

            res[i] = left * right;
        }

        return res;
    }
};
*/

/* Approach 2 (Space Optimization): */
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = sz(nums);
        vi suffix(n);
        revloop(i, n - 1, 0) {
            suffix[i] = nums[i];
            if (i != n - 1)
                suffix[i] *= suffix[i + 1];
        }

        int prefix;
        vi res(n);
        loop(i, 0, n) {
            int left = i != 0 ? prefix : 1;
            int right = i != n - 1 ? suffix[i + 1] : 1;

            prefix *= nums[i];
            if (i == 0)
                prefix = nums[0];

            res[i] = left * right;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4};
    auto res = obj.productExceptSelf(v);
    print(res);
    v = {-1, 1, 0, -3, 3};
    res = obj.productExceptSelf(v);
    print(res);
    return 0;
}

/*
Problem: Product of Array Except Self
*/