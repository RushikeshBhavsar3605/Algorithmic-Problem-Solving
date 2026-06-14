#include "template.hpp"

/* Approach (Counting): */
class Solution {
  public:
    bool validMountainArray(vector<int> &arr) {
        int n = sz(arr);
        if (n < 3)
            return false;

        int incCnt = 0;
        int dscCnt = 0;

        loop(i, 1, n) {
            if (arr[i - 1] < arr[i] && dscCnt == 0)
                incCnt++;
            else if (arr[i - 1] > arr[i])
                dscCnt++;
            else
                return false;
        }

        return (incCnt != 0 && dscCnt != 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 1};
    auto res = obj.validMountainArray(v);
    print(res);
    v = {3, 5, 5};
    res = obj.validMountainArray(v);
    print(res);
    v = {0, 3, 2, 1};
    res = obj.validMountainArray(v);
    print(res);
    return 0;
}

/*
Problem: Valid Mountain Array
*/