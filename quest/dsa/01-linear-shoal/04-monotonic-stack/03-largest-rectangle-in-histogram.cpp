#include "template.hpp"

/* Approach 1 (Monotonic Stack):
class Solution {
  private:
    vi getPrevSmall(vi &heights, int n) {
        stack<int> st({0});
        vi res(n);

        loop(i, 0, n) {
            while (st.top() != 0 && heights[st.top() - 1] >= heights[i])
                st.pop();

            res[i] = st.top();

            st.push(i + 1);
        }

        return res;
    }

    vi getNextSmall(vi &heights, int n) {
        stack<int> st({n + 1});
        vi res(n);

        revloop(i, n - 1, 0) {
            while (st.top() != n + 1 && heights[st.top() - 1] >= heights[i])
                st.pop();

            res[i] = st.top();

            st.push(i + 1);
        }

        return res;
    }

  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = sz(heights);
        vi prevSmall = getPrevSmall(heights, n);
        vi nextSmall = getNextSmall(heights, n);
        int maxi = 0;

        loop(i, 0, n) {
            int leftArea = i - prevSmall[i] - 1;
            int rightArea = nextSmall[i] - i - 1;

            int area = heights[i] * (leftArea + rightArea + 1);
            updateMax(maxi, area);
        }

        return maxi;
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = sz(heights);
        stack<int> st;
        int maxi = 0;

        loop(i, 0, n + 1) {
            int currHeight = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.top()] > currHeight) {
                int prevHeight = heights[st.top()];
                st.pop();

                int leftSmaller = (st.empty() ? -1 : st.top());
                int width = i - leftSmaller - 1;
                updateMax(maxi, prevHeight * width);
            }

            st.push(i);
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 1, 5, 6, 2, 3};
    auto res = obj.largestRectangleArea(v);
    print(res);
    v = {2, 4};
    res = obj.largestRectangleArea(v);
    print(res);
    v = {2, 1, 2};
    res = obj.largestRectangleArea(v);
    print(res);
    return 0;
}

/*
Problem: Largest Rectangle in Histogram
*/