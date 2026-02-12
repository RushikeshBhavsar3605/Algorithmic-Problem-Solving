#include <bits/stdc++.h>
using namespace std;

// =====================
// Type Aliases
// =====================
using ll = long long;

template <typename T> using vec = vector<T>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

// =====================
// STL Helpers
// =====================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// =====================
// Unordered Containers
// =====================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// =====================
// Loop Macros
// =====================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// =====================
// Min / Max Updaters
// =====================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// =====================
// Unique (sort + dedup)
// =====================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// =====================
// Debug Utilities (OJ-safe)
// =====================
#define LOCAL
#ifdef LOCAL

template <typename T> void dump(const T &a, const char *name) {
    cerr << name << " = ";
    for (const auto &x : a)
        cerr << x << ' ';
    cerr << '\n';
}

template <typename T> void dump2D(const T &a, const char *name) {
    cerr << name << ":\n";
    for (const auto &row : a) {
        for (const auto &x : row)
            cerr << x << ' ';
        cerr << '\n';
    }
}

#define DUMP(x) dump(x, #x)
#define DUMP2D(x) dump2D(x, #x)

#else
#define DUMP(x)
#define DUMP2D(x)
#endif

/* Approach 1 (Brute Force with Frequency Counting): */
class Solution {
  public:
    int longestBalanced(string s) {
        // init: length of string and answer
        int n = sz(s);
        int maxi = 0;

        // helper: check if all non-zero frequencies are equal
        auto checkBalanced = [&](vec<int> &freq) {
            // init: store common frequency
            int common = 0;

            // loop: iterate over all 26 lowercase characters
            loop(i, 0, 26) {
                // skip characters not present in substring
                if (freq[i] == 0)
                    continue;

                // first non-zero frequency becomes baseline
                if (common == 0)
                    common = freq[i];
                // if mismatch found → not balanced
                else if (freq[i] != common)
                    return false;
            }

            // all non-zero frequencies matched
            return true;
        };

        // outer loop: fix starting index
        loop(i, 0, n) {
            // init: frequency array for current substring
            vec<int> freq(26, 0);

            // inner loop: expand substring ending at j
            loop(j, i, n) {
                // update: include current character
                freq[s[j] - 'a']++;

                // condition: check if substring is balanced
                if (checkBalanced(freq))
                    updateMax(maxi, j - i + 1); // update: maximize length
            }
        }

        // return: maximum balanced substring length
        return maxi;
    }
};

int main() {
    Solution obj;
    cout << obj.longestBalanced("abbac") << endl;
    cout << obj.longestBalanced("zzabccy") << endl;
    cout << obj.longestBalanced("aba") << endl;
    return 0;
}

/*
Problem: Longest Balanced Substring I
*/