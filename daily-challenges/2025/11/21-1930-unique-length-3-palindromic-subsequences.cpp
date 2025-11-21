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

/* Approach 1 (Recursion):
class Solution {
  private:
    bool isValid(string s, uset<string> &st) {
        int n = sz(s);
        if (n != 3)
            return false;

        loop(i, 0, n) {
            if (s[i] != s[n - i - 1])
                return false;
        }

        st.insert(s);
        return true;
    }

    void solve(int idx, string &s, uset<string> &st, string curr = "") {
        int n = sz(s);
        if (idx == n) {
            isValid(curr, st);
            return;
        }

        solve(idx + 1, s, st, curr + s[idx]);
        solve(idx + 1, s, st, curr);
    }

  public:
    int countPalindromicSubsequence(string s) {
        uset<string> st;
        solve(0, s, st);
        return sz(st);
    }
};
*/

/* Approach 2 (Count Letters In-Between): */
class Solution {
  public:
    int countPalindromicSubsequence(string s) {
        uset<char> letters;
        iterate(ch, s) letters.insert(ch);

        int result = 0;
        iterate(letter, letters) {
            int i = -1;
            int j = 0;

            loop(k, 0, sz(s)) {
                if (s[k] == letter) {
                    if (i == -1)
                        i = k;
                    j = k;
                }
            }

            uset<char> between;
            loop(k, i + 1, j) between.insert(s[k]);

            result += sz(between);
        }

        return result;
    }
};

int main() {
    Solution obj;
    println(obj.countPalindromicSubsequence("aabca"));
    println(obj.countPalindromicSubsequence("adc"));
    println(obj.countPalindromicSubsequence("bbcbaba"));
}

/*
Problem: Unique Length-3 Palindromic Subsequences
*/