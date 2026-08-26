#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    int missingMultiple(vector<int> &nums, int k) {
        uset<int> st(all(nums));
        int curr = k;

        while (st.count(curr))
            curr += k;

        return curr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {8, 2, 3, 4, 6};
    auto res = obj.missingMultiple(v, 2);
    print(res);
    v = {1, 4, 7, 10, 15};
    res = obj.missingMultiple(v, 5);
    print(res);
    return 0;
}

/*
Problem: Smallest Missing Multiple of K
*/