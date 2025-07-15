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

/* Approach 1 (Binary Search):
class MedianFinder {
  private:
    int getIndex(int num) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (nums[mid] < num)
                left = mid + 1;
            else if (nums[mid] > num)
                right = mid - 1;
            else
                return mid;
        }

        return left;
    }

  public:
    vi nums;

    MedianFinder() {}

    void addNum(int num) {
        int index = getIndex(num);
        nums.insert(begin(nums) + index, num);
    }

    double findMedian() {
        if (nums.size() & 1)
            return nums[nums.size() >> 1];
        else {
            double num1 = nums[nums.size() >> 1];
            double num2 = nums[(nums.size() >> 1) - 1];
            return (num1 + num2) / 2.0;
        }
    }
};
*/

/* Approach 2 (Heap): */
class MedianFinder {
  public:
    // maxHeap ↘️ smaller half (largest on top)
    priority_queue<double> maxHeap;
    // minHeap ↗️ larger  half (smallest on top)
    priority_queue<double, vector<double>, greater<double>> minHeap;

    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        // 2️⃣ maintain ordering: maxHeap.top() ≤ minHeap.top()
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // 3️⃣ rebalance sizes so the heaps differ by ≤ 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())            // odd
            return maxHeap.top();
        if (maxHeap.size() < minHeap.size())            // odd
            return minHeap.top();

        return (maxHeap.top() + minHeap.top()) / 2.0;   // even
    }
};

int main() {
    MedianFinder *obj = new MedianFinder;
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;
    return 0;
}

/*
Problem: Find Median from Data Stream
*/