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
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        unordered_map<int, int> count1, count2;
        int minVal = basket1[0];
        loop(i, 0, basket1.size()) {
            count1[basket1[i]]++;
            minVal = min(minVal, basket1[i]);

            count2[basket2[i]]++;
            minVal = min(minVal, basket2[i]);
        }

        vi toSwap;

        iterate(it, count1) {
            int cost = it.first;
            int occ1 = it.second, occ2 = count2[it.first];
            int diff = abs(occ1 - occ2);

            if (diff % 2 == 1)
                return -1;
            diff /= 2;

            while (diff--)
                toSwap.push_back(cost);

            count1[cost] = count2[cost] = 0;
        }

        iterate(it, count2) {
            int cost = it.first;
            int occ1 = count1[it.first], occ2 = it.second;
            int diff = abs(occ1 - occ2);

            if (diff % 2 == 1)
                return -1;
            diff /= 2;

            while (diff--)
                toSwap.push_back(cost);

            count1[cost] = count2[cost] = 0;
        }

        sort(all(toSwap));

        ll result = 0;
        loop(i, 0, toSwap.size() / 2)
            result += min(2LL * minVal, 1LL * toSwap[i]);

        return result;
    }
};

int main() {
    Solution obj;
    vi b1 = {4, 2, 2, 2};
    vi b2 = {1, 4, 1, 2};
    cout << obj.minCost(b1, b2) << endl;
    b1 = {2, 3, 4, 1};
    b2 = {3, 2, 5, 1};
    cout << obj.minCost(b1, b2) << endl;
    b1 = {4, 4, 4, 4, 3};
    b2 = {5, 5, 5, 5, 3};
    cout << obj.minCost(b1, b2) << endl;
    return 0;
}

/*
Problem: Rearranging Fruits
*/