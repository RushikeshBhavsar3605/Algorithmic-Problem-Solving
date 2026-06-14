#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    vector<string> buildArray(vector<int> &target, int n) {
        nvec_t<string, 1> res;
        int idx = 0;

        loop(i, 1, n + 1) {
            if (i != target[idx]) {
                res.pb("Push");
                res.pb("Pop");
            } else {
                res.pb("Push");
                idx++;
            }

            if (idx == sz(target))
                break;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3};
    auto res = obj.buildArray(v, 3);
    print(res);
    v = {1, 2, 3};
    res = obj.buildArray(v, 3);
    print(res);
    v = {1, 2};
    res = obj.buildArray(v, 4);
    print(res);
    return 0;
}

/*
Problem: Build an Array With Stack Operations
*/