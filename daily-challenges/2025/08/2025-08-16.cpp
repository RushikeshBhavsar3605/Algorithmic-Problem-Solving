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
    int maximum69Number(int num) {
        string s = to_string(num);
        int maxNum = 0;
        bool change = false;

        iterate(it, s)
            if (it == '6' && !change) {
                maxNum = (maxNum * 10) + 9;
                change = !change;
            }
            else
                maxNum = (maxNum * 10) + (it - '0');

        return maxNum;
    }
};
*/

/* Approach 2 (Math): */
class Solution {
  public:
    int maximum69Number(int num) {
        int a = -1;
        for (int n = num, d = 0; n > 0; n /= 10, d++) {
            int r = n % 10;
            if (r == 6)
                a = d;
        }

        return (a == -1) ? num : int(num + 3 * pow(10, a));
    }
};

int main() {
    Solution obj;
    cout << obj.maximum69Number(9669) << endl;
    return 0;
}

/*
Problem: Maximum 69 Number
*/