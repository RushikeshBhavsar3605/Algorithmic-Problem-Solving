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
    int solve(int idx, vvi &nums, int activity) {
        int n = sz(nums);
        if (idx == n)
            return 0;

        int running = 0, fighting = 0, learning = 0;

        if (activity != 1)
            running = nums[idx][0] + solve(idx + 1, nums, 1);
        if (activity != 2)
            fighting = nums[idx][1] + solve(idx + 1, nums, 2);
        if (activity != 3)
            learning = nums[idx][2] + solve(idx + 1, nums, 3);

        return max({running, fighting, learning});
    }

  public:
    int maximumPoints(vector<vector<int>> &arr) {
        return solve(0, arr, 0);
    }
};
*/

/* Approach 2 (Memoization):
class Solution {
  private:
    int solve(int idx, vvi &nums, int activity, vvi &memo) {
        int n = sz(nums);
        if (idx == n)
            return 0;

        if (memo[idx][activity] != -1)
            return memo[idx][activity];

        int running = 0, fighting = 0, learning = 0;

        if (activity != 1)
            running = nums[idx][0] + solve(idx + 1, nums, 1, memo);
        if (activity != 2)
            fighting = nums[idx][1] + solve(idx + 1, nums, 2, memo);
        if (activity != 3)
            learning = nums[idx][2] + solve(idx + 1, nums, 3, memo);

        return memo[idx][activity] = max({running, fighting, learning});
    }

  public:
    int maximumPoints(vector<vector<int>> &arr) {
        int n = sz(arr);
        vvi memo(n, vi(4, -1));
        return solve(0, arr, 0, memo);
    }
};
*/

/* Approach 3 (Tabulation):
class Solution {
  public:
    int maximumPoints(vector<vector<int>> &arr) {
        int n = sz(arr);
        vvi dp(n + 1, vi(3, 0));

        revloop(idx, n - 1, 0) {
            loop(activity, 0, 3) {
                int running = 0, fighting = 0, learning = 0;

                if (activity != 0)
                    running = arr[idx][0] + dp[idx + 1][0];
                if (activity != 1)
                    fighting = arr[idx][1] + dp[idx + 1][1];
                if (activity != 2)
                    learning = arr[idx][2] + dp[idx + 1][2];

                dp[idx][activity] = max({running, fighting, learning});
            }
        }

        int maxi = 0;
        iterate(it, dp[0])
            updateMax(maxi, it);

        return maxi;
    }
};
*/

/* Approach 4 (Space Optimization): */
class Solution {
  public:
    int maximumPoints(vector<vector<int>> &arr) {
        int n = sz(arr);
        vi next(3, 0);

        revloop(idx, n - 1, 0) {
            vi curr(3, 0);

            loop(activity, 0, 3) {
                int running = 0, fighting = 0, learning = 0;

                if (activity != 0)
                    running = arr[idx][0] + next[0];
                if (activity != 1)
                    fighting = arr[idx][1] + next[1];
                if (activity != 2)
                    learning = arr[idx][2] + next[2];

                curr[activity] = max({running, fighting, learning});
            }

            next = curr;
        }

        return *max_element(all(next));
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    println(obj.maximumPoints(v));
    v = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    println(obj.maximumPoints(v));
    v = {{4, 2, 6}};
    println(obj.maximumPoints(v));
}

/*
Problem: Geek's Training
*/