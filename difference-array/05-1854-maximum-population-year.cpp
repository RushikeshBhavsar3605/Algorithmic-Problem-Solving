#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    int maximumPopulation(vector<vector<int>> &logs) {
        vi diff(2051, 0);

        iterate(it, logs) {
            int left = it[0];
            int right = it[1];

            diff[left] += 1;
            diff[right] -= 1;
        }

        pii maxi = {diff[0], logs[0][0]};

        loop(i, 1, 2051) {
            diff[i] += diff[i - 1];

            if (maxi.ff < diff[i])
                maxi = {diff[i], i};
        }

        return maxi.ss;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1993, 1999}, {2000, 2010}};
    auto res = obj.maximumPopulation(v);
    print(res);
    v = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
    res = obj.maximumPopulation(v);
    print(res);
    return 0;
}

/*
Problem: Maximum Population Year
*/