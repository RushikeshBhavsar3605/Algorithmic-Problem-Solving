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

class DSU {
  private:
    vi parent, size;

  public:
    DSU(int n) : parent(n), size(n, 1) {
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

    void mergeSets(int a, int b) {
        a = findRoot(a);
        b = findRoot(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }
};

class Solution {
  private:
  public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries) {
        DSU uf(c + 1);
        iterate(it, connections)
            uf.mergeSets(it[0], it[1]);

        vector<set<int>> members(c + 1);
        loop(i, 1, c + 1)
            members[uf.findRoot(i)].insert(i);

        vector<bool> active(c + 1, true);
        vector<int> result;

        iterate(it, queries) {
            int type = it[0], x = it[1];
            if (type == 1)
                if (active[x])
                    result.push_back(x);
                else {
                    auto &s = members[uf.findRoot(x)];
                    result.push_back(s.empty() ? -1 : *s.begin());
                }
            else if (active[x]) {
                active[x] = false;
                members[uf.findRoot(x)].erase(x);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vvi connections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vvi queries = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
    vi res = obj.processQueries(5, connections, queries);
    iterate(it, res) cout << it << " ";
    return 0;
}

/*
Problem:
*/