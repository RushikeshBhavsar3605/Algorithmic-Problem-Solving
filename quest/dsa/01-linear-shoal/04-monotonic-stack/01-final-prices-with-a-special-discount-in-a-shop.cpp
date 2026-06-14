#include "template.hpp"

/* Approach (Monotonic stack): */
class Solution {
  public:
    vector<int> finalPrices(vector<int> &prices) {
        int n = sz(prices);
        vi res(n);
        stack<int> st;

        revloop(i, n - 1, 0) {
            while (!st.empty() && st.top() > prices[i])
                st.pop();

            res[i] = prices[i];
            if (!st.empty())
                res[i] -= st.top();

            st.push(prices[i]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {8, 4, 6, 2, 3};
    auto res = obj.finalPrices(v);
    print(res);
    v = {1, 2, 3, 4, 5};
    res = obj.finalPrices(v);
    print(res);
    v = {10, 1, 1, 6};
    res = obj.finalPrices(v);
    print(res);
    return 0;
}

/*
Problem: Final Prices With a Special Discount in a Shop
*/