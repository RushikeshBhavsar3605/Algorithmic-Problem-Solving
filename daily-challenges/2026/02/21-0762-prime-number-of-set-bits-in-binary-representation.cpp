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

/* Approach 1 (Bit Manipulation): */
class Solution {
  public:
    int countPrimeSetBits(int left, int right) {
        // init:
        // primes → store all possible prime counts of set bits (max 20 for int range)
        uset<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
        // res → stores count of numbers whose set bit count is prime
        int res = 0;

        // loop: iterate through all numbers in range [left, right]
        loop(num, left, right + 1) {
            // compute: count number of set bits in current number
            int setBits = __builtin_popcount(num);

            // condition: if set bit count is prime → increment result
            if (primes.count(setBits))
                res++;
        }

        // return total valid numbers
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.countPrimeSetBits(6, 10) << endl;
    cout << obj.countPrimeSetBits(10, 15) << endl;
    return 0;
}

/*
Problem: Prime Number of Set Bits in Binary Representation
*/