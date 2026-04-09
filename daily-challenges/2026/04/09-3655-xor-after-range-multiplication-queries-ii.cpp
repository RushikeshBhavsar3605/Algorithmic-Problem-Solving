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

/* Approach 1 (Difference Array Technique): */
class Solution {
  private:
    int M = 1e9 + 7;

    ll power(ll a, ll b) {
        if (b == 0)
            return 1;

        ll half = power(a, b / 2);
        ll res = (half * half) % M;

        if (b % 2 == 1)
            res = (res * a) % M;

        return res;
    }

  public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        int n = sz(nums);
        int blockSize = ceil(sqrt(n));

        umap<int, vec<vec<int>>> smallKMap;

        iterate(query, queries) {
            int L = query[0];
            int R = query[1];
            int K = query[2];
            int V = query[3];

            if (K >= blockSize)
                for (int i = L; i <= R; i += K)
                    nums[i] = (1LL * nums[i] * V) % M;
            else
                smallKMap[K].pb(query);
        }

        for (auto &[K, allQueries] : smallKMap) {
            vec<ll> diff(n, 1);

            iterate(query, allQueries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R - L) / K;
                int next = L + (steps + 1) * K;

                if (next < n)
                    diff[next] = (diff[next] * power(V, M - 2)) % M;
            }

            loop(i, 0, n)
                if (i - K >= 0)
                    diff[i] = (diff[i] * diff[i - K]) % M;

            loop(i, 0, n)
                nums[i] = (1LL * nums[i] * diff[i]) % M;
        }

        int res = 0;
        iterate(num, nums)
            res = res ^ num;

        return res;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 1, 1};
    vec<vec<int>> q = {{0, 2, 1, 4}};
    auto res = obj.xorAfterQueries(v, q);
    print(res);
    v = {2, 3, 1, 5, 4};
    q = {{1, 4, 2, 3}, {0, 2, 1, 2}};
    res = obj.xorAfterQueries(v, q);
    print(res);
    return 0;
}

/*
Problem: XOR After Range Multiplication Queries II
*/