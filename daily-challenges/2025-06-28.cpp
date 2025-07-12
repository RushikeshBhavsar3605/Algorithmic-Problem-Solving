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
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        // Min-heap: {value, index}
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        loop(i, 0, nums.size()) {
            pq.emplace(nums[i], i);
            if (pq.size() > k)
                pq.pop();
        }

        // Extract remaining k elements
        vector<pii> topk;
        while (!pq.empty()) {
            topk.push_back(pq.top());
            pq.pop();
        }

        // Sort by original index
        sort(all(topk), [](const pii &a, const pii &b) {
            return a.second < b.second;
        });

        vi result;
        iterate(it, topk)
            result.push_back(it.first);

        return result;
    }
};

int main() {
    Solution obj;
    vi nums = {2, 1, 3, 3};
    vi result = obj.maxSubsequence(nums, 2);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Find Subsequence of Length K With the Largest Sum
*/