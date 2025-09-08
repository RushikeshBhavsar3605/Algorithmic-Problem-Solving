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

/* Approach 1 (Floyd Warshall Algorithm): */
class Solution {
  public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        // Initialize distance matrix with infinity
        vvi dist(n, vi(n, INT_MAX));

        // Set direct edge weights in both directions (undirected graph)
        iterate(edge, edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        // Distance from city to itself is 0
        loop(i, 0, n)
            dist[i][i] = 0;

        // Floyd-Warshall algorithm to find shortest paths between all pairs
        loop(k, 0, n)
            loop(i, 0, n)
                loop(j, 0, n)
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        updateMin(dist[i][j], dist[i][k] + dist[k][j]);

        // Find city with minimum reachable cities within threshold
        int countCity = n;
        int cityNo = -1;

        loop(city, 0, n) {
            int count = 0;

            // Count cities within distance threshold
            loop(adjCity, 0, n)
                if (dist[city][adjCity] <= distanceThreshold)
                    count++;

            // Update result (prefer higher indexed city in case of tie)
            if (count <= countCity) {
                countCity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    cout << obj.findTheCity(4, v, 4) << endl;
    v = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    cout << obj.findTheCity(5, v, 2) << endl;
}

/*
Problem: Find the City With the Smallest Number of Neighbors at a Threshold Distance
*/