#include "template.hpp"

/* Approach (Heap): */
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<pair<int, vi>> maxHeap;

        iterate(p, points) {
            int d = p[0] * p[0] + p[1] * p[1];
            maxHeap.push({d, p});

            if (sz(maxHeap) > k)
                maxHeap.pop();
        }

        vvi res;

        while (!maxHeap.empty()) {
            res.pb(maxHeap.top().ss);
            maxHeap.pop();
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 3}, {-2, 2}};
    auto res = obj.kClosest(v, 1);
    print(res);
    v = {{3, 3}, {5, -1}, {-2, 4}};
    res = obj.kClosest(v, 2);
    print(res);
    return 0;
}

/*
Problem: K Closest Points to Origin
*/