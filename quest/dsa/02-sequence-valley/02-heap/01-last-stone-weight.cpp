#include "template.hpp"

/* Approach 1 (Heap): */
class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> maxHeap(all(stones));

        while (sz(maxHeap) > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop();
            int stone2 = maxHeap.top(); maxHeap.pop();

            if (stone1 != stone2)
                maxHeap.push(stone1 - stone2);
        }

        return !maxHeap.empty() ? maxHeap.top() : 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 7, 4, 1, 8, 1};
    auto res = obj.lastStoneWeight(v);
    print(res);
    v = {1};
    res = obj.lastStoneWeight(v);
    print(res);
    return 0;
}

/*
Problem: Last Stone Weight
*/