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

/* Approach 1 (Sorting):
class Solution {
  public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        sort(all(happiness), greater<int>());

        ll result = 0;
        loop(i, 0, k)
            result += max(0, happiness[i] - i);

        return result;
    }
};
*/

/* Approach 2 (Heap): */
class Solution {
  public:
    long long maximumHappinessSum(vector<int> &happiness, int k) {
        priority_queue<int, vi, greater<int>> minHeap;

        iterate(it, happiness) {
            if (sz(minHeap) < k)
                minHeap.push(it);
            else {
                if (minHeap.top() < it) {
                    minHeap.pop();
                    minHeap.push(it);
                }
            }
        }

        ll result = 0;
        int idx = sz(minHeap) - 1;
        while (!minHeap.empty()) {
            result += max(0, minHeap.top() - idx--);
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3};
    println(obj.maximumHappinessSum(v, 2));
    v = {1, 1, 1, 1};
    println(obj.maximumHappinessSum(v, 2));
    v = {2, 3, 4, 5};
    println(obj.maximumHappinessSum(v, 1));
}

/*
Problem: Maximize Happiness of Selected Children
*/