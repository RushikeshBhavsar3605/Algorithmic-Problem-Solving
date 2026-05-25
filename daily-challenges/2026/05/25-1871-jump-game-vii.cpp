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

/* Approach 1 (Memoization) (TLE):
class Solution {
  private:
    int dfs(int i, string &s, int minJump, int maxJump, int n, vi &memo) {
        if (i == n - 1)
            return true;

        if (memo[i] != -1)
            return memo[i];

        loop(j, i + minJump, min(i + maxJump + 1, n)) {
            if (s[j] == '0' && dfs(j, s, minJump, maxJump, n, memo))
                return memo[i] = true;
        }

        return memo[i] = false;
    }

  public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = sz(s);
        vi memo(n, -1);

        return dfs(0, s, minJump, maxJump, n, memo);
    }
};
*/

/* Approach 2 (Tabulation): */
class Solution {
  public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = sz(s);
        vi prefix(n + 1, 0);

        vi dp(n, 0);
        dp[0] = 1;

        loop(i, 0, n) {
            if (s[i] == '0') {
                int left = max(0, i - maxJump);
                int right = i - minJump;

                if (right >= 0) {
                    int reachableCount = prefix[right + 1] - prefix[left];
                    dp[i] = (reachableCount > 0);
                }
            }

            prefix[i + 1] = prefix[i] + dp[i];
        }

        return dp[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.canReach("011010", 2, 3);
    print(res);
    res = obj.canReach("01101110", 2, 3);
    print(res);
    return 0;
}

/*
Problem: Jump Game VII
*/