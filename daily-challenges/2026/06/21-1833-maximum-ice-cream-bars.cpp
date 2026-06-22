#include "template.hpp"

/* Appraoch 1 (Heap):
class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        priority_queue<int, vi, greater<int>> minHeap;
        iterate(cost, costs) minHeap.push(cost);

        int res = 0;
        while (!minHeap.empty() && coins >= minHeap.top()) {
            res++;
            coins -= minHeap.top();
            minHeap.pop();
        }

        return res;
    }
};
*/

/* Approach 2 (Counting Sort): */
class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        int maxi = *max_element(all(costs));
        vi freq(maxi + 1, 0);
        iterate(cost, costs) freq[cost]++;

        int cnt = 0;
        loop(x, 1, maxi + 1) {
            int f = freq[x];
            if (f == 0)
                continue;

            int buy = min(coins / x, f);
            if (buy == 0)
                break;

            cnt += buy;
            coins -= buy * x;
        }

        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, 2, 4, 1};
    auto res = obj.maxIceCream(v, 7);
    print(res);
    v = {10, 6, 8, 7, 7, 8};
    res = obj.maxIceCream(v, 5);
    print(res);
    v = {1, 6, 3, 1, 2, 5};
    res = obj.maxIceCream(v, 20);
    print(res);
    return 0;
}

/*
Problem: Maximum Ice Cream Bars
*/