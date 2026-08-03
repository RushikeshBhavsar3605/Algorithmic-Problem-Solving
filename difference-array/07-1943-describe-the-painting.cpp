#include "template.hpp"

/* Approach (Difference Array + Line Sweep): */
class Solution {
  public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
        map<ll, ll> diff;

        iterate(s, segments) {
            diff[s[0]] += s[2];
            diff[s[1]] -= s[2];
        }

        vvl res;

        ll currColor = 0;
        ll prev = -1;

        for (auto &[pos, color] : diff) {
            if (prev != -1 && currColor > 0)
                res.pb({prev, pos, currColor});

            currColor += color;
            prev = pos;
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}};
    auto res = obj.splitPainting(v);
    print(res);
    v = {{1, 7, 9}, {6, 8, 15}, {8, 10, 7}};
    res = obj.splitPainting(v);
    print(res);
    v = {{1, 4, 5}, {1, 4, 7}, {4, 7, 1}, {4, 7, 11}};
    res = obj.splitPainting(v);
    print(res);
    return 0;
}

/*
Problem: Describe the Painting
*/