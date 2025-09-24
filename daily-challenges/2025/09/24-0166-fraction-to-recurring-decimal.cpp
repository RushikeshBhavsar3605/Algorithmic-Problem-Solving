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

/* Approach 1 (Hashing): */
class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
        // Edge case: zero numerator always results in "0"
        if (numerator == 0)
            return "0";

        string result;
        // XOR to check if signs differ (one positive, one negative)
        if (numerator < 0 ^ denominator < 0)
            result += '-';

        // Convert to positive long long to avoid overflow during operations
        ll num = abs((ll)numerator);
        ll den = abs((ll)denominator);

        // Reduce fraction to lowest terms using GCD
        int g = __gcd(num, den);
        num /= g, den /= g;

        // Calculate integer part using division
        ll quo = num / den;
        ll rem = num % den;
        result += to_string(quo);

        // If no remainder, fraction is already a whole number
        if (rem == 0)
            return result;

        // Start decimal part
        result.pb('.');
        umap<ll, int> mp; // Maps remainder -> position in result string

        // Perform long division to find decimal digits
        while (rem != 0)
            if (mp.find(rem) != mp.end()) {
                // Cycle detected: remainder seen before, insert parentheses
                int len = mp[rem];
                result.insert(len, "(");
                result.pb(')');
                break;
            } else {
                // Track remainder position for cycle detection
                mp[rem] = sz(result);
                rem *= 10;       // Standard long division step
                quo = rem / den; // Next decimal digit
                rem = rem % den; // Update remainder
                result += to_string(quo);
            }

        return result;
    }
};

int main() {
    Solution obj;
    cout << obj.fractionToDecimal(1, 2) << endl;
    cout << obj.fractionToDecimal(2, 1) << endl;
    cout << obj.fractionToDecimal(4, 333) << endl;
}

/*
Problem: Fraction to Recurring Decimal
*/