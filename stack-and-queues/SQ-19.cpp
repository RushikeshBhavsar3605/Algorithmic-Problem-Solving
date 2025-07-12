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
    int MOD = 1e9 + 7;

    vi findNSE(vi &arr) {
        vi result(arr.size(), 0);
        stack<int> st;

        revloop(i, arr.size() - 1, 0) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            result[i] = st.empty() ? arr.size() : st.top();

            st.push(i);
        }

        return result;
    }

    vi findPSE(vi &arr) {
        vi result(arr.size(), 0);
        stack<int> st;

        loop(i, 0, arr.size()) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return result;
    }

  public:
    int sumSubarrayMins(vector<int> &arr) {
        int result = 0;

        vi NSE = findNSE(arr);
        vi PSE = findPSE(arr);

        loop(i, 0, arr.size()) {
            int left = NSE[i] - i;
            int right = i - PSE[i];

            result = (result + 1LL * left * right * arr[i]) % MOD;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi arr = {3, 1, 2, 4};
    cout << obj.sumSubarrayMins(arr);
    return 0;
}

/*
Problem: Sum of Subarray Minimums
*/