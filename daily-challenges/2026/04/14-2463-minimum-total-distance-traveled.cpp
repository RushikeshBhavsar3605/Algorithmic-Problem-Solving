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
    ll solve(int robotIdx, int positionsIdx, vi &robot, vi &positions, vvl &memo) {
        if (robotIdx == sz(robot))
            return 0;
        if (positionsIdx == sz(positions))
            return LONG_LONG_MAX;

        if (memo[robotIdx][positionsIdx] != -1)
            return memo[robotIdx][positionsIdx];

        ll take = solve(robotIdx + 1, positionsIdx + 1, robot, positions, memo);
        if (take != LONG_LONG_MAX)
            take += abs(robot[robotIdx] - positions[positionsIdx]);

        ll skip = solve(robotIdx, positionsIdx + 1, robot, positions, memo);

        return memo[robotIdx][positionsIdx] = min(take, skip);
    }

  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        sort(all(robot));
        sort(all(factory));

        vi positions;
        loop(i, 0, sz(factory)) {
            int pos = factory[i][0];
            int limit = factory[i][1];

            loop(j, 0, limit) positions.pb(pos);
        }

        vvl memo(sz(robot), vl(sz(positions), -1));
        return solve(0, 0, robot, positions, memo);
    }
};
*/

/* Approach 2 (Tabulation):
class Solution {
  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        sort(all(robot));
        sort(all(factory));

        vi positions;
        iterate(it, factory)
            loop(i, 0, it[1])
                positions.pb(it[0]);

        int n = sz(robot);
        int m = sz(positions);
        vvl dp(n + 1, vl(m + 1, 0));
        loop(i, 0, n)
            dp[i][m] = LONG_LONG_MAX;

        revloop(robotIdx, n - 1, 0) {
            revloop(positionsIdx, m - 1, 0) {
                ll take = dp[robotIdx + 1][positionsIdx + 1];
                if (take != LONG_LONG_MAX)
                    take += abs(robot[robotIdx] - positions[positionsIdx]);

                ll skip = dp[robotIdx][positionsIdx + 1];

                dp[robotIdx][positionsIdx] = min(take, skip);
            }
        }

        return dp[0][0];
    }
};
*/

/* Approach 3 (Space Optimization): */
class Solution {
  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
        sort(all(robot));
        sort(all(factory));

        vi positions;
        iterate(it, factory) loop(i, 0, it[1]) positions.pb(it[0]);

        int n = sz(robot);
        int m = sz(positions);
        vl curr(m + 1, 0);
        vl next(m + 1, 0);

        revloop(robotIdx, n - 1, 0) {
            curr[m] = LONG_LONG_MAX;

            revloop(positionsIdx, m - 1, 0) {
                ll take = next[positionsIdx + 1];
                if (take != LONG_LONG_MAX)
                    take += abs(robot[robotIdx] - positions[positionsIdx]);

                ll skip = curr[positionsIdx + 1];

                curr[positionsIdx] = min(take, skip);
            }

            swap(curr, next);
        }

        return next[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi r = {0, 4, 6};
    vvi f = {{2, 2}, {6, 2}};
    auto res = obj.minimumTotalDistance(r, f);
    print(res);
    r = {1, -1};
    f = {{-2, 1}, {2, 1}};
    res = obj.minimumTotalDistance(r, f);
    print(res);
    return 0;
}

/*
Problem: Minimum Total Distance Traveled
*/