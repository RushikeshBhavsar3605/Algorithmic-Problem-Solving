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

class Solution {
  private:
    multiset<ll> l, r;

  public:
    long long minimumCost(vector<int> &nums, int k, int dist) {
        int n = sz(nums);
        k--;

        ll curr = nums[0];
        loop_le(i, 1, dist + 1)
            curr += nums[i], l.insert(nums[i]);

        while (sz(l) > k) {
            curr -= *l.rbegin();
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }

        ll res = curr;
        loop(i, dist + 2, n) {
            if (l.find(nums[i - dist - 1]) != l.end()) {
                curr -= nums[i - dist - 1];
                l.erase(l.find(nums[i - dist - 1]));
            } else
                r.erase(r.find(nums[i - dist - 1]));

            if (nums[i] < *l.rbegin()) {
                curr += nums[i];
                l.insert(nums[i]);
            } else
                r.insert(nums[i]);

            while (sz(l) < k) {
                curr += *r.begin();
                l.insert(*r.begin());
                r.erase(r.find(*r.begin()));
            }

            while (sz(l) > k) {
                curr -= *l.rbegin();
                r.insert(*l.rbegin());
                l.erase(l.find(*l.rbegin()));
            }

            updateMin(res, curr);
        }

        return res;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 3, 2, 6, 4, 2};
    cout << obj.minimumCost(v, 3, 3) << endl;
    v = {10, 1, 2, 2, 2, 1};
    cout << obj.minimumCost(v, 4, 3) << endl;
    v = {10, 8, 18, 9};
    cout << obj.minimumCost(v, 3, 1) << endl;
    return 0;
}

/*
Problem: Divide an Array Into Subarrays With Minimum Cost II
*/