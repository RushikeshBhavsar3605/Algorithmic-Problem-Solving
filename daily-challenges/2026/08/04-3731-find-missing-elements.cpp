#include "template.hpp"

/* Approach (Hashing): */
class Solution {
  public:
    vector<int> findMissingElements(vector<int> &nums) {
        int mn = *min_element(all(nums));
        int mx = *max_element(all(nums));

        uset<int> seen(all(nums));

        vi res;
        loop(i, mn + 1, mx) if (!seen.count(i)) res.pb(i);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 4, 2, 5};
    auto res = obj.findMissingElements(v);
    print(res);
    v = {7, 8, 6, 9};
    res = obj.findMissingElements(v);
    print(res);
    v = {5, 1};
    res = obj.findMissingElements(v);
    print(res);
    return 0;
}

/*
Problem: Find Missing Elements
*/