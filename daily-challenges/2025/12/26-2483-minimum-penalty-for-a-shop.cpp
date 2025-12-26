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

/* Approach 1 (Prefix/Suffix): */
class Solution {
  public:
    int bestClosingTime(string customers) {
        int n = sz(customers);

        int remainingNoPenalty = count(all(customers), 'N');

        int earliestClosingHour = n;
        int minimumPenalty = remainingNoPenalty;

        int currentYesPenalty = 0;
        int suffixYesPenalty = 0;

        revloop(i, n - 1, 0) {
            if (customers[i] == 'Y')
                currentYesPenalty++;
            else
                remainingNoPenalty--;

            if (i != n - 1)
                currentYesPenalty += suffixYesPenalty;

            int totalPenalty = currentYesPenalty + remainingNoPenalty;

            if (totalPenalty <= minimumPenalty) {
                minimumPenalty = totalPenalty;
                earliestClosingHour = i;
            }

            suffixYesPenalty = currentYesPenalty;
            currentYesPenalty = 0;
        }

        return earliestClosingHour;
    }
};

int main() {
    Solution obj;
    println(obj.bestClosingTime("YYNY"));
    println(obj.bestClosingTime("NNNNN"));
    println(obj.bestClosingTime("YYYY"));
}

/*
Problem: Minimum Penalty for a Shop
*/