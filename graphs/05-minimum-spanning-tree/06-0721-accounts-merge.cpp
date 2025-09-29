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

class DisjointSet {
  private:
    vi size, parent;

  public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        loop(i, 0, n + 1) parent[i] = i;
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

/* Approach 1 (Disjoint Set Union): */
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = sz(accounts);
        DisjointSet st(n);
        umap<string, int> mapMailNode;

        // Map each email to first account and union accounts with shared emails
        loop(i, 0, n) {
            loop(j, 1, sz(accounts[i])) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end())
                    mapMailNode[mail] = i;
                else
                    st.unionBySize(i, mapMailNode[mail]);
            }
        }

        // Group emails by their root parent account
        vector<string> mergeMail[n];
        iterate(it, mapMailNode) {
            string mail = it.ff;
            int node = st.findParent(it.ss);
            mergeMail[node].pb(mail);
        }

        // Build result with sorted emails for each merged account
        vector<vector<string>> result;
        loop(i, 0, n) {
            if (sz(mergeMail[i]) == 0)
                continue;

            sort(all(mergeMail[i]));
            vector<string> temp;
            temp.pb(accounts[i][0]); // Add account name

            iterate(it, mergeMail[i])
                temp.pb(it);

            result.pb(temp);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<string>> v = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                {"John", "johnsmith@mail.com", "john00@mail.com"},
                                {"Mary", "mary@mail.com"},
                                {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> result = obj.accountsMerge(v);
    iterate(it, result) {
        iterate(i, it) cout << i << " ";
        cout << endl;
    }
}

/*
Problem: Accounts Merge
*/