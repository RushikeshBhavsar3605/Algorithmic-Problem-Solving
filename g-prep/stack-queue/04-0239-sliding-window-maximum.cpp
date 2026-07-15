#include "template.hpp"

/* Approach (Deque): */
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = sz(nums);
        deque<int> dq;

        vi res;
        int left = 0;

        loop(right, 0, n) {
            while (!dq.empty() && dq.front() <= right - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[right])
                dq.pop_back();

            dq.push_back(right);

            if (right >= k - 1)
                res.pb(nums[dq.front()]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = obj.maxSlidingWindow(v, 3);
    print(res);
    v = {1};
    res = obj.maxSlidingWindow(v, 1);
    print(res);
    return 0;
}

/*
Problem: Sliding Window Maximum
*/