#include "template.hpp"

/* Approach 1 (Queue):
class Solution {
  public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        queue<int> q;
        loop(i, 0, sz(tickets))
            q.push(i);

        int time = 0;
        while (!q.empty()) {
            time++;
            int front = q.front();
            q.pop();

            tickets[front]--;

            if (tickets[k] == 0)
                return time;
            else if (tickets[front] != 0)
                q.push(front);
        }

        return time;
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
        int time = 0;
        loop(i, 0, sz(tickets)) {
            if (i <= k)
                time += min(tickets[k], tickets[i]);
            else
                time += min(tickets[k] - 1, tickets[i]);
        }

        return time;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 3, 2};
    auto res = obj.timeRequiredToBuy(v, 2);
    print(res);
    v = {5, 1, 1, 1};
    res = obj.timeRequiredToBuy(v, 0);
    print(res);
    return 0;
}

/*
Problem: Time Needed to Buy Tickets
*/