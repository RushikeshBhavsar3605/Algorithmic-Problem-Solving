#include "template.hpp"

/* Approach (Heap): */
class Solution {
  public:
    int eatenApples(vector<int> &apples, vector<int> &days) {
        priority_queue<pii, nvec_t<pii, 1>, greater<pii>> minHeap;

        int n = sz(apples);
        int res = 0;

        for (int day = 0; day < n || !minHeap.empty(); day++) {
            if (day < n && apples[day] > 0)
                minHeap.push({day + days[day], apples[day]});

            while (!minHeap.empty() && minHeap.top().ff <= day)
                minHeap.pop();

            if (!minHeap.empty()) {
                auto [expiry, cnt] = minHeap.top();
                minHeap.pop();

                res++;

                if (--cnt)
                    minHeap.push({expiry, cnt});
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi a = {1, 2, 3, 5, 2};
    vi d = {3, 2, 1, 4, 2};
    auto res = obj.eatenApples(a, d);
    print(res);
    a = {3, 0, 0, 0, 0, 2};
    d = {3, 0, 0, 0, 0, 2};
    res = obj.eatenApples(a, d);
    print(res);
    return 0;
}

/*
Problem: Maximum Number of Eaten Apples
*/