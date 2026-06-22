#include "template.hpp"

/* Approach (Heap): */
class Solution {
  public:
    bool isPossible(vector<int> &target) {
        ll sum = accumulate(all(target), 0LL);

        priority_queue<ll> maxHeap;
        iterate(it, target) maxHeap.push(it);

        while (!maxHeap.empty() && maxHeap.top() != 1) {
            ll val = maxHeap.top();
            maxHeap.pop();

            ll remain = sum - val;
            if (remain >= val || remain == 0)
                return false;

            ll newVal = val % remain;
            if (newVal == 0)
                newVal = remain;

            sum = remain + newVal;
            maxHeap.push(newVal);
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    // vi v = {9, 3, 5};
    vi v = {1, 1000};
    auto res = obj.isPossible(v);
    print(res);
    v = {1, 1, 1, 2};
    res = obj.isPossible(v);
    print(res);
    v = {8, 5};
    res = obj.isPossible(v);
    print(res);
    return 0;
}

/*
Problem: Construct Target Array With Multiple Sums
*/