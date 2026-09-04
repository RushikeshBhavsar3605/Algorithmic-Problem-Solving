#include "template.hpp"

/* Approach (Observation + Greedy):

* All Combinations:
    even - even = even
    odd - odd = even
    odd - even = odd
    even - odd = odd

* For converting `even` -> `odd` we need:
    even - odd = odd

* For converting `odd` -> `even` we need:
    odd - odd = even

* Difference must be `>= 1`.
* If there is an **odd** number and we try to make everything **even**, that odd number may need `odd - odd = 0`, which
is invalid.
* So, if **any odd exists**, try to make everything **odd**.
* If there is **no odd**, everything is already even → `true`.
*/
class Solution {
  public:
    bool uniformArray(vector<int> &nums1) {
        int minOdd = INT_MAX;
        iterate(x, nums1)
            if (x & 1) updateMin(minOdd, x);

        iterate(x, nums1) {
            if (!(x & 1) && minOdd != INT_MAX && x <= minOdd)
                return false;
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 4, 7};
    auto res = obj.uniformArray(v);
    print(res);
    v = {2, 3};
    res = obj.uniformArray(v);
    print(res);
    v = {4, 6};
    res = obj.uniformArray(v);
    print(res);
    v = {11, 16};
    res = obj.uniformArray(v);
    print(res);
    return 0;
}

/*
Problem: Construct Uniform Parity Array II
*/