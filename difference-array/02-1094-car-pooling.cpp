#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        vi trip(1001, 0);

        iterate(it, trips) {
            int cnt = it[0];
            int left = it[1];
            int right = it[2];

            trip[left] += cnt;
            trip[right] -= cnt;
        }

        if (trip[0] > capacity)
            return false;

        loop(i, 1, 1001) {
            trip[i] += trip[i - 1];

            if (trip[i] > capacity)
                return false;
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{2, 1, 5}, {3, 3, 7}};
    auto res = obj.carPooling(v, 4);
    print(res);
    res = obj.carPooling(v, 5);
    print(res);
    v = {{2, 1, 5}, {3, 5, 7}};
    res = obj.carPooling(v, 3);
    print(res);
    return 0;
}

/*
Problem: Car Pooling
*/