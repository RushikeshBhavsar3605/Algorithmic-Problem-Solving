#include "template.hpp"

class Solution {
  public:
    int maxArea(vector<int> &height) {
        int maxi = 0;
        int left = 0, right = sz(height) - 1;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            updateMax(maxi, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto res = obj.maxArea(v);
    print(res);
    return 0;
}

/*
Problem: Container With Most Water
*/