#include "template.hpp"

/* Approach (Math): */
class Solution {
  public:
    bool stoneGameIX(vector<int> &stones) {
        vi cnt(3, 0);
        iterate(stone, stones)
            cnt[stone % 3]++;

        if (cnt[0] % 2 == 0)
            return cnt[1] > 0 && cnt[2] > 0;

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {2, 1};
    auto res = obj.stoneGameIX(v);
    print(res);
    v = {2};
    res = obj.stoneGameIX(v);
    print(res);
    v = {5, 1, 2, 4, 3};
    res = obj.stoneGameIX(v);
    print(res);
    return 0;
}

/*
Problem: Stone Game IX
*/