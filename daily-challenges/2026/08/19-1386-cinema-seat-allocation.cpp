#include "template.hpp"

/* Approach 1 (Simulation):
class Solution {
  public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        sort(all(reservedSeats));

        int res = 0, currRow = 1;
        vector<bool> reserved(8, false);

        auto countFamilies = [&]() {
            bool left = !reserved[0] && !reserved[1] &&
                        !reserved[2] && !reserved[3];

            bool middle = !reserved[2] && !reserved[3] &&
                          !reserved[4] && !reserved[5];

            bool right = !reserved[4] && !reserved[5] &&
                         !reserved[6] && !reserved[7];

            if (left && right) return 2;
            else if (left || middle || right) return 1;
            else return 0;
        };

        iterate(it, reservedSeats) {
            int row = it[0];
            int col = it[1];

            if (col == 1 || col == 10)
                continue;

            if (currRow != row) {
                res += countFamilies();
                res += 2 * (row - currRow - 1);

                currRow = row;
                fill(all(reserved), false);
            }

            reserved[col - 2] = 1;
        }

        res += countFamilies();
        res += 2 * (n - currRow);

        return res;
    }
};
*/

/* Approach 2 (Hashing + Bit Masking): */
class Solution {
  public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats) {
        unordered_map<int, int> mp;

        iterate(seat, reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            mp[row] |= (1 << col);
        }

        int res = (n - sz(mp)) * 2;

        for (auto &[row, mask] : mp) {
            bool left = !(mask & ((1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)));
            bool middle = !(mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)));
            bool right = !(mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)));

            if (left && right)
                res += 2;
            else if (left || middle || right)
                res += 1;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    auto res = obj.maxNumberOfFamilies(3, v);
    print(res);
    v = {{2, 1}, {1, 8}, {2, 6}};
    res = obj.maxNumberOfFamilies(2, v);
    print(res);
    v = {{4, 3}, {1, 4}, {4, 6}, {1, 7}};
    res = obj.maxNumberOfFamilies(4, v);
    print(res);
    v = {{2, 3}};
    res = obj.maxNumberOfFamilies(3, v);
    print(res);
    v = {{2, 10}, {3, 1}, {1, 2}, {2, 2}, {3, 5}, {4, 1}, {4, 9}, {2, 7}};
    res = obj.maxNumberOfFamilies(4, v);
    print(res);
    return 0;
}

/*
Problem: Cinema Seat Allocation
*/