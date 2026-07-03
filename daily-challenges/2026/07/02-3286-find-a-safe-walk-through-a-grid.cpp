#include "template.hpp"

/* Approach 1 (Heap):
TC: (h * n * m * log(h * n * m))
SC: (h * n * m)

class Solution {
  public:
    bool findSafeWalk(vector<vector<int>> &grid, int health) {
        int n = sz(grid);
        int m = sz(grid[0]);

        int newHealth = grid[0][0] == 1 ? health - 1 : health;

        nvec_t<pii, 1> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        nvec_t<int, 3> vis(newHealth + 1, vvi(n, vi(m, 0)));
        vis[newHealth][0][0] = 1;

        using state = tuple<int, int, int>;
        priority_queue<state> maxHeap;
        maxHeap.push({newHealth, 0, 0});

        while (!maxHeap.empty()) {
            auto [h, r, c] = maxHeap.top();
            maxHeap.pop();

            if (h < 1)
                return false;

            if (r == n - 1 && c == m - 1)
                return true;

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr == n || nc == m)
                    continue;

                int nh = grid[nr][nc] == 1 ? h - 1 : h;
                if (vis[nh][nr][nc])
                    continue;

                maxHeap.push({nh, nr, nc});
                vis[nh][nr][nc] = 1;
            }
        }

        return false;
    }
};
*/

/* Approach 2 (Queue):
TC: O((n * m) ^ 2)
SC: O(n * m)

class Solution {
  public:
    bool findSafeWalk(vector<vector<int>> &grid, int health) {
        int n = sz(grid);
        int m = sz(grid[0]);

        nvec_t<pii, 1> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        using state = tuple<int, int, int>;
        queue<state> q;
        q.push({grid[0][0], 0, 0});

        vvi dist(n, vi(m, INT_MAX));
        dist[0][0] = grid[0][0];

        while (!q.empty()) {
            auto [w, r, c] = q.front();
            q.pop();

            if (dist[r][c] != w)
                continue;

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr == n || nc == m)
                    continue;

                if (dist[nr][nc] > w + grid[nr][nc]) {
                    dist[nr][nc] = w + grid[nr][nc];
                    q.push({dist[nr][nc], nr, nc});
                }
            }
        }

        return dist[n - 1][m - 1] < health;
    }
};
*/

/* Approach 3 (0-1 BFS):
TC: O(n * m)
SC: O(n * m)
*/
class Solution {
  public:
    bool findSafeWalk(vector<vector<int>> &grid, int health) {
        int n = sz(grid);
        int m = sz(grid[0]);

        nvec_t<pii, 1> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vvi dist(n, vi(m, INT_MAX));
        dist[0][0] = grid[0][0];

        deque<pii> dq;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            for (auto &[dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr == n || nc == m)
                    continue;

                int w = grid[nr][nc];
                if (dist[nr][nc] > dist[r][c] + w) {
                    dist[nr][nc] = dist[r][c] + w;
                    if (w == 0)
                        dq.push_front({nr, nc});
                    else
                        dq.push_back({nr, nc});
                }
            }
        }

        return dist[n - 1][m - 1] < health;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    auto res = obj.findSafeWalk(v, 1);
    print(res);
    v = {{0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}};
    res = obj.findSafeWalk(v, 3);
    print(res);
    v = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    res = obj.findSafeWalk(v, 5);
    print(res);
    return 0;
}

/*
Problem: Find a Safe Walk Through a Grid
*/