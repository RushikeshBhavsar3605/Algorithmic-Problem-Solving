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

/*
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> pq; // {value, index}

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            if (i >= (k - 1)) {
                // Remove elements outside the current window
                while (i - pq.top().second >= k)
                    pq.pop();

                // Current max in the window
                result.push_back(pq.top().first);
            }
        }

        return result;
    }
};
*/

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> dq; // stores indices

        loop(i, 0, nums.size()) {
            // Remove indices out of current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Add max of current window
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {1, 3, -1, -3, 5, 3, 6, 7};
    vi res = obj.maxSlidingWindow(v, 3);
    iterate(it, res) cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Sliding Window Maximum
*/