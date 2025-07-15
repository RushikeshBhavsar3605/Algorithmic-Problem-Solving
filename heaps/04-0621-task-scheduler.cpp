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
  public:
    int leastInterval(vector<char> &tasks, int n) {
        // build frequency map: task → remaining count
        unordered_map<int, int> mp;
        iterate(it, tasks) mp[it]++;

        // max‑heap (always run the task with most instances left)
        priority_queue<int> pq;
        iterate(it, mp) pq.push(it.second);

        // cooling queue: {remainingCnt, tickWhenReady}
        queue<pair<int, int>> q;
        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;                     // advance one tick

            if (!pq.empty()) {          // schedule a task
                int cnt = pq.top() - 1; // one run
                pq.pop();
                if (cnt > 0)
                    q.push({cnt, time + n}); // still needs work → cool
            }

            // move tasks whose cooldown expired back to the heap
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

int main() {
    Solution obj;
    vector<char> v = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << obj.leastInterval(v, 2) << endl;
    v = {'A', 'C', 'A', 'B', 'D', 'B'};
    cout << obj.leastInterval(v, 1) << endl;
    v = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << obj.leastInterval(v, 3) << endl;
    return 0;
}

/*
Problem: Task Scheduler
*/