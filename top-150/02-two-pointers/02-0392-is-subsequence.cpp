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
    bool solve(int i, int j, string &s, string &t, vvi &memo) {
        if (i == sz(s))
            return true;
        if (j == sz(t))
            return false;

        if (memo[i][j] != -1)
            return memo[i][j];

        bool take = 0;
        if (s[i] == t[j])
            take = solve(i + 1, j + 1, s, t, memo);

        bool notTake = solve(i, j + 1, s, t, memo);

        return memo[i][j] = take || notTake;
    }

  public:
    bool isSubsequence(string s, string t) {
        vvi memo(sz(s), vi(sz(t), -1));
        return solve(0, 0, s, t, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int n = sz(s);
        int m = sz(t);
        vvi dp(n + 1, vi(m + 1, 0));
        loop(i, 0, m + 1) dp[n][i] = 1;

        revloop(i, n - 1, 0) {
            revloop(j, m - 1, 0) {
                int take = 0;
                if (s[i] == t[j])
                    take = dp[i + 1][j + 1];
                int notTake = dp[i][j + 1];

                dp[i][j] = take || notTake;
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 3 (Space Optimization):
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int n = sz(s);
        int m = sz(t);
        vi curr(m + 1, 0);
        vi next(m + 1, 1);

        revloop(i, n - 1, 0) {
            curr[m] = 0;

            revloop(j, m - 1, 0) {
                int take = 0;
                if (s[i] == t[j])
                    take = next[j + 1];
                int notTake = curr[j + 1];

                curr[j] = take || notTake;
            }

            swap(curr, next);
        }

        return next[0];
    }
};
*/

/* Approach 4 (Two Pointer): */
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < sz(s) && j < sz(t)) {
            if (s[i] == t[j])
                i++;
            j++;
        }

        return i == sz(s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.isSubsequence("abc", "ahbgdc");
    print(res);
    res = obj.isSubsequence("axc", "ahbgdc");
    print(res);
    return 0;
}

/*
Problem: Is Subsequence
*/