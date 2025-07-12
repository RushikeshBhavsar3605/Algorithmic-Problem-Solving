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

// Time Limit Exceeded
// class Solution {
//   private:
//     int solve(int index, vi &coins, int target) {
//         if (target == 0)
//             return 1;

//         if (index == coins.size() || target < 0)
//             return 0;

//         int take = solve(index, coins, target - coins[index]);
//         int skip = solve(index + 1, coins, target);

//         return take + skip;
//     }

//     int compute(vi &coins, int target) {
//         int result = solve(0, coins, target);
//         return result;
//     }

//     bool isPossible(vi &result, int amount) {
//         int sum = 0;
//         iterate(it, result) {
//             while (amount - it >= 0)
//                 amount -= it;
//             if (amount == 0)
//                 return true;
//         }
//         return false;
//     }

//   public:
//     vector<int> findCoins(vector<int> &numWays) {
//         vi result;
//         loop(i, 0, numWays.size()) {
//             int amount = i + 1;
//             int ways = compute(result, amount);

//             if (ways < numWays[i]) {
//                 if (numWays[i] - ways != 1)
//                     return {};

//                 result.push_back(amount);
//             }

//             if (numWays[i] == 0) {
//                 result.erase(remove(all(result), amount), result.end());
//                 if (isPossible(result, amount))
//                     return {};
//             }
//         }
//         return result;
//     }
// };
class Solution {
  private:
    void solve(vi &numWays, vi &result) {
        vi dp(numWays.size() + 1, 0);
        dp[0] = 1;
        loop(i, 1, numWays.size() + 1) {
            if (dp[i] > numWays[i - 1]) {
                result = {};
                return;
            }
            if (dp[i] < numWays[i - 1]) {
                if (dp[i] + 1 != numWays[i - 1]) {
                    result = {};
                    return;
                }
                result.push_back(i);
                loop(j, i, numWays.size() + 1) dp[j] += dp[j - i];
            }
        }
    }

  public:
    vector<int> findCoins(vector<int> &numWays) {
        if (numWays.size() == 0)
            return {};

        vi result;
        solve(numWays, result);

        return result;
    }
};

int main() {
    Solution obj;
    vi v = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
    vi result = obj.findCoins(v);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem:
*/