#include "template.hpp"

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;

        loop(i, 1, sz(prices))
            profit += max(0, prices[i] - prices[i - 1]);

        return profit;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {7, 1, 5, 3, 6, 4};
    auto res = obj.maxProfit(v);
    print(res);
    v = {1, 2, 3, 4, 5};
    res = obj.maxProfit(v);
    print(res);
    v = {7, 6, 4, 3, 1};
    res = obj.maxProfit(v);
    print(res);
    return 0;
}

/*
Problem: Best Time to Buy and Sell Stock II
*/