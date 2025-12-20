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

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Hashing + Graph): */
class Solution {
  public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        // people who currently know the secret
        uset<int> secrets = {0, firstPerson};

        // time -> (person -> neighbours at that time)
        // using ordered map so we process times in increasing order (as in Python sorted keys)
        map<int, umap<int, vi>> time_maps;
        iterate(meeting, meetings) {
            time_maps[meeting[2]][meeting[0]].pb(meeting[1]);
            time_maps[meeting[2]][meeting[1]].pb(meeting[0]);
        }

        // DFS to propagate secret inside the connected component of a single timestamp
        // vis is local per timestamp to avoid cross-time contamination
        function<void(int, umap<int, vi> &, umap<int, int> &)> dfs = [&](int src, umap<int, vi> &adj, umap<int, int> &vis) {
            if (vis.count(src)) // already visited for this time
                return;

            vis[src] = true;     // mark visited for this time
            secrets.insert(src); // src learns the secret

            iterate(nei, adj[src]) // visit neighbours (same timestamp)
                dfs(nei, adj, vis);
        };

        // process each timestamp: start DFS only from participants who already know the secret
        iterate(time_map, time_maps) {
            int time = time_map.ff;
            auto &time_adj = time_map.ss; // person -> neighbours for this timestamp
            umap<int, int> vis;           // reset visited per timestamp

            iterate(p, time_adj) { // iterate participants (keys), not neighbours
                int src = p.ff;
                if (secrets.count(src)) // only start propagation from those who know it
                    dfs(src, time_adj, vis);
            }
        }

        // return vector from set
        return {all(secrets)};
    }
};

int main() {
    Solution obj;
    vvi m = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    dump(obj.findAllPeople(6, m, 1));
    m = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}};
    dump(obj.findAllPeople(4, m, 3));
    m = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    dump(obj.findAllPeople(5, m, 1));
}

/*
Problem: Find All People With Secret
*/