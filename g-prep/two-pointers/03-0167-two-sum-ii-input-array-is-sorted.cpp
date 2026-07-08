#include "template.hpp"

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = sz(numbers) - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 7, 11, 15};
    auto res = obj.twoSum(v, 9);
    print(res);
    v = {2, 3, 4};
    res = obj.twoSum(v, 6);
    print(res);
    v = {-1, 0};
    res = obj.twoSum(v, -1);
    print(res);
    return 0;
}

/*
Problem: Two Sum II - Input Array Is Sorted
*/