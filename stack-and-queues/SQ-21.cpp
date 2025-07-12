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
    vi findNext(vi &arr, bool isSmall) {
        vi result(arr.size(), 0);
        stack<int> st;

        revloop(i, arr.size() - 1, 0) {
            while (!st.empty() && ((isSmall && arr[st.top()] >= arr[i]) || (!isSmall && arr[st.top()] <= arr[i])))
                st.pop();

            result[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }

        return result;
    }

    vi findPrevious(vi &arr, bool isSmall) {
        vi result(arr.size(), 0);
        stack<int> st;

        loop(i, 0, arr.size()) {
            while (!st.empty() && ((isSmall && arr[st.top()] > arr[i]) || (!isSmall && arr[st.top()] < arr[i])))
                st.pop();

            result[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return result;
    }

    long long sumSubarray(vector<int> &arr, int isMin) {
        long long result = 0;

        vi NSE = findNext(arr, isMin);
        vi PSE = findPrevious(arr, isMin);

        loop(i, 0, arr.size()) {
            int left = NSE[i] - i;
            int right = i - PSE[i];

            result = (result + 1LL * left * right * arr[i]);
        }

        return result;
    }

  public:
    long long subArrayRanges(vector<int> &nums) {
        long long maxi = sumSubarray(nums, false);
        long long mini = sumSubarray(nums, true);
        long long result = maxi - mini;
        return result;
    }
};

int main() {
    Solution obj;
    vi nums = {4, -2, -3, 4, 1};
    cout << obj.subArrayRanges(nums);
    return 0;
}

/*
Problem: Sum of Subarray Ranges
*/