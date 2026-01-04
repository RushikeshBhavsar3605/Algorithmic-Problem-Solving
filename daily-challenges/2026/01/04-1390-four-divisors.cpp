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

/* Approach 1 (Number Theory): */
class Solution {
  public:
    int sumFourDivisors(vector<int> &nums) {
        auto solve = [&](int num) {
            int sum = 0;
            int divisors = 0;

            for (int fact = 1; fact * fact <= num; fact++)
                if (num % fact == 0) {
                    int other = num / fact;

                    if (fact == other) {
                        divisors += 1;
                        sum += fact;
                    } else {
                        divisors += 2;
                        sum += fact + other;
                    }

                    if (divisors > 4)
                        return 0;
                }

            return divisors == 4 ? sum : 0;
        };

        int result = 0;
        iterate(num, nums)
            result += solve(num);

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {21, 4, 7};
    println(obj.sumFourDivisors(v));
    v = {21, 21};
    println(obj.sumFourDivisors(v));
    v = {1, 2, 3, 4, 5};
    println(obj.sumFourDivisors(v));
}

/*
Problem: Four Divisors
*/