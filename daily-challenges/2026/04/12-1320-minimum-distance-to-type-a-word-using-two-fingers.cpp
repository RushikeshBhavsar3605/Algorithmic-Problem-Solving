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
    int dist(int a, int b) {
        if (a == 26)
            return 0;

        int row1 = a / 6, col1 = a % 6;
        int row2 = b / 6, col2 = b % 6;

        return abs(row1 - row2) + abs(col1 - col2);
    }

    int solve(int idx, int finger1, int finger2, string &word, nvec_t<int, 3> &memo) {
        if (idx == sz(word))
            return 0;

        if (memo[idx][finger1][finger2] != -1)
            return memo[idx][finger1][finger2];

        int curr = word[idx] - 'A';

        int move1 = dist(finger1, curr) + solve(idx + 1, curr, finger2, word, memo);
        int move2 = dist(finger2, curr) + solve(idx + 1, finger1, curr, word, memo);

        return memo[idx][finger1][finger2] = min(move1, move2);
    }

  public:
    int minimumDistance(string word) {
        int n = sz(word);
        nvec_t<int, 3> memo(n, vvi(27, vi(27, -1)));

        return solve(0, 26, 26, word, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    int minimumDistance(string word) {
        int n = sz(word);
        nvec_t<int, 3> dp(n + 1, vvi(27, vi(27, 0)));

        auto dist = [&](int a, int b) {
            if (a == 26)
                return 0;

            int row1 = a / 6, col1 = a % 6;
            int row2 = b / 6, col2 = b % 6;

            return abs(row1 - row2) + abs(col1 - col2);
        };

        revloop(idx, n - 1, 0) {
            loop(finger1, 0, 27) {
                loop(finger2, 0, 27) {
                    int curr = word[idx] - 'A';

                    int move1 = dist(finger1, curr) + dp[idx + 1][curr][finger2];
                    int move2 = dist(finger2, curr) + dp[idx + 1][finger1][curr];

                    dp[idx][finger1][finger2] = min(move1, move2);
                }
            }
        }

        return dp[0][26][26];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    int minimumDistance(string word) {
        int n = sz(word);
        vvi curr(27, vi(27, 0));
        vvi next(27, vi(27, 0));

        auto dist = [&](int a, int b) {
            if (a == 26)
                return 0;

            int row1 = a / 6, col1 = a % 6;
            int row2 = b / 6, col2 = b % 6;

            return abs(row1 - row2) + abs(col1 - col2);
        };

        revloop(idx, n - 1, 0) {
            loop(finger1, 0, 27) {
                loop(finger2, 0, 27) {
                    int cur = word[idx] - 'A';

                    int move1 = dist(finger1, cur) + next[cur][finger2];
                    int move2 = dist(finger2, cur) + next[finger1][cur];

                    curr[finger1][finger2] = min(move1, move2);
                }
            }

            swap(curr, next);
        }

        return next[26][26];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.minimumDistance("CAKE");
    print(res);
    res = obj.minimumDistance("HAPPY");
    print(res);
    return 0;
}

/*
Problem: Minimum Distance to Type a Word Using Two Fingers
*/