#include "template.hpp"

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int ele = -1, cnt = 0;

        iterate(num, nums) {
            if (cnt == 0)
                ele = num;

            cnt += (num == ele) ? 1 : -1;
        }

        return ele;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 2, 3};
    auto res = obj.majorityElement(v);
    print(res);
    v = {2, 2, 1, 1, 1, 2, 2};
    res = obj.majorityElement(v);
    print(res);
    return 0;
}

/*
Problem: Majority Element
*/