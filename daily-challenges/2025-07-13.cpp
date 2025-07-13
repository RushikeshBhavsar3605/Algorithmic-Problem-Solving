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

/* Approach 1 (Naive):
class Solution {
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        int result = 0;
        loop(i, 0, players.size())
            loop(j, 0, trainers.size())
                if (trainers[j] >= players[i]) {
                    result++;
                    trainers[j] = -1;
                    break;
                }

        return result;
    }
};
*/

class Solution {
  public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        int result = 0;
        sort(all(players));
        sort(all(trainers));

        int idx1 = 0, idx2 = 0;
        while (idx1 < players.size() && idx2 < trainers.size()) {
            if (players[idx1] <= trainers[idx2]) {
                result++;
                idx1++;
            }
            idx2++;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vi v1 = {4, 7, 9};
    vi v2 = {8, 2, 5, 8};
    cout << obj.matchPlayersAndTrainers(v1, v2) << endl;
    v1 = {1, 1, 1};
    v2 = {10};
    cout << obj.matchPlayersAndTrainers(v1, v2) << endl;
    return 0;
}

/*
Problem: Maximum Matching of Players With Trainers
*/
/*
Example 1:

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.

Example 2:

Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
*/