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

/* Approach 1 (BFS):
class Solution {
  public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        q.push(s);

        set<string> vis;
        vis.insert(s);

        string result = s;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr < result)
                result = curr;

            string add = curr;
            for (int i = 1; i < sz(s); i += 2)
                add[i] = ((add[i] - '0' + a) % 10) + '0';

            if (!vis.count(add)) {
                q.push(add);
                vis.insert(add);
            }

            string rotate = curr;
            reverse(all(rotate));
            reverse(begin(rotate), begin(rotate) + b);
            reverse(begin(rotate) + b, end(rotate));

            if (!vis.count(rotate)) {
                q.push(rotate);
                vis.insert(rotate);
            }
        }

        return result;
    }
};
*/

/* Approach 2 (DFS): */
class Solution {
  private:
    string solve(string s, set<string> &vis, int a, int b) {
        int n = sz(s);

        if (vis.count(s))
            return s;

        vis.insert(s);

        string result = s;

        string add = s;
        for (int i = 1; i < sz(s); i += 2)
            add[i] = ((add[i] - '0' + a) % 10) + '0';
        updateMin(result, solve(add, vis, a, b));

        string rotate = s.substr(n - b) + s.substr(0, n - b);
        updateMin(result, solve(rotate, vis, a, b));

        return result;
    }

  public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> vis;
        return solve(s, vis, a, b);
    }
};

int main() {
    Solution obj;
    println(obj.findLexSmallestString("5525", 9, 2));
    println(obj.findLexSmallestString("74", 5, 1));
    println(obj.findLexSmallestString("0011", 4, 2));
}

/*
Problem: Lexicographically Smallest String After Applying Operations
*/