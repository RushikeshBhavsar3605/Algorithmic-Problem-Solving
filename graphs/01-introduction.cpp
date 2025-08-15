#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

/* Adjacency Matrix */
void adjacencyMatrix(int n, vvi &edges) {
    vvi adj(n, vi(n, 0));
    iterate(it, edges) {
        int u = it[0], v = it[1];
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove for directed graphs
    }

    iterate(it, adj) {
        iterate(i, it)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}
/*
Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/

/* Adjacency List */
void adjacencyList(int n, vvi &edges) {
    map<int, vi> adj;
    iterate(it, edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove for directed graphs
    }

    iterate(it, adj) {
        cout << it.first << " -> ";
        iterate(i, it.second)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}
/*
Time Complexity: O(n * n)
Space Complexity: O(n * n)
But efficient then Adjacency Matrix
*/

/* Adjacency Matrix for Weighted Graphs */
void adjacencyMatrixWeighted(int n, vvi &edges) {
    vvi adj(n, vi(n, 0));
    iterate(it, edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u][v] = w;
        adj[v][u] = w; // Remove for directed graphs
    }

    iterate(it, adj) {
        iterate(i, it)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
}

/* Adjacency List for Weighted Graphs */
void adjacencyListWeighted(int n, vvi &edges) {
    map<int, vector<pii>> adj;
    iterate(it, edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove for directed graphs
    }

    iterate(it, adj) {
        cout << it.first << " -> ";
        iterate(i, it.second)
            cout << "{" << i.first << ", " << i.second << "} ";
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n = 4;
    vvi v = {{0, 2}, {0, 3}, {1, 3}, {0, 1}, {2, 3}};

    adjacencyMatrix(n, v);
    adjacencyList(n, v);

    v = {{0, 2, 3}, {0, 3, 2}, {1, 3, 4}, {0, 1, 1}, {2, 3, 1}};
    adjacencyMatrixWeighted(n, v);
    adjacencyListWeighted(n, v);
    return 0;
}

/*
Problem:
*/