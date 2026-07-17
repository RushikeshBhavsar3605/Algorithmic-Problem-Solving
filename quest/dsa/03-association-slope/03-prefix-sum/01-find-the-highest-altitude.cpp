#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int largestAltitude(vector<int> &gain) {
        int maxi = 0, curr = 0;

        iterate(it, gain) {
            curr += it;
            updateMax(maxi, curr);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {-5, 1, 5, 0, -7};
    auto res = obj.largestAltitude(v);
    print(res);
    v = {-4, -3, -2, -1, 4, 3, 2};
    res = obj.largestAltitude(v);
    print(res);
    return 0;
}

/*
Problem: Find the Highest Altitude
*/