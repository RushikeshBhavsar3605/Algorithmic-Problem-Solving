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

template <typename Node> void print(Node *head) {
    Node *curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

/* Approach (BFS + Binary Exponentiation): */
class Solution {
  private:
    const int MOD = 1e9 + 7;

    int bfs(vvi &adj, int n) {
        queue<int> q;
        q.push(1);

        vi vis(n, 0);
        vis[1] = 1;

        int depth = 0;
        while (!q.empty()) {
            int size = sz(q);

            loop(i, 0, size) {
                int node = q.front();
                q.pop();

                vis[node] = 1;

                iterate(newNode, adj[node]) {
                    if (!vis[newNode])
                        q.push(newNode);
                }
            }

            depth++;
        }

        return depth - 1;
    }

    int power(int base, int exp) {
        ll res = 1;
        ll b = base;

        while (exp > 0) {
            if (exp & 1)
                res = (res * b) % MOD;

            b = (b * b) % MOD;
            exp >>= 1;
        }

        return (int)res;
    }

  public:
    int assignEdgeWeights(vector<vector<int>> &edges) {
        int n = sz(edges) + 2;
        vvi adj(n);

        iterate(edge, edges) {
            adj[edge[0]].pb(edge[1]);
            adj[edge[1]].pb(edge[0]);
        }

        int depth = bfs(adj, n);

        return power(2, depth - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 2}};
    auto res = obj.assignEdgeWeights(v);
    print(res);
    v = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    res = obj.assignEdgeWeights(v);
    print(res);
    return 0;
}

/*
Problem: Number of Ways to Assign Edge Weights I
*/