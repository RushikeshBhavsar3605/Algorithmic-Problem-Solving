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

/* Approach 1 (Memoization):
class Solution {
  private:
    int n;
    int memo[100001][3];

    int binarySearch(vvi &events, int endTime) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (events[mid][0] > endTime)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left != 0 ? left : n;
    }

    int solve(vvi &events, int i, int count) {
        if (count == 2 || i >= n)
            return 0;

        if (memo[i][count] != -1)
            return memo[i][count];

        int nextValidIdx = binarySearch(events, events[i][1]);
        int take = solve(events, nextValidIdx, count + 1) + events[i][2];
        int notTake = solve(events, i + 1, count);

        return memo[i][count] = max(take, notTake);
    }

  public:
    int maxTwoEvents(vector<vector<int>> &events) {
        n = sz(events);
        sort(all(events));
        memset(memo, -1, sizeof(memo));

        return solve(events, 0, 0);
    }
};
*/

/* Approach 2 (Heap): */
class Solution {
  public:
    int maxTwoEvents(vector<vector<int>> &events) {
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        sort(all(events));

        int maxVal = 0, maxSum = 0;

        iterate(event, events) {
            while (!min_heap.empty() && min_heap.top().ff < event[0]) {
                updateMax(maxVal, min_heap.top().ss);
                min_heap.pop();
            }

            updateMax(maxSum, maxVal + event[2]);
            min_heap.push({event[1], event[2]});
        }

        return maxSum;
    }
};

int main() {
    Solution obj;
    vvi e = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    println(obj.maxTwoEvents(e));
    e = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5}};
    println(obj.maxTwoEvents(e));
    e = {{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};
    println(obj.maxTwoEvents(e));
}

/*
Problem: Two Best Non-Overlapping Events
*/