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

class Solution {
  public:
    int maxDistance(int side, vector<vector<int>> &points, int k) {
        vl arr;
        iterate(point, points) {
            int x = point[0];
            int y = point[1];
            ll pos;

            if (x == 0)
                pos = y;
            else if (y == side)
                pos = side + x;
            else if (x == side)
                pos = 3LL * side - y;
            else
                pos = 4LL * side - x;

            arr.pb(pos);
        }

        sort(all(arr));

        auto check = [&](int limit) {
            ll perimeter = side * 4LL;
            iterate(start, arr) {
                ll curr = start;
                ll end = start + perimeter - limit;

                loop(i, 0, k - 1) {
                    auto it = lower_bound(arr.begin(), arr.end(), curr + limit);
                    if (it == arr.end() || *it > end) {
                        curr = -1;
                        break;
                    }
                    curr = *it;
                }

                if (curr >= 0)
                    return true;
            }

            return false;
        };

        ll low = 1, high = side;
        int res = 0;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (check(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{0, 2}, {2, 0}, {2, 2}, {0, 0}};
    auto res = obj.maxDistance(2, v, 4);
    print(res);
    v = {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    res = obj.maxDistance(2, v, 4);
    print(res);
    v = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}};
    res = obj.maxDistance(2, v, 5);
    print(res);
    return 0;
}

/*
Problem: Maximize the Distance Between Points on a Square
*/