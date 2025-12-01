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

/* Approach 1 (Binary Search on Answers with Greedy Feasibility Check): */
class Solution {
  private:
    // Greedy feasibility check: Can we run 'computers' for 'time' minutes?
    bool isPossible(vi &batteries, ll time, int computers) {
        ll totalTime = 0;

        // Each battery contributes min(capacity, time)
        // Cap at 'time' because battery is stuck in one computer during execution
        iterate(battery, batteries)
            totalTime += min((ll)battery, time);

        // Resource pooling: total supply >= total demand
        // Batteries can be swapped freely, so only aggregate matters
        return totalTime >= time * computers;
    }

  public:
    long long maxRunTime(int n, vector<int> &batteries) {
        // Binary search on answer: maximize runtime
        ll low = 0, high = 1e14;

        while (low <= high) {
            ll mid = low + ((high - low) >> 1);

            // If time 'mid' is feasible, try larger time
            if (isPossible(batteries, mid, n))
                low = mid + 1;
            else
                high = mid - 1;
        }

        // 'high' is the largest feasible time
        return high;
    }
};
/*
isPossible() logic:
- We cap the values of batteries to `time` because the remaining power from `battery` larger then `time` is unused, as
the `battery` greater then equal to `time` is allocated to one `computer` through out the execution
- We take sum of remaining batteries (each less then `time`) and check wheather they justify `time` to serve remaining
computers or not?
- This approach will work because all remaining values from `batteries` is either less then `time` or equal to `time`
hence we will always compute for remaining `computers` and `batteries` sum with each less then `time`
*/

int main() {
    Solution obj;
    vi v = {3, 3, 3};
    println(obj.maxRunTime(2, v));
    v = {1, 1, 1, 1};
    println(obj.maxRunTime(2, v));
    v = {1, 100};
    println(obj.maxRunTime(2, v));
}

/*
Problem: Maximum Running Time of N Computers
*/