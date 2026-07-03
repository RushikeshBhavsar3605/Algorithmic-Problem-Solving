#include "template.hpp"

class Solution {
  public:
    int trap(vector<int> &height) {
        int leftMax = 0, rightMax = 0;
        int left = 0, right = sz(height) - 1;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                updateMax(leftMax, height[left]);
                water += leftMax - height[left++];
            } else {
                updateMax(rightMax, height[right]);
                water += rightMax - height[right--];
            }
        }

        return water;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto res = obj.trap(v);
    print(res);
    v = {4, 2, 0, 3, 2, 5};
    res = obj.trap(v);
    print(res);
    return 0;
}

/*
Problem: Trapping Rain Water
*/