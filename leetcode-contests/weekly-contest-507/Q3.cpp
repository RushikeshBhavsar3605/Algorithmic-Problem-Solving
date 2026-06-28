#include "template.hpp"

/* Approach (Dijkstra): */
class Solution {
  public:
    int shortestPath(int n, vector<vector<int>> &edges, string labels, int k) {
        umap<int, nvec_t<pii, 1>> adj;
        iterate(edge, edges)
            adj[edge[0]].pb({edge[1], edge[2]});

        vvi dist(n, vi(k, INT_MAX));
        dist[0][0] = 0;

        using state = tuple<int, int, int>;
        priority_queue<state, nvec_t<state, 1>, greater<state>> minHeap;
        minHeap.push({0, 0, 0});

        while (!minHeap.empty()) {
            auto [cost, node, currK] = minHeap.top();
            minHeap.pop();

            if (cost != dist[node][currK])
                continue;

            for (auto &[edgeNode, edgeCost] : adj[node]) {
                int newK = currK;

                if (labels[node] == labels[edgeNode])
                    newK++;
                else
                    newK = 0;

                if (newK == k)
                    continue;

                if (dist[edgeNode][newK] > cost + edgeCost) {
                    dist[edgeNode][newK] = cost + edgeCost;
                    minHeap.push({dist[edgeNode][newK], edgeNode, newK});
                }
            }
        }

        int res = INT_MAX;
        loop(currK, 0, k)
            updateMin(res, dist[n - 1][currK]);

        return res != INT_MAX ? res : -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vvi v = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    auto res = obj.shortestPath(3, v, "aab", 1);
    print(res);
    res = obj.shortestPath(3, v, "aab", 2);
    print(res);
    v = {{0, 1, 1}, {1, 2, 1}};
    res = obj.shortestPath(3, v, "aaa", 2);
    print(res);
    v = {{1, 2, 1746}, {0, 1, 3}, {1, 2, 9}, {2, 3, 2}};
    res = obj.shortestPath(4, v, "abab", 1);
    print(res);
    return 0;
}

/*
Problem: Shortest Path With At Most K Consecutive Identical Characters
*/