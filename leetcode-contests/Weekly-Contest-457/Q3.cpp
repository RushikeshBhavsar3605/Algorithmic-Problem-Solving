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

class UnionFind {
  private:
    vi parent, size;
    int components;

  public:
    int count() { return components; }
    UnionFind(int n) : parent(n), size(n, 1), components(n) {
        iota(all(parent), 0);
    }

    int findRoot(int x) {
        int root = x;
        while (parent[root] != root)
            root = parent[root];

        while (x != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    bool mergeSets(int a, int b) {
        a = findRoot(a);
        b = findRoot(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        components--;
        return true;
    }
};

class Solution {
  public:
    int minTime(int n, vector<vector<int>> &edges, int k) {
        UnionFind uf(n);
        iterate(it, edges) uf.mergeSets(it[0], it[1]);

        if (uf.count() >= k)
            return 0;

        sort(all(edges), [](auto &a, auto &b) {
            return a[2] > b[2];
        });

        UnionFind uff(n);

        int components = n;
        int result = -1;
        int i = 0;
        
        while (i < edges.size()) {
            int type = edges[i][2];
            if (components >= k)
                result = type;

            int j = i;
            while (j < edges.size() && edges[j][2] == type) {
                if (uff.mergeSets(edges[j][0], edges[j][1]))
                    components--;

                j++;
            }

            if (components < k)
                break;

            i = j;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi edges = {{0, 1, 3}};
    cout << obj.minTime(2, edges, 2) << endl;
    edges = {{0, 1, 2}, {1, 2, 4}};
    cout << obj.minTime(3, edges, 3) << endl;
    edges = {{0, 2, 5}};
    cout << obj.minTime(3, edges, 2) << endl;
    edges = {{2, 0, 4242}, {2, 1, 7212}};
    cout << obj.minTime(3, edges, 2) << endl;
    return 0;
}

/*
Problem:
*/