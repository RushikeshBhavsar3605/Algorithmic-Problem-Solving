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
    int subarrayBitwiseORs(vector<int> &arr) {
        set<int> result, prevOr;
        iterate(x, arr) {
            set<int> currOr;
            currOr.insert(x);
            iterate(y, prevOr)
                currOr.insert(y | x);

            result.insert(all(currOr));
            prevOr = currOr;
        }
        return result.size();
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 2};
    cout << obj.subarrayBitwiseORs(v);
    return 0;
}

/*
Problem: Bitwise ORs of Subarrays
*/