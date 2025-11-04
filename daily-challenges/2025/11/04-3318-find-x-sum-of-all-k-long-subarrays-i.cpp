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

/* Approach 1 (Naive): */
class Solution {
  public:
    vector<int> findXSum(vector<int> &nums, int k, int x) {
        int n = sz(nums);
        vi result;
        loop(i, 0, n - k + 1) {
            umap<int, int> cnt;
            loop(j, i, i + k)
                cnt[nums[j]]++;

            vector<pii> freq;
            iterate(it, cnt)
                freq.emplace_back(it.ss, it.ff);
            sort(all(freq), greater<pii>());

            int xsum = 0;
            for (int j = 0; j < x && j < sz(freq); j++)
                xsum += freq[j].ff * freq[j].ss;
            result.pb(xsum);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 2, 2, 3, 4, 2, 3};
    dump(obj.findXSum(v, 6, 2));
    v = {3, 8, 7, 8, 7, 5};
    dump(obj.findXSum(v, 2, 2));
}

/*
Problem: Find X-Sum of All K-Long Subarrays I
*/