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

template <typename Node> void print(Node *head) {
    Node *curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

/* Approach (Dynamic Programming): */
class Solution {
  private:
    int dfs(int idx, vi &nums, int d, int n, vi &jumps) {
        if (jumps[idx] != 0)
            return jumps[idx];

        jumps[idx] = 1;

        revloop(i, idx - 1, max(0, idx - d)) {
            if (nums[i] < nums[idx]) {
                int next = dfs(i, nums, d, n, jumps);
                updateMax(jumps[idx], next + 1);
            } else
                break;
        }

        loop(i, idx + 1, min(n, idx + d + 1)) {
            if (nums[i] < nums[idx]) {
                int next = dfs(i, nums, d, n, jumps);
                updateMax(jumps[idx], next + 1);
            } else
                break;
        }

        return jumps[idx];
    }

  public:
    int maxJumps(vector<int> &arr, int d) {
        int n = sz(arr);
        vi jumps(n, 0);

        loop(i, 0, n)
            if (!jumps[i])
                dfs(i, arr, d, n, jumps);

        return *max_element(all(jumps));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    auto res = obj.maxJumps(v, 2);
    print(res);
    v = {3, 3, 3, 3, 3};
    res = obj.maxJumps(v, 3);
    print(res);
    v = {7, 6, 5, 4, 3, 2, 1};
    res = obj.maxJumps(v, 1);
    print(res);
    return 0;
}

/*
Problem: Jump Game V
*/