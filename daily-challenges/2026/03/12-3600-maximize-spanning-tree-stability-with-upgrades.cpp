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

class DisjointSet {
  private:
    vec<int> size, parent;

  public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        loop(i, 0, n + 1)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;
        else if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        } else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

/* Approach 1 (BS on answers + MST + DSU): */
class Solution {
  private:
    bool check(int n, vec<vec<int>> &edges, int k, int mid) {
        DisjointSet dsu(n);
        vec<vec<int>> upgradeCandidates;

        iterate(edge, edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if (m == 1) {
                if (s < mid)
                    return false;

                dsu.unionBySize(u, v);
            } else {
                if (s >= mid)
                    dsu.unionBySize(u, v);
                else if (2 * s >= mid)
                    upgradeCandidates.pb({u, v});
            }
        }

        iterate(edge, upgradeCandidates) {
            int u = edge[0];
            int v = edge[1];

            if (dsu.findParent(u) != dsu.findParent(v)) {
                if (k == 0)
                    return false;

                dsu.unionBySize(u, v);
                k--;
            }
        }

        int root = dsu.findParent(0);
        loop(node, 1, n)
            if (dsu.findParent(node) != root)
                return false;

        return true;
    }

  public:
    int maxStability(int n, vector<vector<int>> &edges, int k) {
        DisjointSet dsu(n);
        iterate(edge, edges) {
            int u = edge[0];
            int v = edge[1];

            int s = edge[2];
            int m = edge[3];

            if (m == 1) {
                if (dsu.findParent(u) == dsu.findParent(v))
                    return -1;

                dsu.unionBySize(u, v);
            }
        }

        int res = -1;
        int left = 1;
        int right = 2 * 1e5;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (check(n, edges, k, mid)) {
                res = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }

        return res;
    }
};

int main() {
    Solution obj;
    vec<vec<int>> e = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    auto res = obj.maxStability(3, e, 1);
    print(res);
    e = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
    res = obj.maxStability(3, e, 2);
    print(res);
    e = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
    res = obj.maxStability(3, e, 0);
    print(res);
    return 0;
}

/*
Problem: Maximize Spanning Tree Stability with Upgrades
*/