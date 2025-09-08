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

/* Approach 1 (Depth First Search):
class Solution {
  private:
    bool dfs(int node, vi &vis, vi &pathVis, stack<int> &st, umap<int, vi> &adj) {
        vis[node] = pathVis[node] = 1;

        iterate(it, adj[node])
            if (!vis[it]) {
                if (!dfs(it, vis, pathVis, st, adj))
                    return false;
            }
            else if (pathVis[it])
                return false;

        pathVis[node] = 0;
        st.push(node);
        return true;
    }

    pair<bool, vi> topoSort(int n, umap<int, vi> &adj) {
        vi vis(n, 0), pathVis(n, 0);
        stack<int> st;

        loop(i, 0, n)
            if (!vis[i])
                if (!dfs(i, vis, pathVis, st, adj))
                    return {false, {}};

        vi result;
        while (!st.empty()) {
            result.pb(st.top());
            st.pop();
        }

        return {true, result};
    }

  public:
    string findOrder(vector<string> &words) {
        int n = 0;
        iterate(word, words)
            iterate(ch, word)
                updateMax(n, ch - 'a' + 1);

        umap<int, vi> adj;
        loop(i, 0, n) adj[i];

        loop(i, 0, sz(words) - 1) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(sz(s1), sz(s2));
            int ptr = 0;

            while (ptr < len) {
                int ch1 = s1[ptr] - 'a', ch2 = s2[ptr] - 'a';
                if (ch1 != ch2) {
                    adj[ch1].pb(ch2);
                    break;
                }
                ptr++;
            }

            if (ptr == len && sz(s1) > sz(s2))
                return "";
        }

        pair<bool, vi> res = topoSort(n, adj);
        if (!res.first)
            return "";

        vi topo = res.second;

        string result;
        iterate(it, topo)
            result += char(it + 'a');

        return result;
    }
};
*/

/* Approach 2 (Breadth First Search) */
class Solution {
  private:
    vi topoSort(umap<int, vi> &adj) {
        int n = sz(adj);
        vi indeg(n, 0);

        loop(i, 0, n)
            iterate(it, adj[i])
                indeg[it]++;

        queue<int> q;
        loop(i, 0, n)
            if (indeg[i] == 0)
                q.push(i);

        vi topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.pb(node);

            iterate(it, adj[node])
                if (--indeg[it] == 0)
                    q.push(it);
        }

        return topo;
    }

  public:
    string findOrder(vector<string> &words) {
        int n = 0;
        iterate(word, words)
            iterate(ch, word)
                updateMax(n, ch - 'a' + 1);

        umap<int, vi> adj;
        loop(i, 0, n)
            adj[i];

        loop(i, 0, sz(words) - 1) {
            string s1 = words[i], s2 = words[i + 1];
            int len = min(sz(s1), sz(s2));
            int ptr = 0;

            while (ptr < len) {
                int ch1 = s1[ptr] - 'a', ch2 = s2[ptr] - 'a';
                if (ch1 != ch2) {
                    adj[ch1].pb(ch2);
                    break;
                }
                ptr++;
            }

            if (ptr == len && sz(s1) > sz(s2))
                return "";
        }

        vi topo = topoSort(adj);

        string result;
        iterate(it, topo)
            result += char(it + 'a');

        return n == sz(result) ? result : "";
    }
};

int main() {
    Solution obj;
    vector<string> v = {"baa", "abcd", "abca", "cab", "cad"};
    cout << obj.findOrder(v);
    return 0;
}

/*
Problem:
*/