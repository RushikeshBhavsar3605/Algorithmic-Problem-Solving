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

class SegTree {
  public:
    vector<ll> array;
    int size;

    SegTree(int n) {
        size = n;
        array.assign(4 * n + 5, 0);
    }

    void update(int i, long long val, int idx, int left, int right) {
        if (left == right) {
            array[idx] = max(array[idx], val);
            return;
        }

        int mid = left + ((right - left) >> 1);
        if (i <= mid)
            update(i, val, 2 * idx + 1, left, mid);
        else
            update(i, val, 2 * idx + 2, mid + 1, right);

        array[idx] = max(array[2 * idx + 1], array[2 * idx + 2]);
    }

    long long query(int start, int end, int idx, int left, int right) {
        if (right < start || end < left)
            return 0;

        if (start <= left && right <= end)
            return array[idx];

        int mid = left + ((right - left) >> 1);
        return max(query(start, end, 2 * idx + 1, left, mid), query(start, end, 2 * idx + 2, mid + 1, right));
    }
};

/* Approach (Segment Tree): */
class Solution {
  public:
    long long maxAlternatingSum(vector<int> &nums, int k) {
        int MAXV = 1e5;
        int n = sz(nums);

        vl up(n), down(n);
        SegTree segUp(MAXV + 1), segDown(MAXV + 1);

        ll res = 0;

        loop(i, 0, n) {
            if (i - k >= 0) {
                int j = i - k;
                segUp.update(nums[j], up[j], 0, 1, MAXV);
                segDown.update(nums[j], down[j], 0, 1, MAXV);
            }

            ll bestDown = segDown.query(1, nums[i] - 1, 0, 1, MAXV);
            ll bestUp = segUp.query(nums[i] + 1, MAXV, 0, 1, MAXV);

            up[i] = nums[i] + bestDown;
            down[i] = nums[i] + bestUp;

            up[i] = max<ll>(up[i], nums[i]);
            down[i] = max<ll>(down[i], nums[i]);

            updateMax(res, max(up[i], down[i]));
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {5, 4, 2};
    auto res = obj.maxAlternatingSum(v, 2);
    print(res);
    v = {3, 5, 4, 2, 4};
    res = obj.maxAlternatingSum(v, 1);
    print(res);
    v = {5};
    res = obj.maxAlternatingSum(v, 1);
    print(res);
    return 0;
}

/*
Problem: Maximum Sum of Alternating Subsequence With Distance at Least K
*/