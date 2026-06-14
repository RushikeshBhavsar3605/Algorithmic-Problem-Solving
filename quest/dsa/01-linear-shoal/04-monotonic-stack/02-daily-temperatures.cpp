#include "template.hpp"

/* Approach (Monotonic Stack): */
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = sz(temperatures);
        stack<int> st;
        vi res(n, 0);

        revloop(i, n - 1, 0) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();

            if (!st.empty())
                res[i] = st.top() - i;

            st.push(i);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res = obj.dailyTemperatures(v);
    print(res);
    v = {30, 40, 50, 60};
    res = obj.dailyTemperatures(v);
    print(res);
    v = {30, 60, 90};
    res = obj.dailyTemperatures(v);
    print(res);
    return 0;
}

/*
Problem: Daily Temperatures
*/