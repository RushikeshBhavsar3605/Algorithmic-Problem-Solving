#include "template.hpp"

/* Approach (Heap): */
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vi, greater<int>> minHeap;

        iterate(num, nums) {
            minHeap.push(num);

            if (sz(minHeap) > k)
                minHeap.pop();
        }

        return minHeap.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 2, 1, 5, 6, 4};
    auto res = obj.findKthLargest(v, 2);
    print(res);
    v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    res = obj.findKthLargest(v, 4);
    print(res);
    return 0;
}

/*
Problem: Kth Largest Element in an Array
*/