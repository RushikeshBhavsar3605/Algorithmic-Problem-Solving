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

class Solution {
  public:
    int minOperations(string s, int k) {
        int n = sz(s), m = 0;
        vec<int> dist(n + 1, INT_MAX);
        vec<set<int>> nodeSets(2);
        loop(i, 0, n + 1) {
            nodeSets[i % 2].insert(i);
            if (i < n && s[i] == '0')
                m++;
        }

        queue<int> q;
        q.push(m);
        dist[m] = 0;
        nodeSets[m % 2].erase(m);

        while (!q.empty()) {
            m = q.front();
            q.pop();
            int c1 = max(k - n + m, 0), c2 = min(m, k);
            int lnode = m + k - 2 * c2, rnode = m + k - 2 * c1;
            auto &nodeSet = nodeSets[lnode % 2];
            for (auto iter = nodeSet.lower_bound(lnode); iter != nodeSet.end() && *iter <= rnode;) {
                int m2 = *iter;
                dist[m2] = dist[m] + 1;
                q.push(m2);
                iter = next(iter);
                nodeSet.erase(m2);
            }
        }

        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};

int main() {
    Solution obj;
    auto res = obj.minOperations("110", 1);
    print(res);
    res = obj.minOperations("0101", 3);
    print(res);
    res = obj.minOperations("101", 2);
    print(res);
    return 0;
}

/*
Problem: Minimum Operations to Equalize Binary String
*/