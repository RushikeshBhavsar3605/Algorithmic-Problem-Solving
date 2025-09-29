#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

/* Approach 1 (Union By Rank):
class DisjointSet {
  private:
    vi rank, parent;

  public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        loop(i, 0, n + 1)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent == vParent)
            return;
        else if (rank[uParent] < rank[vParent])
            parent[uParent] = vParent;
        else if (rank[uParent] > rank[vParent])
            parent[vParent] = uParent;
        else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }
};
*/
/*
Time Complexity:
- findParent(): O(4 * α(n))
- unionByRank(): O(4 * α(n))
Space Complexity: O(n)
*/

/* Approach 2 (Union By Size): */
class DisjointSet {
  private:
    vi size, parent;

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
/*
Time Complexity:
- findParent(): O(4 * α(n))
- unionBySize(): O(4 * α(n))
Space Complexity: O(n)
*/

int main() {
    DisjointSet obj(7);
    obj.unionBySize(1, 2);
    obj.unionBySize(2, 3);
    obj.unionBySize(4, 5);
    obj.unionBySize(6, 7);
    obj.unionBySize(5, 6);
    if (obj.findParent(3) == obj.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;
    obj.unionBySize(3, 7);
    if (obj.findParent(3) == obj.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;
}

/*
Problem:
*/