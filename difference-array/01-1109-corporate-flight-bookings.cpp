#include "template.hpp"

/* Approach (Difference Array): */
class Solution {
  public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vi res(n, 0);

        iterate(booking, bookings) {
            int left = booking[0] - 1;
            int right = booking[1];
            int seats = booking[2];

            res[left] += seats;
            if (right < n)
                res[right] -= seats;
        }

        loop(i, 1, n)
            res[i] += res[i - 1];

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    auto res = obj.corpFlightBookings(v, 5);
    print(res);
    v = {{1, 2, 10}, {2, 2, 15}};
    res = obj.corpFlightBookings(v, 2);
    print(res);
    return 0;
}

/*
Problem: Corporate Flight Bookings
*/