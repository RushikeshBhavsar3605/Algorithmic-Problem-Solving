#include "template.hpp"

class Solution {
  private:
    int merge(vi &arr, vi &temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        int inversions = 0;

        while (i <= mid && j <= right)
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                inversions += mid - i + 1;
            }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        loop(p, left, right + 1)
            arr[p] = temp[p];

        return inversions;
    }

    int mergeSort(vi &arr, vi &temp, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + ((right - left) >> 1);

        return mergeSort(arr, temp, left, mid) + mergeSort(arr, temp, mid + 1, right) +
               merge(arr, temp, left, mid, right);
    }

  public:
    int inversionCount(vector<int> &arr) {
        vi temp(sz(arr));
        return mergeSort(arr, temp, 0, sz(arr) - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 4, 1, 3, 5};
    auto res = obj.inversionCount(v);
    print(res);
    v = {2, 3, 4, 5, 6};
    res = obj.inversionCount(v);
    print(res);
    v = {10, 10, 10};
    res = obj.inversionCount(v);
    print(res);
    return 0;
}

/*
Problem: Count Inversions
*/