#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void merge(vector<int> &result, vector<pair<int, int>> &numsPair, int low, int mid, int high) {
        vector<pair<int, int>> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (numsPair[left].first <= numsPair[right].first)
                temp.push_back(numsPair[right++]);
            else {
                result[numsPair[left].second] += high - right + 1;
                temp.push_back(numsPair[left++]);
            }
        }

        while (left <= mid)
            temp.push_back(numsPair[left++]);

        while (right <= high)
            temp.push_back(numsPair[right++]);

        for (int i = low; i <= high; i++)
            numsPair[i] = temp[i - low];
    }

    void mergeSort(vector<int> &result, vector<pair<int, int>> &numsPair, int low, int high) {
        if (low >= high)
            return;

        int mid = low + ((high - low) >> 1);
        mergeSort(result, numsPair, low, mid);
        mergeSort(result, numsPair, mid + 1, high);
        merge(result, numsPair, low, mid, high);
    }

  public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<pair<int, int>> numsPair;
        for (int i = 0; i < n; i++)
            numsPair.emplace_back(nums[i], i);

        vector<int> result(n, 0);
        mergeSort(result, numsPair, 0, n - 1);
        return result;
    }
};
int main() {
    vector<int> nums = {5, 2, 6, 1};
    Solution s;
    vector<int> result = s.countSmaller(nums);
    for (int &it : result)
        cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Count of Smaller Numbers After Self
*/