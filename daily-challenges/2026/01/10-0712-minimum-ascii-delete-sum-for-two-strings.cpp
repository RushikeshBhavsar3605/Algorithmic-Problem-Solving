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

/* Approach 1 (Memoization): */
class Solution {
  public:
    int minimumDeleteSum(string s1, string s2) {
        vvi memo(sz(s1) + 1, vi(sz(s2) + 1, -1));

        function<int(int, int)> solve = [&](int idx1, int idx2) -> int {
            if (idx1 == sz(s1) && idx2 == sz(s2))
                return 0;

            if (memo[idx1][idx2] != -1)
                return memo[idx1][idx2];

            if (idx1 == sz(s1))
                return memo[idx1][idx2] = solve(idx1, idx2 + 1) + s2[idx2];
            else if (idx2 == sz(s2))
                return memo[idx1][idx2] = solve(idx1 + 1, idx2) + s1[idx1];

            if (s1[idx1] == s2[idx2])
                return memo[idx1][idx2] = solve(idx1 + 1, idx2 + 1);

            int deleteS1 = solve(idx1 + 1, idx2) + s1[idx1];
            int deleteS2 = solve(idx1, idx2 + 1) + s2[idx2];

            return memo[idx1][idx2] = min(deleteS1, deleteS2);
        };

        return solve(0, 0);
    }
};

int main() {
    Solution obj;
    println(obj.minimumDeleteSum("sea", "eat"));
    println(obj.minimumDeleteSum("delete", "leet"));
}

/*
Problem: Minimum ASCII Delete Sum for Two Strings
*/