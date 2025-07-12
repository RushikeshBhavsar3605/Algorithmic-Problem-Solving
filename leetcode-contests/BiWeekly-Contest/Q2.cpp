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
  private:
    long long minX = LLONG_MAX, maxX = LLONG_MIN;
    long long minY = LLONG_MAX, maxY = LLONG_MIN;

    void compute(vi &it) {
        minX = min(minX, (long long)it[0]);
        maxX = max(maxX, (long long)it[0]);
        minY = min(minY, (long long)it[1]);
        maxY = max(maxY, (long long)it[1]);
    }

    long long solve(unordered_map<int, pair<int, int>> sameX, unordered_map<int, pair<int, int>> sameY) {
        long long b = 0;
        for (auto &i : sameX) {
            long long base = (long long)i.second.second - i.second.first;
            if (base == 0)
                continue;
            long long height = max((long long)i.first - minX, maxX - (long long)i.first);
            if (height)
                b = max(b, base * height);
        }

        for (auto &i : sameY) {
            long long base = (long long)i.second.second - i.second.first;
            if (base == 0)
                continue;
            long long height = max((long long)i.first - minY, maxY - (long long)i.first);
            if (height)
                b = max(b, base * height);
        }

        return b ? b : -1;
    }

  public:
    long long maxArea(vector<vector<int>> &coords) {
        unordered_map<int, pair<int, int>> sameX, sameY;

        iterate(it, coords) {
            if (!sameX.count(it[0]))
                sameX[it[0]] = {it[1], it[1]};
            else {
                sameX[it[0]].first = min(sameX[it[0]].first, it[1]);
                sameX[it[0]].second = min(sameX[it[0]].second, it[1]);
            }

            if (!sameY.count(it[1]))
                sameY[it[1]] = {it[0], it[0]};
            else {
                sameY[it[1]].first = min(sameY[it[1]].first, it[0]);
                sameY[it[1]].second = min(sameY[it[1]].second, it[0]);
            }

            compute(it);
        }
        return solve(sameX, sameY);
    }
};

int main() {
    Solution obj;
    vvi v = {{1, 5}, {2, 3}, {1, 7}, {2, 9}, {1, 2}};
    cout << obj.maxArea(v);
    return 0;
}

/*
Problem:
*/