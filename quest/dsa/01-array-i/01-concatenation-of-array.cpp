#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    vector<int> getConcatenation(vector<int> &nums) {
        vi res = nums;
        res.insert(end(res), all(nums));

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 1};
    auto res = obj.getConcatenation(v);
    print(res);
    v = {1, 3, 2, 1};
    res = obj.getConcatenation(v);
    print(res);
    return 0;
}

/*
Problem: Concatenation of Array
*/