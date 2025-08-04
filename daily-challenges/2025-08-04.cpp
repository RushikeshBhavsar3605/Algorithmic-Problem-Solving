#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class Solution {
  public:
    int totalFruit(vector<int> &fruits) {
        unordered_map<int, int> mp;
        int best = 0;
        int low = 0;

        loop(high, 0, fruits.size()) {
            mp[fruits[high]]++;

            while (mp.size() > 2)
                if (mp[fruits[low]] == 1)
                    mp.erase(fruits[low++]);
                else
                    mp[fruits[low++]]--;

            best = max(best, high - low + 1);
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {0, 1, 2, 2};
    cout << obj.totalFruit(v);
    cout << endl;
    v = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << obj.totalFruit(v);
    return 0;
}

/*
Problem: Fruit Into Baskets
*/