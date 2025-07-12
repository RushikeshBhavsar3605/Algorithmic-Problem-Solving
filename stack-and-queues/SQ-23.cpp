#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class Solution {
  private:
    // Next Smaller Element to the right
    vi NSE(vi nums) {
        int n = nums.size();
        vi result(n, 0);
        stack<int> st;
        st.push(n); // sentinel index beyond last

        revloop(i, n - 1, 0) {
            while (st.top() != n && nums[st.top()] >= nums[i])
                st.pop();

            result[i] = st.top(); // index of next smaller element

            st.push(i);
        }

        return result;
    }

    // Previous Smaller Element to the left
    vi PSE(vi nums) {
        int n = nums.size();
        vi result(nums.size(), 0);
        stack<int> st;
        st.push(-1); // sentinel index before first

        loop(i, 0, nums.size()) {
            while (st.top() != -1 && nums[st.top()] >= nums[i])
                st.pop();

            result[i] = st.top(); // index of previous smaller element

            st.push(i);
        }

        return result;
    }

  public:
    int largestRectangleArea(vector<int> &heights) {
        vi next = NSE(heights);
        vi prev = PSE(heights);
        int best = 0;

        loop(i, 0, heights.size()) {
            int area = next[i] - prev[i] - 1; // width between next and prev smaller
            best = max(best, heights[i] * area);
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {2, 1, 5, 6, 2, 3};
    cout << obj.largestRectangleArea(v) << endl;
    v = {2, 4};
    cout << obj.largestRectangleArea(v) << endl;
    v = {2, 1, 2};
    cout << obj.largestRectangleArea(v) << endl;
    return 0;
}

/*
Problem: Largest Rectangle in Histogram
*/