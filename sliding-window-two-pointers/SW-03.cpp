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
        unordered_map<int, int> mp; // stores fruit type and its count in current window
        int best = 0;
        int low = 0;

        loop(high, 0, fruits.size()) {
            mp[fruits[high]]++; // add current fruit to basket

            // shrink window if more than 2 types of fruits
            while (mp.size() > 2 && mp.find(fruits[low]) != mp.end())
                if (mp[fruits[low]] == 1)
                    mp.erase(fruits[low++]); // remove type if only one left
                else
                    mp[fruits[low++]]--; // decrement count and move window

            best = max(best, high - low + 1); // update max window size
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 1};
    cout << obj.totalFruit(v) << endl;
    v = {0, 1, 2, 2};
    cout << obj.totalFruit(v) << endl;
    v = {1, 2, 3, 2, 2};
    cout << obj.totalFruit(v) << endl;
    v = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << obj.totalFruit(v) << endl;
    return 0;
}

/*
Problem: Fruit Into Baskets
*/