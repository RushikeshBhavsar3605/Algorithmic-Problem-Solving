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
class KthLargest {
  private:
    int getIndex(int val) {
        int left = 0, right = stream.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);

            if (stream[mid] < val)
                left = mid + 1;
            else if (stream[mid] > val)
                right = mid - 1;
            else
                return mid;
        }

        return left;
    }

  public:
    vi stream;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        iterate(num, nums)
            stream.push_back(num);
        sort(all(stream));
    }

    int add(int val) {
        int index = getIndex(val);
        stream.insert(begin(stream) + index, val);

        return stream[stream.size() - k];
    }
};
*/

/* Approach 2 (Heap): */
class KthLargest {
  public:
    priority_queue<int, vi, greater<int>> minHeap;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;

        iterate(num, nums) {
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k)
            minHeap.pop();

        return minHeap.top();
    }
};

int main() {
    vi v = {4, 5, 8, 2};
    KthLargest *obj = new KthLargest(3, v);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}

/*
Problem: Kth Largest Element in a Stream
*/