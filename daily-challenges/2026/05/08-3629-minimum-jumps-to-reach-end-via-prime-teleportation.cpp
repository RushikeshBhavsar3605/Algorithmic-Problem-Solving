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

const int MX = 1000001;
vector<int> factors[MX];
bool initialized = []() {
    loop(i, 2, MX) {
        if (factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                factors[j].pb(i);
            }
        }
    }
    return true;
}();

class Solution {
  public:
    int minJumps(vector<int> &nums) {
        int n = nums.size();
        umap<int, vi> edges;
        loop(i, 0, n) {
            iterate(p, factors[nums[i]]) { edges[p].pb(i); }
        }

        int res = 0;
        vector<bool> seen(n, false);
        seen[0] = true;
        vi q = {0};

        while (true) {
            vi q2;
            iterate(i, q) {
                if (i == n - 1)
                    return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.pb(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.pb(i + 1);
                }
                if (factors[nums[i]].size() == 1) {
                    int p = nums[i];
                    if (edges.count(p)) {
                        iterate(j, edges[p]) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.pb(j);
                            }
                        }
                        edges[p].clear();
                    }
                }
            }

            q = move(q2);
            res++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 4, 6};
    auto res = obj.minJumps(v);
    print(res);
    v = {2, 3, 4, 7, 9};
    res = obj.minJumps(v);
    print(res);
    v = {4, 6, 5, 8};
    res = obj.minJumps(v);
    print(res);
    return 0;
}

/*
Problem: Minimum Jumps to Reach End via Prime Teleportation
*/