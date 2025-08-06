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

/* Approach 1 (Square Root Decomposition): */
class Solution {
  public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        int n = sz(baskets);
        int m = sqrt(n);
        int section = (n + m - 1) / m;
        int count = 0;

        vi maxV(section);
        loop(i, 0, n)
            maxV[i / m] = max(maxV[i / m], baskets[i]);

        iterate(fruit, fruits) {
            int sec;
            int unset = 1;

            loop(sec, 0, section) {
                if (maxV[sec] < fruit)
                    continue;

                int choose = 0;
                maxV[sec] = 0;
                loop(i, 0, m) {
                    int pos = sec * m + i;
                    if (pos < n && baskets[pos] >= fruit && !choose) {
                        baskets[pos] = 0;
                        choose = 1;
                    }
                    if (pos < n)
                        maxV[sec] = max(maxV[sec], baskets[pos]);
                }

                unset = 0;
                break;
            }

            count += unset;
        }

        return count;
    }
};

int main() {
    Solution obj;
    vi v1 = {4, 2, 5};
    vi v2 = {3, 5, 4};
    cout << obj.numOfUnplacedFruits(v1, v2);
    return 0;
}

/*
Problem: Fruits Into Baskets III
*/