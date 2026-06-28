#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int maxDistance(string moves) {
        int horizontal = 0;
        int vertical = 0;
        int cnt = 0;

        iterate(move, moves) {
            if (move == 'L')
                horizontal--;
            else if (move == 'R')
                horizontal++;
            else if (move == 'D')
                vertical--;
            else if (move == 'U')
                vertical++;
            else
                cnt++;
        }

        int dist = abs(horizontal) + abs(vertical);
        return dist + cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.maxDistance("L_D_");
    print(res);
    res = obj.maxDistance("U_R");
    print(res);
    res = obj.maxDistance("UL");
    print(res);
    return 0;
}

/*
Problem: Maximum Manhattan Distance After All Moves
*/