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

/* Approach 1 (Naive):
class Solution {
  public:
    bool isPowerOfFour(int n) {
        loop(i, 0, 16)
            if ((1 << (i * 2)) == n)
                return true;

        return false;
    }
};
*/

/* Approach 2 (Math): */
class Solution {
  public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;

        while (n % 4 == 0)
            n /= 4;

        return n == 1;
    }
};

int main() {
    Solution obj;
    cout << obj.isPowerOfFour(16) << endl;
    cout << obj.isPowerOfFour(5) << endl;
    cout << obj.isPowerOfFour(1) << endl;
    return 0;
}

/*
Problem: Power of Four
*/