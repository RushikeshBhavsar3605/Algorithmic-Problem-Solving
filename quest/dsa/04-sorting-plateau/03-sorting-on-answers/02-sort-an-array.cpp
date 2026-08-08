#include "template.hpp"

/* Approach 1 (Merge Sort):
class Solution {
  private:
    void merge(int st, int mid, int en, vi &nums) {
        vi temp;
        int i = st, j = mid + 1;

        while (i <= mid && j <= en) {
            if (nums[i] < nums[j])
                temp.pb(nums[i++]);
            else
                temp.pb(nums[j++]);
        }

        while (i <= mid)
            temp.pb(nums[i++]);
        while (j <= en)
            temp.pb(nums[j++]);

        loop(k, 0, sz(temp)) nums[st + k] = temp[k];
    }

    void mergeSort(int st, int en, vi &nums) {
        if (st >= en)
            return;

        int mid = st + ((en - st) >> 1);

        mergeSort(st, mid, nums);
        mergeSort(mid + 1, en, nums);
        merge(st, mid, en, nums);
    }

  public:
    vector<int> sortArray(vector<int> &nums) {
        mergeSort(0, sz(nums) - 1, nums);
        return nums;
    }
};
*/

/* Approach 2 (Quick Select): */
class Solution {
  private:
    int partition(int left, int right, vi &nums) {
        int randomIdx = left + rand() % (right - left + 1);
        swap(nums[randomIdx], nums[right]);

        int pivot = nums[right];
        int store = left;

        loop(i, left, right)
            if (nums[i] < pivot)
                swap(nums[store++], nums[i]);

        swap(nums[store], nums[right]);
        return store;
    }

    void quickSort(int left, int right, vi &nums) {
        if (left >= right)
            return;

        int pivotIdx = partition(left, right, nums);

        quickSort(left, pivotIdx - 1, nums);
        quickSort(pivotIdx + 1, right, nums);
    }

  public:
    vector<int> sortArray(vector<int> &nums) {
        quickSort(0, sz(nums) - 1, nums);
        return nums;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {5, 2, 3, 1};
    auto res = obj.sortArray(v);
    print(res);
    v = {5, 1, 1, 2, 0, 0};
    res = obj.sortArray(v);
    print(res);
    return 0;
}

/*
Problem: Sort an Array
*/