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

/* Approach 1 (Binary Search): */
class Solution {
  private:
    int findPairs(int spell, vi &potions, ll success) {
        int n = sz(potions);
        int low = 0, high = n - 1;

        while (low <= high) {
            ll mid = low + ((high - low) >> 1);

            if ((ll)spell * potions[mid] >= success)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return n - low;
    }

  public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        int n = sz(spells);
        sort(all(potions));
        vi result;

        loop(i, 0, n)
            result.pb(findPairs(spells[i], potions, success));

        return result;
    }
};

int main() {
    Solution obj;
    vi spells = {5, 1, 3};
    vi potions = {1, 2, 3, 4, 5};
    dump(obj.successfulPairs(spells, potions, 7));
    spells = {3, 1, 2};
    potions = {8, 5, 8};
    dump(obj.successfulPairs(spells, potions, 16));
}

/*
Problem: Successful Pairs of Spells and Potions
*/