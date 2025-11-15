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

/* Approach 1 (Sliding Window + Math): */
class Solution {
  public:
    int numberOfSubstrings(string s) {
        int n = sz(s);

        // Precompute next zero position from each index
        vi next_zero(n + 1);
        next_zero[n - 1] = n; // Sentinel: no zero after last position

        // Build next_zero array in reverse: for each index, store position of nearest '0' to the right
        revloop(i, n - 2, 0) {
            if (s[i + 1] == '0')
                next_zero[i] = i + 1;
            else
                next_zero[i] = next_zero[i + 1]; // Propagate from next position
        }

        int res = 0;

        // Try every possible left boundary
        loop(left, 0, n) {
            int zeroes = s[left] == '0' ? 1 : 0; // Count zeros starting from left
            int right = left;

            // Enumerate substrings by incrementing zero count (max √n zeros for valid substrings)
            while (zeroes * zeroes <= n) {
                int next_z = next_zero[right];       // Position of next zero
                int ones = (next_z - left) - zeroes; // Count of ones in (left, next_z)

                // If dominant ones constraint satisfied, count valid extensions
                if (ones >= zeroes * zeroes)
                    res += min(next_z - right, ones - zeroes * zeroes + 1);

                right = next_z; // Jump to next zero
                zeroes += 1;    // Increment zero count
                if (right == n) // No more zeros
                    break;
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    println(obj.numberOfSubstrings("00011"));
    println(obj.numberOfSubstrings("101101"));
}

/*
Problem: Count the Number of Substrings With Dominant Ones
*/