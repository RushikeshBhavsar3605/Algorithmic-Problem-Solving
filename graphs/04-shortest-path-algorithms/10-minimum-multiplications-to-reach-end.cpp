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

/* Approach 1 (Dijkstra's Algorithm): */
class Solution {
  public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        int MOD = 1e5;
        int n = sz(arr);

        // BFS queue: (current_number, steps_taken)
        queue<pii> q;
        q.push({start, 0});

        // Track visited numbers to avoid cycles
        vi dist(1e5, INT_MAX);
        dist[start] = 0;

        // BFS to find minimum steps
        while (!q.empty()) {
            int node = q.front().ff;
            int steps = q.front().ss;
            q.pop();

            // Check if target reached
            if (node == end)
                return steps;

            // Try multiplying with each array element
            iterate(it, arr) {
                int num = (node * it) % MOD;

                // Visit unvisited numbers only
                if (dist[num] == INT_MAX) {
                    dist[num] = steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        // Target unreachable
        return -1;
    }
};

int main() {
    Solution obj;
    vi v = {2, 5, 7};
    cout << obj.minimumMultiplications(v, 3, 30) << endl;
    v = {3, 4, 65};
    cout << obj.minimumMultiplications(v, 7, 66175) << endl;
}

/*
Problem: Minimum Multiplications to reach End
*/