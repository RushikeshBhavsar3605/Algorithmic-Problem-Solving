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
    long long minimumDifference(vector<int> &nums) {
        priority_queue<int> leftMaxHeap;                    // Max-heap to track largest elements in left part
        priority_queue<int, vi, greater<int>> rightMinHeap; // Min-heap to track smallest elements in right part
        vector<long long> rightMaxSum(nums.size(), 0);      // Stores min sum of n elements from right part
        long long partitionSize = nums.size() / 3;
        long long minDiff = LONG_LONG_MAX;

        long long currRightSum = 0;
        // Process right side (from end to n), keep smallest n elements using rightMinHeap
        revloop(i, nums.size() - 1, partitionSize) {
            rightMinHeap.push(nums[i]);
            currRightSum += nums[i];

            if (rightMinHeap.size() > partitionSize) {
                currRightSum -= rightMinHeap.top(); // Remove largest among the smallest
                rightMinHeap.pop();
            }

            if (rightMinHeap.size() == partitionSize)
                rightMaxSum[i] = currRightSum;      // Save sum of smallest n elements from i to end
        }

        long long currLeftSum = 0;
        // Process left side (from 0 to size - n), keep largest n elements using leftMaxHeap
        loop(i, 0, nums.size() - partitionSize) {
            leftMaxHeap.push(nums[i]);
            currLeftSum += nums[i];

            if (leftMaxHeap.size() > partitionSize) {
                currLeftSum -= leftMaxHeap.top(); // Remove largest
                leftMaxHeap.pop();
            }

            // Compute min diff when both left and right have exactly n elements
            if (leftMaxHeap.size() == partitionSize)
                minDiff = min(minDiff, currLeftSum - rightMaxSum[i + 1]);
        }

        return minDiff;
    }
};

int main() {
    Solution obj;
    vi v = {3, 1, 2};
    cout << obj.minimumDifference(v) << endl;
    return 0;
}

/*
Problem: Minimum Difference in Sums After Removal of Elements
*/