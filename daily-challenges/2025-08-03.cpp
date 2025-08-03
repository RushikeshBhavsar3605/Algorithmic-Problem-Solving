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
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
        int n = fruits.size();

        vi prefixSum(n);
        vi positions(n);

        loop(i, 0, n) {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFruits = 0;

        loop(dist, 0, k / 2 + 1) {
            // Case-1 - moved dist steps to the left
            int remain = k - 2 * dist;
            int i = startPos - dist;
            int j = startPos + remain;

            int left = lower_bound(all(positions), i) - begin(positions);
            int right = upper_bound(all(positions), j) - begin(positions) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }

            // Case-2 - moved dist steps to the right
            // remain = k - 2 * dist;
            i = startPos - remain;
            j = startPos + dist;

            left = lower_bound(all(positions), i) - begin(positions);
            right = upper_bound(all(positions), j) - begin(positions) - 1;

            if (left <= right) {
                int total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxFruits = max(maxFruits, total);
            }
        }

        return maxFruits;
    }
};

int main() {
    Solution obj;
    vvi v = {{2, 8}, {6, 3}, {8, 6}};
    cout << obj.maxTotalFruits(v, 5, 4);
    return 0;
}

/*
Problem: Maximum Fruits Harvested After at Most K Steps
*/