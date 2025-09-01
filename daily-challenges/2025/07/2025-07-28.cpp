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

/* Approach 1 (Recursive):
class Solution {
  private:
    void compute(int index, vi &nums, int val, map<int, int> &mp) {
        if (index == nums.size()) {
            mp[val]++;
            return;
        }

        compute(index + 1, nums, val | nums[index], mp);
        compute(index + 1, nums, val, mp);
    }

  public:
    int countMaxOrSubsets(vector<int> &nums) {
        map<int, int> mp;
        compute(0, nums, 0, mp);

        if (mp.empty())
            return 0;
        return prev(mp.end())->second;
    }
};
*/

/* Approach 2 (Recursive) (Space Optimization):
class Solution {
  private:
    int countSubsets(int index, const vi &nums, int val, int &target) {
        if (index == nums.size())
            return (val == target) ? 1 : 0;

        int take = countSubsets(index + 1, nums, val | nums[index], target);
        int notTake = countSubsets(index + 1, nums, val, target);

        return take + notTake;
    }

  public:
    int countMaxOrSubsets(vector<int> &nums) {
        int maxi = 0;
        iterate(it, nums)
            maxi |= it;

        return countSubsets(0, nums, 0, maxi);
    }
};
*/

/* Approach 3 (Memoization): */
class Solution {
  private:
    int countSubsets(int index, vi &nums, int val, int target, vvi &memo) {
        if (index == nums.size())
            return (val == target) ? 1 : 0;

        if (memo[index][val] != -1)
            return memo[index][val];

        int take = countSubsets(index + 1, nums, val | nums[index], target, memo);
        int notTake = countSubsets(index + 1, nums, val, target, memo);

        return memo[index][val] = take + notTake;
    }

  public:
    int countMaxOrSubsets(vector<int> &nums) {
        int maxi = 0;
        iterate(it, nums)
            maxi |= it;

        vvi memo(nums.size(), vi(maxi + 1, -1));

        return countSubsets(0, nums, 0, maxi, memo);
    }
};

int main() {
    Solution obj;
    vi v = {3, 1};
    cout << obj.countMaxOrSubsets(v) << endl;
    v = {3, 2, 1, 5};
    cout << obj.countMaxOrSubsets(v) << endl;
    return 0;
}

/*
Problem: Count Number of Maximum Bitwise-OR Subsets
*/