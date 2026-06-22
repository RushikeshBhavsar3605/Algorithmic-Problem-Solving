#include "template.hpp"

/* Approach 1 (Heap):
class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = sz(nums1);
        int m = sz(nums2);

        priority_queue<vi, vvi, greater<vi>> minHeap;
        minHeap.push({nums1[0] + nums2[0], 0, 0});

        vvi res;
        map<pii, int> mp;

        while (!minHeap.empty() && k--) {
            vi top = minHeap.top();
            minHeap.pop();

            int i = top[1];
            int j = top[2];
            res.pb({nums1[i], nums2[j]});

            if (j + 1 < m && !mp.count({i, j + 1})) {
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
                mp[{i, j + 1}] = 1;
            }

            if (i + 1 < n && !mp.count({i + 1, j})) {
                minHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
                mp[{i + 1, j}] = 1;
            }
        }

        return res;
    }
};
*/

/* Approach 2 (Optimal): */
class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = sz(nums1);
        int m = sz(nums2);

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        loop(i, 0, min(n, k)) minHeap.push({nums1[i] + nums2[0], i, 0});

        vvi res;

        while (!minHeap.empty() && k--) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();

            res.pb({nums1[i], nums2[j]});

            if (j + 1 < m)
                minHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 7, 11};
    vi v2 = {2, 4, 6};
    auto res = obj.kSmallestPairs(v1, v2, 3);
    print(res);
    v1 = {1, 1, 2};
    v2 = {1, 2, 3};
    res = obj.kSmallestPairs(v1, v2, 2);
    print(res);
    return 0;
}

/*
Problem: Find K Pairs with Smallest Sums
*/