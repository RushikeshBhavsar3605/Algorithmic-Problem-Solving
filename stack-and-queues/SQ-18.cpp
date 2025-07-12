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
  public:
    int trap(vector<int> &height) {
        stack<int> st;
        int result = 0;

        loop(i, 0, height.size()) {
            int curr = height[i];

            while (!st.empty() && height[st.top()] < curr) {
                int poppedIdx = st.top();
                st.pop();

                if (!st.empty()) {
                    int heightVal = min(height[st.top()], curr) - height[poppedIdx];
                    int length = i - st.top() - 1;
                    result += heightVal * length;
                }
            }

            st.push(i);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi height = {4, 2, 0, 3, 2, 5};
    cout << obj.trap(height);
    return 0;
}

/*
Problem: Trapping Rain Water
*/