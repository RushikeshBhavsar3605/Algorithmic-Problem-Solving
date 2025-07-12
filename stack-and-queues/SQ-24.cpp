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

  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int best = 0;
        vi his(matrix[0].size(), 0);
        
        loop(i, 0, matrix.size()) {
            loop(j, 0, matrix[0].size())
                if (matrix[i][j] == '1')
                    his[j]++;
                else
                    his[j] = 0;
            
            best = max(best, largestRectangleArea(his));
        }

        return best;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> mat = {
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << obj.maximalRectangle(mat);
    return 0;
}

/*
Problem: Maximal Rectangle
*/