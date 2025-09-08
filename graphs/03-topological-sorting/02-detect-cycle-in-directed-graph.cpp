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

/* Approach 3 (Breadth First Search) (Kahn's Algorithm): */
class Solution {
  public:
    bool solve(int n, umap<int, vi> &adj) {
        vi indeg(n, 0);
        loop(i, 0, n)
            iterate(it, adj[i])
                indeg[it]++;

        queue<int> q;
        loop(i, 0, n)
            if (indeg[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;

            iterate(it, adj[node])
                if (--indeg[it] == 0)
                    q.push(it);
        }

        return count != n;
    }
};

int main() {
    Solution obj;
    umap<int, vi> adj = {{1, {2}}, {2, {3}},    {3, {4, 7}}, {4, {5}}, {5, {6}},
                         {7, {5}}, {8, {2, 9}}, {9, {10}},   {10, {8}}};
    cout << obj.solve(11, adj);
    return 0;
}

/*
Problem:
*/