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

// =====================
// Universal Printers
// =====================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vec<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vec<vec<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Brute Force + Greedy):
class Solution {
  public:
    string findDifferentBinaryString(vector<string> &nums) {
        int n = sz(nums);
        sort(all(nums));
        string curr = string(n, '0');

        auto increment = [&]() {
            revloop(i, n - 1, 0) {
                if (curr[i] == '0') {
                    curr[i] = '1';
                    return;
                } else
                    curr[i] = '0';
            }
        };

        iterate(it, nums) {
            loop(i, 0, n)
                if (curr[i] != it[i])
                    return curr;

            increment();
        }

        return curr;
    }
};
*/

/* Approach 2 (Hashing Integers):
class Solution {
  public:
    string findDifferentBinaryString(vector<string> &nums) {
        uset<int> integers;
        iterate(num, nums)
            integers.insert(stoi(num, 0, 2));

        int n = sz(nums);
        loop(num, 0, n + 1)
            if (integers.find(num) == integers.end()) {
                string res = bitset<16>(num).to_string();
                return res.substr(16 - n);
            }

        return "";
    }
};
*/

/* Approach 3 (Cantor's Diagonal Argument): */
class Solution {
  public:
    string findDifferentBinaryString(vector<string> &nums) {
        string res;
        loop(i, 0, sz(nums)) {
            char curr = nums[i][i];
            res += curr == '0' ? '1' : '0';
        }

        return res;
    }
};

int main() {
    Solution obj;
    vec<string> v = {"01", "10"};
    auto res = obj.findDifferentBinaryString(v);
    print(res);
    v = {"00", "01"};
    res = obj.findDifferentBinaryString(v);
    print(res);
    v = {"111", "011", "001"};
    res = obj.findDifferentBinaryString(v);
    print(res);
    return 0;
}

/*
Problem: Find Unique Binary String
*/