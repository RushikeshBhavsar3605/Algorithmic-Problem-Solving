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

/* Approach 1 (String Compression Stack): */
class Solution {
  public:
    // Removes any block of exactly k consecutive ')' that is immediately preceded
    // by at least k '(' by deleting those k matched pairs.
    string removeSubstring(string s, int k) {
        vector<pii> st; // run-length stack: (char, count); pii == pair<char,int>

        iterate(ch, s) {
            // Compress consecutive identical characters.
            if (!st.empty() && st.back().ff == ch)
                st.back().ss++;
            else
                st.pb({ch, 1});

            // If the last two groups look like: '(' with count >= k followed by
            // ')' with count exactly k, remove k matched pairs.
            int n = sz(st);
            if (n >= 2
                && (st[n - 2].ff == '(' && st[n - 2].ss >= k)
                && (st[n - 1].ff == ')' && st[n - 1].ss == k)) {
                st[n - 2].ss -= k; // consume k '('
                st.pop_back();     // remove the k ')' group entirely

                // If '(' group count becomes zero, drop that group as well.
                if (st.back().ss == 0)
                    st.pop_back();
            }
        }

        // Reconstruct the final string from run-length groups.
        string result = "";
        iterate(it, st)
            result += string(it.ss, it.ff);

        return result;
    }
};

int main() {
    Solution obj;
    println(obj.removeSubstring("(())", 1));
    println(obj.removeSubstring("(()(", 1));
    println(obj.removeSubstring("((()))()()()", 3));
}

/*
Problem: Remove K-Balanced Substrings
*/