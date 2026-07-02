#include "template.hpp"

/* Approach (Heap): */
class Solution {
  public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = sz(grid);
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        queue<pii> q;
        loop(r, 0, n)
            loop(c, 0, n)
                if (grid[r][c] == 1)
                    q.push({r, c});

        nvec_t<pii, 1> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto &[dr, dc] : dirs) {
                int nr = dr + r;
                int nc = dc + c;

                if (nr < 0 || nc < 0 || nr == n || nc == n || grid[nr][nc] != 0)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }

        using state = tuple<int, int, int>;
        priority_queue<state> maxHeap;
        maxHeap.push({grid[0][0], 0, 0});

        nvec_t<int, 2> vis(n, vi(n, 0));
        vis[0][0] = 1;
        int minDist = n + n - 1;

        while (!maxHeap.empty()) {
            auto [dist, r, c] = maxHeap.top();
            maxHeap.pop();
            updateMin(minDist, dist);

            if (r == n - 1 && c == n - 1)
                return minDist - 1;

            for (auto &[dr, dc] : dirs) {
                int nr = dr + r;
                int nc = dc + c;

                if (nr < 0 || nc < 0 || nr == n || nc == n || vis[nr][nc])
                    continue;

                maxHeap.push({grid[nr][nc], nr, nc});
                vis[nr][nc] = 1;
            }
        }

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    auto res = obj.maximumSafenessFactor(v);
    print(res);
    v = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    res = obj.maximumSafenessFactor(v);
    print(res);
    v = {{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    res = obj.maximumSafenessFactor(v);
    print(res);
    return 0;
}

/*
Problem: Find the Safest Path in a Grid
*/