#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class Solution {
  private:
    int solve(vi &pos, vi &target) {
        int swaps = 0;
        loop(i, 0, pos.size()) swaps += abs(pos[i] - target[i]);
        return swaps;
    }
    void compute(int &result, vi &v) {
        vi target;
        loop(i, 0, v.size())
            target.push_back(i * 2);

        result = min(result, solve(v, target));
    }

  public:
    int minSwaps(vector<int> &nums) {
        vi eVector, oVector;
        int n = nums.size();
        loop(i, 0, n) if (nums[i] & 1) oVector.push_back(i);
        else eVector.push_back(i);

        int eCnt = eVector.size(), oCnt = oVector.size();
        if (abs(eCnt - oCnt) > 1)
            return -1;

        int result = INT_MAX;
        if (eCnt >= oCnt)
            compute(result, eVector);
        if (oCnt >= eCnt)
            compute(result, oVector);

        return result;
    }
};

int main() {
    Solution obj;
    vi nums = {2, 4, 6, 5, 7};
    cout << obj.minSwaps(nums);
    return 0;
}

/*
Problem:
*/