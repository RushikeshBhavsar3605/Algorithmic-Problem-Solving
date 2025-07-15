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

/* Approach 1 (Sorting):
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(all(nums));
        return nums[nums.size() - k];
    }
};
*/

/* Approach 2 (Heap):
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        // min-heap keeps the *k* largest elements seen so far
        priority_queue<int, vi, greater<int>> minHeap;

        iterate(num, nums) {        // add current element
            minHeap.push(num);
            if (minHeap.size() > k)
                minHeap.pop();      // remove smallest → size stays k
        }

        return minHeap.top();       // root = k-th largest
    }
};
*/

/* Approach 3 (Quick Select) (Only for interviews):
class Solution {
  private:
    int quickSelect(vi &nums, int left, int right, int k) {
        int pivot = nums[right];    // pick last element as pivot
        int p = left;               // pivot’s final index

        loop(i, left, right)        // partition: <=pivot to left
            if (nums[i] <= pivot) {
            swap(nums[p], nums[i]);
            p++;
        }
        swap(nums[p], nums[right]); // put pivot at its place

        if (p > k)
            return quickSelect(nums, left, p - 1, k);   // search left
        else if (p < k)
            return quickSelect(nums, p + 1, right, k);  // search right
        else
            return nums[p]; // found k-th smallest
    }

  public:
    int findKthLargest(vector<int> &nums, int k) {
        k = nums.size() - k; // convert to k-th smallest index
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
*/

/* Approach 4 (Quick Select Optimized):
class Solution {
  private:
    int quickSelect(vi &nums, int left, int right, int &k) {
        int pivot = nums[right]; // choose last element as pivot
        int smaller = left;      // end of "< pivot" region
        int greater = right;     // start of "> pivot" region
        int i = left;            // current scan index

        // --- 3-way (Dutch-National-Flag) partition ---
        while (i <= greater)
            if (nums[i] < pivot)        // move smaller to front
                swap(nums[smaller++], nums[i++]);
            else if (nums[i] > pivot)   // move larger to back
                swap(nums[greater--], nums[i]);
            else                        // nums[i] == pivot
                i++;

        if (smaller > k)        // k in "< pivot" zone
            return quickSelect(nums, left, smaller - 1, k);
        else if (greater < k)   // k in "> pivot" zone
            return quickSelect(nums, greater + 1, right, k);
        else                    // k in "== pivot" zone
            return pivot;       // found!
    }

  public:
    int findKthLargest(vector<int> &nums, int k) {
        k = nums.size() - k; // convert to k-th smallest index
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
};
*/

/* Approach 5 (Hashing + Counting): */
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int maxi = *max_element(all(nums)); // highest value
        int mini = *min_element(all(nums)); // lowest value
        vi count(maxi - mini + 1, 0);       // freq array

        iterate(num, nums) // fill frequency
            count[num - mini]++;

        // walk counts from high → low until k elements have been skipped
        revloop(i, count.size() - 1, 0) {
            k -= count[i];          // remove this bucket
            if (k <= 0)
                return i + mini;    // i+mini = k-th largest
        }

        return -1; // should never hit
    }
};

int main() {
    Solution obj;
    vi v = {3, 2, 1, 5, 6, 4};
    cout << obj.findKthLargest(v, 2) << endl;
    v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << obj.findKthLargest(v, 4) << endl;
    return 0;
}

/*
Problem: Kth Largest Element in an Array
*/