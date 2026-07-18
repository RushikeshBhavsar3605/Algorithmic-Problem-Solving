#include "template.hpp"

/* Approach (Sorting): */
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(all(intervals));
        vvi res;

        iterate(it, intervals) {
            if (res.empty() || res.back()[1] < it[0])
                res.pb(it);
            else
                updateMax(res.back()[1], it[1]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = obj.merge(v);
    print(res);
    return 0;
}

/*
Problem: Merge Intervals
*/