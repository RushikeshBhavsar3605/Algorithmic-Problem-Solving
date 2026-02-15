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

/* Approach 1 (Bit Manipulation + Simulation): */
class Solution {
  public:
    string addBinary(string a, string b) {
        // init: result string, pointers at end of both strings, carry
        string res = "";
        int i = sz(a) - 1;
        int j = sz(b) - 1;
        int carry = 0;

        // loop: process until both strings and carry are exhausted
        while (i >= 0 || j >= 0 || carry) {
            // init: start sum with carry
            int sum = carry;

            // add current bit from string a (if exists)
            if (i >= 0)
                sum += a[i--] - '0';

            // add current bit from string b (if exists)
            if (j >= 0)
                sum += b[j--] - '0';

            // update: new carry for next iteration
            carry = sum / 2;

            // append: current result bit (sum % 2)
            res += to_string(sum % 2);
        }

        // final step: reverse since bits were added from LSB to MSB
        reverse(all(res));
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.addBinary("11", "1") << endl;
    cout << obj.addBinary("1010", "1011") << endl;
    return 0;
}

/*
Problem: Add Binary
*/