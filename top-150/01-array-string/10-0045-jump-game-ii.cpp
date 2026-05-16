#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Type Aliases
// ==========================================
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

// N-dimensional vector
template <typename T, int N> struct nvec {
    using type = vector<typename nvec<T, N - 1>::type>;
};

template <typename T> struct nvec<T, 1> {
    using type = vector<T>;
};

template <typename T, int N> using nvec_t = typename nvec<T, N>::type;

// ==========================================
// Pair Helpers
// ==========================================
#define ff first
#define ss second

// ==========================================
// STL Helpers
// ==========================================
#define pb push_back
#define all(x) begin(x), end(x)

template <typename T> inline int sz(const T &x) { return static_cast<int>(x.size()); }

// ==========================================
// Unordered Containers
// ==========================================
template <typename K, typename V> using umap = unordered_map<K, V>;

template <typename T> using uset = unordered_set<T>;

// ==========================================
// Loop Macros
// ==========================================
#define loop(i, a, b) for (auto i = (a); i < (b); i++)
#define loop_le(i, a, b) for (auto i = (a); i <= (b); i++)
#define revloop(i, a, b) for (auto i = (a); i >= (b); i--)
#define iterate(x, a) for (auto &x : (a))

// ==========================================
// Min / Max Updaters
// ==========================================
template <typename T> inline void updateMin(T &a, const T &b) {
    if (b < a)
        a = b;
}

template <typename T> inline void updateMax(T &a, const T &b) {
    if (b > a)
        a = b;
}

// ==========================================
// Unique (sort + dedup)
// ==========================================
template <typename T> inline void uniq(T &v) {
    sort(all(v));
    v.erase(unique(all(v)), v.end());
}

// ==========================================
// Debug Utilities (OJ-safe)
// ==========================================
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

// ==========================================
// Universal Printers
// ==========================================
template <typename T> void print(T x) { cout << x << endl; }

template <typename T> void print(vector<T> &v) {
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}

template <typename T> void print(vector<vector<T>> &vv) {
    for (auto &v : vv) {
        for (auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

/* Approach 1 (Memoization):
class Solution {
  private:
    int solve(int idx, vi &nums, vi &memo) {
        if (idx == sz(nums) - 1)
            return 0;

        if (memo[idx] != -1)
            return memo[idx];

        int steps = INT_MAX;

        loop(jump, 1, nums[idx] + 1) {
            if (idx + jump >= sz(nums))
                continue;

            int next = solve(idx + jump, nums, memo);
            if (next != INT_MAX)
                updateMin(steps, next + 1);
        }

        return memo[idx] = steps;
    }

  public:
    int jump(vector<int> &nums) {
        vi memo(sz(nums), -1);

        return solve(0, nums, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int jump(vector<int> &nums) {
        int n = sz(nums);
        vi dp(n, INT_MAX);
        dp[n - 1] = 0;

        revloop(idx, n - 2, 0) {
            int steps = INT_MAX;

            loop(jump, 1, nums[idx] + 1) {
                if (idx + jump >= n)
                    continue;

                int next = dp[idx + jump];
                if (next != INT_MAX)
                    updateMin(steps, next + 1);
            }

            dp[idx] = steps;
        }

        return dp[0];
    }
};
*/

/* Approach 3 (Greedy): */
class Solution {
  public:
    int jump(vector<int> &nums) {
        int n = sz(nums);
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        loop(i, 0, n - 1) {
            updateMax(farthest, i + nums[i]);

            if (i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 3, 1, 1, 4};
    auto res = obj.jump(v);
    print(res);
    v = {2, 3, 0, 1, 4};
    res = obj.jump(v);
    print(res);
    return 0;
}

/*
Problem: Jump Game II
*/