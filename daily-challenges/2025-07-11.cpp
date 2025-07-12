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
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<long long> busy(n, 0);
        vi count(n, 0);

        sort(all(meetings));

        iterate(meeting, meetings) {
            int start = meeting[0], end = meeting[1];
            long long earliest = LLONG_MAX;
            int roomIndex = -1;
            bool assigned = false;

            loop(i, 0, n) {
                if (busy[i] < earliest) {
                    earliest = busy[i];
                    roomIndex = i;
                }
                if (busy[i] <= start) {
                    busy[i] = end;
                    count[i]++;
                    assigned = true;
                    break;
                }
            }

            if (!assigned) {
                busy[roomIndex] += (end - start);
                count[roomIndex]++;
            }
        }

        int result = 0, maxCount = 0;
        loop(i, 0, n)
            if (count[i] > maxCount) {
                maxCount = count[i];
                result = i;
            }

        return result;
    }
};

int main() {
    Solution obj;
    vvi v = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << obj.mostBooked(2, v);
    return 0;
}

/*
Problem:
*/