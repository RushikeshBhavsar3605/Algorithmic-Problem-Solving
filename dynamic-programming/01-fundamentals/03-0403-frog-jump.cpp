#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

/* Approach 1 (Recursion):
class Solution {
  private:
    bool solve(int idx, int effort, vi &stones, umap<int, int> &mp) {
        // Base case: reached last stone
        if (idx == sz(stones) - 1)
            return true;

        // Try k-1, k, k+1 jumps
        loop(i, -1, 2) {
            int newEffort = effort + i;
            if (newEffort <= 0) // Can't jump 0 or negative
                continue;

            int nextPos = stones[idx] + newEffort;
            if (mp.find(nextPos) == mp.end()) // Stone doesn't exist at nextPos
                continue;
            if (solve(mp[nextPos], newEffort, stones, mp))
                return true;
        }

        return false;
    }

  public:
    bool canCross(vector<int> &stones) {
        if (stones[1] != 1) // First jump must be exactly 1 unit
            return false;

        // Map: stone position -> stone index
        umap<int, int> mp;
        loop(i, 0, sz(stones))
            mp[stones[i]] = i;

        return solve(1, 1, stones, mp); // Start at stone 1 with jump size 1
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
    bool solve(int idx, int effort, vi &stones, umap<int, int> &mp, vvi &memo) {
        // Base case: reached last stone
        if (idx == sz(stones) - 1)
            return memo[idx][effort] = true;

        // Return cached result
        if (memo[idx][effort] != -1)
            return memo[idx][effort];

        // Try k-1, k, k+1 jumps
        loop(i, -1, 2) {
            int newEffort = effort + i;
            if (newEffort <= 0) // Can't jump 0 or negative
                continue;

            int nextPos = stones[idx] + newEffort;
            if (mp.find(nextPos) == mp.end()) // Stone doesn't exist at nextPos
                continue;
            if (solve(mp[nextPos], newEffort, stones, mp, memo))
                return memo[idx][effort] = true;
        }

        return memo[idx][effort] = false; // Cache and return
    }

  public:
    bool canCross(vector<int> &stones) {
        if (stones[1] != 1) // First jump must be exactly 1 unit
            return false;

        // Map: stone position -> stone index
        umap<int, int> mp;
        loop(i, 0, sz(stones))
            mp[stones[i]] = i;

        // memo[stone_idx][jump_size] = can reach end from here?
        vvi memo(sz(stones) + 1, vi(sz(stones) + 2, -1));
        return solve(1, 1, stones, mp, memo); // Start at stone 1 with jump size 1
    }
};
*/

/* Approach 3 (Tabulation): */
class Solution {
  public:
    bool canCross(vector<int> &stones) {
        int n = sz(stones);
        if (stones[1] != 1) // First jump must be exactly 1 unit
            return false;

        // Map: stone position -> stone index
        umap<int, int> mp;
        loop(i, 0, n)
            mp[stones[i]] = i;

        // dp[stone_idx][jump_size] = can reach this stone with this jump?
        vvi dp(n, vi(n + 2, false));
        dp[0][0] = true; // Start at stone 0 with no previous jump

        // Build forward: propagate reachable states
        loop(idx, 0, n) {
            loop(effort, 0, n + 1) {
                if (!dp[idx][effort]) // Skip unreachable states
                    continue;

                // Try k-1, k, k+1 jumps from current stone
                loop(i, -1, 2) {
                    int newEffort = effort + i;
                    if (newEffort <= 0) // Can't jump 0 or negative
                        continue;

                    int nextPos = stones[idx] + newEffort;
                    if (mp.find(nextPos) != mp.end()) // Mark next stone as reachable
                        dp[mp[nextPos]][newEffort] = true;
                }
            }
        }

        // Check if last stone is reachable with any jump size
        loop(effort, 0, n + 1)
            if (dp[n - 1][effort])
                return true;

        return false;
    }
};

int main() {
    Solution obj;
    vi v = {0, 1, 3, 5, 6, 8, 12, 17};
    println(obj.canCross(v));
    v = {0, 1, 2, 3, 4, 8, 9, 11};
    println(obj.canCross(v));
}

/*
Problem: Frog Jump
*/