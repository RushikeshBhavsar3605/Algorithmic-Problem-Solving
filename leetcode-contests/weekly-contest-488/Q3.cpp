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
  public:
    long long countSubarrays(vector<int> &nums, long long k) {
        int n = sz(nums);
        ll total = (long)n * (n + 1) / 2;
        ll invalid = 0;

        deque<int> maxD;
        deque<int> minD;
        int left = 0;

        loop(right, 0, n) {
            while (!maxD.empty() && nums[maxD.back()] <= nums[right])
                maxD.pop_back();
            maxD.push_back(right);

            while (!minD.empty() && nums[minD.back()] >= nums[right])
                minD.pop_back();
            minD.push_back(right);

            while (!maxD.empty() && !minD.empty()) {
                ll diff = (ll)nums[maxD.front()] - nums[minD.front()];
                ll cost = diff * (right - left + 1);
                if (cost <= k)
                    break;

                invalid += (n - right);
                left++;

                if (maxD.front() < left)
                    maxD.pop_front();
                if (minD.front() < left)
                    minD.pop_front();
            }
        }

        return total - invalid;
    }
};

int main() {
    Solution obj;
    vec<int> v = {1, 3, 2};
    cout << obj.countSubarrays(v, 4) << endl;
    v = {5, 5, 5, 5};
    cout << obj.countSubarrays(v, 0) << endl;
    v = {1, 2, 3};
    cout << obj.countSubarrays(v, 0) << endl;
    return 0;
}

/*
Problem: Count Subarrays With Cost Less Than or Equal to K
*/