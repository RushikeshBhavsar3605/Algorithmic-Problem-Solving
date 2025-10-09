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

/* Approach 1 (Tabulation): */
class Solution {
  public:
    long long minTime(vector<int> &skill, vector<int> &mana) {
        int n = sz(skill);
        int m = sz(mana);
        // finishTime[j] = earliest completion time after processing some potions up to skill index j
        vector<ll> finishTime(n, 0);

        // Process each "row" i (potion), where cell (i, j) takes time skill[j] * mana[i]
        loop(i, 0, m) {
            ll now = finishTime[0]; // rolling completion within current row
            int currPotion = mana[i];

            // Forward pass: enforce DP transition against top and left dependencies
            // now + skill[j-1]*currPotion = coming from left in current row
            // finishTime[j]               = coming from above (previous rows)
            loop(j, 1, n)
                now = max(now + skill[j - 1] * 1LL * currPotion, finishTime[j]);

            // Complete the last cell in the row
            finishTime[n - 1] = now + skill[n - 1] * currPotion;

            // Backward pass: reconstruct this row's finishTime by undoing per-step durations
            // Ensures finishTime[j] matches the DP-consistent timeline for row i
            revloop(j, n - 2, 0)
                finishTime[j] = finishTime[j + 1] - skill[j + 1] * currPotion;
        }

        return finishTime[n - 1]; // final completion time after all potions and skills
    }
};

int main() {
    Solution obj;
    vi skill = {1, 5, 2, 4};
    vi mana = {5, 1, 4, 2};
    println(obj.minTime(skill, mana));
    skill = {1, 1, 1};
    mana = {1, 1, 1};
    println(obj.minTime(skill, mana));
    skill = {1, 2, 3, 4};
    mana = {1, 2};
    println(obj.minTime(skill, mana));
}

/*
Problem: Find the Minimum Amount of Time to Brew Potions
*/