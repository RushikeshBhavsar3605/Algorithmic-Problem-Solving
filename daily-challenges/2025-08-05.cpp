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
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        loop(i, 0, sz(fruits))
            loop(j, 0, sz(baskets))
                if (baskets[j] >= fruits[i]) {
                    fruits[i] = -1;
                    baskets[j] = -1;
                    break;
                }

        int count = 0;
        loop(i, 0, sz(fruits))
            if (fruits[i] != -1)
                count++;

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
Problem: Fruits Into Baskets II
*/