#include "template.hpp"

/* Approach (Observation Greedy): */
class Solution {
  public:
    bool uniformArray(vector<int> &nums1) {
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 3};
    auto res = obj.uniformArray(v);
    print(res);
    v = {4, 6};
    res = obj.uniformArray(v);
    print(res);
    return 0;
}

/*
Problem: Construct Uniform Parity Array I
*/