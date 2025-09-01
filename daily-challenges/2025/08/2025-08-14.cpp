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

class Solution {
  public:
    string largestGoodInteger(string num) {
        int count = 1;
        int maxi = -1;
        int curr = num[0] - '0';

        loop(i, 1, sz(num)) {
            if (num[i] == num[i - 1] && count < 3) {
                count++;
                curr = (curr * 10) + (num[i] - '0');
            } else {
                count = 1;
                curr = num[i] - '0';
            }

            if (count == 3)
                maxi = max(maxi, curr);
        }

        if (maxi == -1)
            return "";

        return maxi == 0 ? string(3, maxi + '0') : to_string(maxi);
    }
};

int main() {
    Solution obj;
    cout << obj.largestGoodInteger("6777133339") << endl;
    cout << obj.largestGoodInteger("2300019") << endl;
    cout << obj.largestGoodInteger("42352338") << endl;
    return 0;
}

/*
Problem: Largest 3-Same-Digit Number in String
*/