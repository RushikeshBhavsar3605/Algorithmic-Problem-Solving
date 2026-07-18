#include "template.hpp"

/* Approach (Sorting): */
class Solution {
  public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        sort(all(arr));

        int mini = INT_MAX;
        vvi res;

        loop(i, 1, sz(arr)) {
            int diff = arr[i] - arr[i - 1];

            if (diff > mini)
                continue;

            if (diff < mini) {
                res.clear();
                mini = diff;
            }

            res.pb({arr[i - 1], arr[i]});
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {4, 2, 1, 3};
    auto res = obj.minimumAbsDifference(v);
    print(res);
    return 0;
}

/*
Problem: Minimum Absolute Difference
*/