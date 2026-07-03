#include "template.hpp"

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(all(intervals));

        vvi res;
        iterate(interval, intervals) {
            if (res.empty() || res.back()[1] < interval[0])
                res.pb(interval);
            else
                res.back()[1] = max(res.back()[1], interval[1]);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = obj.merge(v);
    print(res);
    v = {{1, 4}, {4, 5}};
    res = obj.merge(v);
    print(res);
    v = {{4, 7}, {1, 4}};
    res = obj.merge(v);
    print(res);
    return 0;
}

/*
Problem: Merge Intervals
*/