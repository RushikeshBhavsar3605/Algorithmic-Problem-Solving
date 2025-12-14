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

/* Approach 1 (Memoization): */
class Solution {
  private:
    const int MOD = 1e9 + 7;

    int count(int index, int seats, string &corridor, vvi &cache) {
        if (index == sz(corridor))
            return seats == 2 ? 1 : 0;

        if (cache[index][seats] != -1)
            return cache[index][seats];

        int result = 0;

        if (seats == 2) {
            if (corridor[index] == 'S')
                result = count(index + 1, 1, corridor, cache);
            else
                result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;
        } else {
            if (corridor[index] == 'S')
                result = count(index + 1, seats + 1, corridor, cache);
            else
                result = count(index + 1, seats, corridor, cache);
        }

        return cache[index][seats] = result;
    }

  public:
    int numberOfWays(string corridor) {
        vvi cache(sz(corridor), vi(3, -1));

        return count(0, 0, corridor, cache);
    }
};

int main() {
    Solution obj;
    println(obj.numberOfWays("SSPPSPS"));
    println(obj.numberOfWays("PPSPSP"));
    println(obj.numberOfWays("S"));
}

/*
Problem: Number of Ways to Divide a Long Corridor
*/