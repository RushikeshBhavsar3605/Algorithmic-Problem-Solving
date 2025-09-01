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
    int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
        vi freeGaps(1, startTime[0]);
        loop(i, 1, startTime.size())
            freeGaps.push_back(startTime[i] - endTime[i - 1]);
        freeGaps.push_back(eventTime - endTime.back());

        vi largestRight(freeGaps.size(), 0);
        revloop(i, freeGaps.size() - 2, 0)
            largestRight[i] = max(largestRight[i + 1], freeGaps[i + 1]);

        vi largestLeft(freeGaps.size(), 0);
        loop(i, 2, freeGaps.size())
            largestLeft[i] = max(largestLeft[i - 1], freeGaps[i - 2]);

        int maxFreeDuration = 0;
        loop(i, 1, freeGaps.size()) {
            int meetingTime = endTime[i - 1] - startTime[i - 1];
            if (meetingTime <= max(largestLeft[i], largestRight[i]))
                maxFreeDuration = max(maxFreeDuration, freeGaps[i - 1] + freeGaps[i] + meetingTime);

            maxFreeDuration = max(maxFreeDuration, freeGaps[i - 1] + freeGaps[i]);
        }

        return maxFreeDuration;
    }
};

int main() {
    Solution obj;
    vi v1 = {1, 3};
    vi v2 = {2, 5};
    cout << obj.maxFreeTime(5, v1, v2) << endl;
    return 0;
}

/*
Problem:
*/